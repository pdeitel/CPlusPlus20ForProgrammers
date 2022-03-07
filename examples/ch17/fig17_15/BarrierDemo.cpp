// Fig. 17.15: BarrierDemo.cpp
// Coordinating threads with a std::barrier object.
#include <barrier>
#include <chrono>
#include <fmt/format.h>
#include <iostream>
#include <random>
#include <string_view>
#include <thread>

int main() {
   // simulate moving car into painting position
   auto moveCarIntoPosition{
      []() {
         std::cout << "Moving next car into painting position.\n";
         std::this_thread::sleep_for(std::chrono::seconds(1)); 
         std::cout << "Car ready for painting.\n\n";
      }
   };

   int carsToPaint{3}; 

   // stop_source used to notify robots assembly line is shutting down
   std::stop_source assemblyLineStopSource;

   // stop_token used by paintingRobotTask to determine when to shut down
   std::stop_token stopToken{assemblyLineStopSource.get_token()};

   // assembly line waits for two painting robots to reach this barrier 
   std::barrier paintingDone{2, 
      [&]() noexcept { // lambda called when robots finish
         static int count{0}; // # of cars that have been painted
         std::cout << "Painting robots completed tasks\n\n";
         
         // check whether it's time to shut down the assembly line
         if (++count == carsToPaint) {
            std::cout << "Shutting down assembly line\n\n";
            assemblyLineStopSource.request_stop(); 
         }
         else { 
            moveCarIntoPosition();
         }
      }
   };

   // lambda that simulates painting work
   auto paintingRobotTask{
      [&](std::string_view name) {
         // set up random-number generation 
         std::random_device rd;
         std::default_random_engine engine{rd()};
         std::uniform_int_distribution ints{2500, 5000};

         // check whether the assembly line is shutting down
         // and, if not, do the painting work
         while (!stopToken.stop_requested()) {
            auto workTime{std::chrono::milliseconds{ints(engine)}};

            std::cout << fmt::format("{} painting for {} ms\n",
               name, workTime.count());
            std::this_thread::sleep_for(workTime); // simulate work

            // show that task woke up and arrived at continuationBarrier
            std::cout << fmt::format(
               "{} done painting. Waiting for next car.\n", name);

            // decrement paintingDone barrier's counter and
            // wait for other painting robots to arrive here
            paintingDone.arrive_and_wait(); 
         }

         std::cout << fmt::format("{} shut down.\n", name);
      }
   };

   moveCarIntoPosition(); // move the first car into position

   // start up two painting robots
   std::cout << "Starting robots.\n\n";
   std::jthread leftSideRobot{paintingRobotTask, "Left side robot"};
   std::jthread rightSideRobot{paintingRobotTask, "Right side robot"};
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

