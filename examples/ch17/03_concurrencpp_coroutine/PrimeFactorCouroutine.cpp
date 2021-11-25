// PrimeFactorCoroutine.cpp
// co_awaiting tasks, then co_returning the results.
#include <chrono>
#include <concurrencpp/concurrencpp.h>
#include <fmt/format.h>
#include <iostream>
#include <memory> // for shared_ptr
#include <sstream>
#include <thread>
#include <tuple>
#include <utility>
#include <vector>

// <chrono> library features used for timing
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

// get current thread's ID as a string
std::string id() {
   std::ostringstream out{};
   out << std::this_thread::get_id();
   return out.str();
}

// type alias for vector of factor/count pairs
using Factors = std::vector<std::pair<long long, int>>;

// type alias for a tuple containing a task name, a number, whether 
// the number prime, its factors and how long getFactors took to run
using FactorResults = 
   std::tuple<std::string, long long, bool, Factors, milliseconds>;

// prime factorization coroutine    
FactorResults getFactors(std::string name, long long number) {
   std::cout << fmt::format(
      "{}: Thread {} executing getFactors\n", name, id());

   long long originalNumber{number}; // copy to place in FactorResults
   auto startTime{steady_clock::now()}; // time before factorization
   Factors factors{}; // vector of factor/count pairs

   // lambda that divides number by a factor and stores factor/count
   auto factorCount{
      [&](int factor) {
         int count{0}; // how many times number is divisible by factor

         // count how many times number is divisible by factor
         while (number % factor == 0) {
            ++count;
            number /= factor;
         }

         // store tuple containing the factor and its count
         if (count > 0) {
            factors.push_back({factor, count});
         }
      }
   };

   factorCount(2); // count how many times number is divisible by 2

   // number is now odd; store each factor and its count 
   for (int i{3}; i <= sqrt(number); i += 2) {
      factorCount(i); // count how many times number is divisible by i
   }

   // add last prime factor
   if (number > 2) {
      factors.push_back({number, 1});
   }

   bool isPrime{factors.size() == 1 && get<int>(factors[0]) == 1};
   auto endTime{steady_clock::now()}; // time after calculation
   auto duration{duration_cast<milliseconds>(endTime - startTime)};

   // initialize the FactorResults object returned by getFactors
   return {name, originalNumber, isPrime, factors, duration};
}

// coroutine uses parallel tasks to determine whether a number is prime
concurrencpp::result<std::vector<FactorResults>> isPrime(
   std::shared_ptr<concurrencpp::thread_pool_executor> executor,
   long long value, int tasks) {

   // stores task result objects so we can await task completion later;
   std::vector<concurrencpp::result<FactorResults>> results{};

   // schedule each task
   for (int i{1}; i <= tasks; ++i) {
      std::string taskName{fmt::format("Task{}", i)};
      std::cout << fmt::format(
         "isPrime: Thread {} launching {} to call getFactors for {}\n",
         id(), taskName, value);
      results.emplace_back(executor->submit(getFactors, taskName, value));
   }

   // store each task's FactorResults in a vector to return to main
   std::vector<FactorResults> factorResults{};

   // co_await any task's result until all are available
   while (!results.empty()) {
      std::cout << fmt::format(
         "\nisPrime: Thread {} co_awaiting any task's result.\n", id());

      // await any result
      auto any{co_await concurrencpp::when_any(
         results.begin(), results.end())};

      // the task that finished is at any.index; 
      // move that result into finishedTask
      auto finishedTask{std::move(any.results[any.index])};

      // get the task's returned FactorResults object
      auto taskResult{co_await finishedTask}; 

      // get and display the task's name
      auto name{get<std::string>(taskResult)};
      std::cout << fmt::format(
         "isPrime: Thread {} {} done.\n", id(), name);

      // move taskResult into factorResults vector
      factorResults.push_back(std::move(taskResult));

      // when_any moves its argument range into any.results; move it back
      // into results then remove the completed task's result object 
      results = std::move(any.results);
      results.erase(results.begin() + any.index);
   }

   std::cout << "\nisPrime: Couroutine ending. "
      << fmt::format("Thread {} co_returning to main\n", id());

   co_return factorResults; // terminates coroutine
}

// multiply the factors and confirm they reproduce number
void proveFactors(long long number, Factors factors) {
   long long proof{1}; 

   // for each factor/count pair, unpack it then multiply proof 
   // by factor the number of times specified by count
   for (const auto& [factor, count] : factors) { 
      for (int i{0}; i < count; ++i) {
         proof *= factor;
      }
   }

   // confirm proof and number are equal
   if (proof == number) {
      std::cout << fmt::format(
         "\nProduct of factors matches original value ({})\n", proof);
   }
   else { 
      std::cout << fmt::format("\n{} != {}\n", proof, number);
   }
}

// show a task's FactorResults 
void displayResults(std::vector<FactorResults> results) {
   for (auto& result : results) {
      // unpack result into name (std::string), number (long long), 
      // isPrime (bool), factors (vector) and time (milliseconds)
      const auto& [name, number, isPrime, factors, time] {result};

      std::cout << fmt::format("\n{} results:\n", name);
      std::cout << fmt::format("Duration (ms): {}\n", time.count());

      // display whether value is prime
      if (isPrime) {
         std::cout << fmt::format("{} is prime\n", number);
      }
      else { // display prime factors
         std::cout << fmt::format("\n{}'s prime factors:\n\n", number);
         std::cout << fmt::format("{:<12}{:<8}\n", "Factor", "Count");

         for (const auto& [factor, count] : factors) {
            std::cout << fmt::format("{:<12}{:<8}\n", factor, count);
         }
      }
      
      // if not prime, prove that factors produce the original number 
      if (!isPrime) {
         proveFactors(number, factors); 
      }
   }
}

int main() {
   concurrencpp::runtime runtime{}; // set up concurrencpp runtime
   auto executor{runtime.thread_pool_executor()}; // get the executor
   int numberOfTasks{2}; // number of factorization tasks to launch

   // get value to check
   long long value{};
   std::cout << "Enter an integer to determine if it's prime: ";
   std::cin >> value;
   
   std::cout << fmt::format(
      "Main thread {} calling coroutine isPrime\n\n", id());

   // call isPrime couroutine to launch parallel tasks  
   // that check whether value is prime
   auto result{isPrime(executor, value, numberOfTasks)};

   std::cout << fmt::format(
      "\nMain thread {} waiting for results.\n\n", id());

   auto finalResults{result.get()}; // wait until results are available
   std::cout << fmt::format(
      "Main thread {} received results from coroutine isPrime\n", id());

   displayResults(finalResults);

   std::cout << fmt::format("\nMain thread {} ends\n", id());
}

/* Some values to test with:
1000000000000000003 // prime
1016669006116682993 // not prime. Factors are 1000000007 and 1016668999
*/

/**************************************************************************
 * (C) Copyright 1992-2021 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
