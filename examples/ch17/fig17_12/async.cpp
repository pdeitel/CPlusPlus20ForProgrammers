// Fig. 17.12: async.cpp
// Prime-factorization tasks performed in separate threads
#include <cmath>
#include <fmt/format.h>
#include <future> // std::async
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

// get current thread's ID as a string
std::string id() {
   std::ostringstream out;
   out << std::this_thread::get_id();
   return out.str();
}

// type alias for vector of factor/count pairs
using Factors = std::vector<std::pair<long long, int>>;

// type alias for a tuple containing a task name,   
// a number, whether the number is prime and its factors 
using FactorResults = std::tuple<std::string, long long, bool, Factors>;

// performs prime factorization   
FactorResults getFactors(std::string name, long long number) {
   std::cout << fmt::format(
      "{}: Thread {} executing getFactors for {}\n", name, id(), number);

   long long originalNumber{number}; // copy to place in FactorResults
   Factors factors; // vector of factor/count pairs

   // lambda that divides number by a factor and stores factor/count
   auto factorCount{
      [&](int factor) {
         int count{0}; // how many times number is divisible by factor

         // count how many times number is divisible by factor
         while (number % factor == 0) {
            ++count;
            number /= factor;
         }

         // store pair containing the factor and its count
         if (count > 0) {
            factors.push_back({factor, count});
         }
      }
   };

   factorCount(2); // count how many times number is divisible by 2

   // number is now odd; store each factor and its count 
   for (int i{3}; i <= std::sqrt(number); i += 2) {
      factorCount(i); // count how many times number is divisible by i
   }

   // add last prime factor
   if (number > 2) {
      factors.push_back({number, 1});
   }

   bool isPrime{factors.size() == 1 && get<int>(factors[0]) == 1};

   // initialize the FactorResults object returned by getFactors
   return {name, originalNumber, isPrime, factors};
}

// multiply the factors and confirm they reproduce number
void proveFactors(long long number, const Factors& factors) {
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
void displayResults(const FactorResults& results) {
   // unpack results into name (std::string), number (long long), 
   // isPrime (bool) and factors (Factors) 
   const auto& [name, number, isPrime, factors] {results};

   std::cout << fmt::format("\n{} results:\n", name);

   // display whether value is prime
   if (isPrime) {
      std::cout << fmt::format("{} is prime\n", number);
   }
   else { // display prime factors
      std::cout << fmt::format("{}'s prime factors:\n\n", number);
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

int main() {
   std::cout << "MAIN LAUNCHING TASKS\n";
   auto future1{std::async(std::launch::async,
      getFactors, "Task 1", 1016669006116682993)}; // not prime
   auto future2{std::async(std::launch::async,
      getFactors, "Task 2", 1000000000000000003)}; // prime

   std::cout << "\nWAITING FOR TASK RESULTS\n";

   // wait for results from each task, then display the results    
   displayResults(future1.get());
   displayResults(future2.get());

   std::cout << "\nMAIN ENDS\n";
}


 

/************************************************************************
 * (C) Copyright 1992-2022 by Deitel & Associates, Inc. and             *
 * Pearson Education, Inc. All Rights Reserved.                         *
 *                                                                      *
 * DISCLAIMER: The authors and publisher of this book have used their   *
 * best efforts in preparing the book. These efforts include the        *
 * development, research, and testing of the theories and programs      *
 * to determine their effectiveness. The authors and publisher make     *
 * no warranty of any kind, expressed or implied, with regard to these  *
 * programs or to the documentation contained in these books. The       *
 * authors and publisher shall not be liable in any event for           *
 * incidental or consequential damages in connection with, or arising   *
 * out of, the furnishing, performance, or use of these programs.       *
 ***********************************************************************/

