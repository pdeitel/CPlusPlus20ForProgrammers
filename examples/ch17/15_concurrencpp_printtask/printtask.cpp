// Fig. 17.20: printtask.cpp
// Setting up the concurrencpp::runtime and scheduling tasks with it.
#include <chrono>
#include <concurrencpp/concurrencpp.h>
#include <fmt/format.h>
#include <iostream>
#include <random>
#include <sstream>
#include <thread>
#include <vector>

// get current thread's ID as a string
std::string id() {
    std::ostringstream out;
    out << std::this_thread::get_id();
    return out.str();
}

// Function printTask sleeps for a specified period in milliseconds. 
// When it continues executing, it prints its name and completes.
void printTask(std::string name, std::chrono::milliseconds sleep) {
   std::cout << fmt::format(
      "{} (thread ID: {}) going to sleep for {} ms\n",
      name, id(), sleep.count());

   // put the calling thread to sleep for sleep milliseconds 
   std::this_thread::sleep_for(sleep);

   std::cout << fmt::format("{} (thread ID: {}) done sleeping\n",
      name, id());
}

int main() {
   // set up the concurrencpp runtime for scheduling tasks to execute
   concurrencpp::runtime runtime;

   std::cout << fmt::format("main's thread ID: {}\n\n", id());

   // set up random number generation for random sleep times
   std::random_device rd;
   std::mt19937_64 random{rd()}; 
   std::uniform_int_distribution ints{0, 5000};

   // stores the tasks so we can wait for them to complete later;
   // concurrencpp::result<void> indicates that each task returns void
   std::vector<concurrencpp::result<void>> results; 

   std::cout << "STARTING THREE CONCURRENCPP TASKS\n";

   // schedule three tasks
   for (int i{1}; i < 4; ++i) {
      std::chrono::milliseconds sleepTime{ints(random)};
      std::string name{fmt::format("Task {}", i)};

      // use a concurrencpp thread_pool_executor to schedule a call
      // to printTask with name and sleepTime as its arguments
      results.emplace_back(runtime.thread_pool_executor()->submit(
         printTask, name, sleepTime));
   }

   std::cout << "\nALL TASKS STARTED\n";
   std::cout << "\nWAITING FOR TASKS TO COMPLETE\n";
  
   // wait for each task to complete
   for (auto& result : results) {
      result.get(); // wait for each task to return its result
   } 

   std::cout << fmt::format("main's thread ID: {}\nMAIN ENDS\n", id());
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
