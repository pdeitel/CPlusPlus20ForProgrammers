// fig18_03.cpp
// Implementing a coroutine with co_await and co_return.
#include <concurrencpp/concurrencpp.h>
#include <fmt/format.h>
#include <iostream>
#include <memory> // for shared_ptr
#include <random>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

// get current thread's ID as a string
std::string id() {
   std::ostringstream out;
   out << std::this_thread::get_id();
   return out.str();
}

// coroutine that sorts a vector<int> using two tasks 
concurrencpp::result<void> sortCoroutine(
   std::shared_ptr<concurrencpp::thread_pool_executor> executor,
   std::vector<int>& values) {

   std::cout << fmt::format("Thread {}: sortCoroutine started\n\n", id());

   // lambda that sorts a portion of a vector
   auto sortTask{
      [&](auto begin, auto end) {
         std::cout << fmt::format(
            "Thread {}: Sorting {} elements\n", id(), end - begin);
         std::sort(begin, end); 
         std::cout << fmt::format("Thread {}: Finished sorting\n", id());
      }
   };

   // stores task results
   std::vector<concurrencpp::result<void>> results;

   size_t middle{values.size() / 2}; // middle element index

   std::cout << fmt::format(
      "Thread {}: sortCoroutine starting first half sortTask\n", id());

   // use a concurrencpp thread_pool_executor to schedule 
   // a sortTask call that sorts the first half of values
   results.push_back(
      executor->submit(
         [&]() {sortTask(values.begin(), values.begin() + middle);}
      )
   );

   std::cout << fmt::format(
      "Thread {}: sortCoroutine starting second half sortTask\n", id());

   // use a concurrencpp thread_pool_executor to schedule 
   // a sortTask call that sorts the second half of values
   results.push_back(
      executor->submit(
         [&]() {sortTask(values.begin() + middle, values.end());}
      )
   );

   // suspend coroutine while waiting for all sortTasks to complete 
   std::cout << fmt::format("\nThread {}: {}\n", id(),
      "sortCoroutine co_awaiting sortTask completion");
   co_await concurrencpp::when_all(
      executor, results.begin(), results.end());

   // merge the two sorted sub-vectors
   std::cout << fmt::format(
      "\nThread {}: sortCoroutine merging results\n", id());
   std::inplace_merge(
      values.begin(), values.begin() + middle, values.end());

   std::cout << fmt::format("Thread {}: sortCoroutine done\n", id());
   co_return; // terminate coroutine and resume caller
}

int main() {
   concurrencpp::runtime runtime; // set up concurrencpp runtime
   auto executor{runtime.thread_pool_executor()}; // get the executor

   // set up random number generation 
   std::random_device rd;
   std::default_random_engine engine{rd()};
   std::uniform_int_distribution ints;

   std::cout << fmt::format(
      "Thread {}: main creating vector of random ints\n", id());
   std::vector<int> values(100'000'000);
   std::ranges::generate(values, [&]() {return ints(engine);});

   std::cout << fmt::format(
      "Thread {}: main starting sortCoroutine\n", id());
   auto result{sortCoroutine(executor, values)};

   std::cout << fmt::format("\nThread {}: {}\n", id(),
     "main resumed. Waiting for sortCoroutine to complete.");
   result.get(); // wait for sortCoroutine to complete

   std::cout << fmt::format(
      "\nThread {}: main confirming that vector is sorted\n", id());
   bool sorted{std::ranges::is_sorted(values)};
   std::cout << fmt::format("Thread {}: values is{} sorted\n", 
      id(), sorted ? "" : " not");
}




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
