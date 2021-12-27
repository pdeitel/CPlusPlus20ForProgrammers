// Fig. 17.11: CooperativeCancelation.cpp
// Using a std::jthread's built-in stop_source 
// to request that the std::jthread stop executing.
#include <chrono>
#include <fmt/format.h>
#include <iostream>
#include <mutex>
#include <random>
#include <string>
#include <thread>
#include <vector>

// get current thread's ID as a string
std::string id() {
    std::ostringstream out;
    out << std::this_thread::get_id();
    return out.str();
}

int main() {
   // set up random number generation and a mutex to protect it
   std::random_device rd;
   std::mt19937_64 random{rd()};
   std::uniform_int_distribution ints{500, 1000};
   std::mutex randomMutex;

   // each printTask iterates until a stop is requested by another thread
   auto printTask{
      [&](std::stop_token token, std::string name) {
         // register a function to call when a stop is requested 
         std::stop_callback callback(token, [&]() {
            std::cout << fmt::format(
               "{} (id: {}) was told to stop\n", name, id());
         });

         while (!token.stop_requested()) { // run until stop requested
            std::chrono::milliseconds sleepTime;

            // synchronize access to the random-number generator
            {
               std::lock_guard lock{randomMutex};
               sleepTime = std::chrono::milliseconds{ints(random)};
            }

            std::cout << fmt::format(
               "{} (id: {}) going to sleep for {} ms\n",
               name, id(), sleepTime.count());

            // put thread to sleep for sleepTime milliseconds 
            std::this_thread::sleep_for(sleepTime);

            // show that task woke up 
            std::cout << fmt::format("{} working.\n", name);
         }

         std::cout << fmt::format("{} terminating.\n", name);
      }
   };

   std::cout << "MAIN STARTING TWO TASKS\n";

   // create two jthreads that each call printTask with a string argument
   std::jthread task1{printTask, "Task 1"};
   std::jthread task2{printTask, "Task 2"};

   // put main thread to sleep for 2 seconds 
   std::cout << "\nMAIN GOING TO SLEEP FOR 2 SECONDS\n\n";
   std::this_thread::sleep_for(std::chrono::seconds{2});

   std::cout << "\nMAIN ENDS\n\n";
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

