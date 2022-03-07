// Fig. 17.14: LatchDemo.cpp
// Coordinate threads with a std::latch object.
#include <chrono>
#include <fmt/format.h>
#include <iostream>
#include <latch>
#include <random>
#include <string_view>
#include <thread>
#include <vector>

int main() {
   // set up random-number generation 
   std::random_device rd;
   std::default_random_engine engine{rd()};
   std::uniform_int_distribution ints{2000, 3000};

   // latch that 3 threads must signal before the main thread continues
   std::latch mainLatch{3};

   // lambda representing the task to execute
   auto task{
      [&](std::string_view name, std::chrono::milliseconds workTime) {
         std::cout << fmt::format("Proceeding with {} work for {} ms.\n",
            name, workTime.count());

         // simulate work by sleeping 
         std::this_thread::sleep_for(workTime);

         // show that task arrived at mainLatch
         std::cout << fmt::format("{} done; signals mainLatch.\n", name);
         mainLatch.count_down();
      }
   };

   std::vector<std::jthread> threads; // stores the threads
   std::cout << "Main starting three jthreads.\n";

   // start three jthreads
   for (int i{1}; i < 4; ++i) {
      // create jthread that calls task lambda, 
      // passing a task name and work time
      threads.push_back(std::jthread{task,
         fmt::format("Task {}", i),
         std::chrono::milliseconds{ints(engine)}});
   }

   std::cout << "\nMain waiting for jthreads to reach the latch.\n\n";
   mainLatch.wait();

   std::cout << "\nAll jthreads reached the latch. Main working.\n";
   std::cout << "Showing that mainLatch is permanently open.\n";
   mainLatch.wait(); // latch is already open 
   std::cout << "mainLatch is already open. Main continues.\n";
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

