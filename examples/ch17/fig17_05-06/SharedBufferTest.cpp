// Fig. 17.6: SharedBufferTest.cpp
// Application with concurrent jthreads sharing an unsynchronized buffer.
#include <chrono>
#include <fmt/format.h>
#include <iostream>
#include <random>
#include <thread>
#include "UnsynchronizedBuffer.h"

int main() {
   // create UnsynchronizedBuffer to store ints       
   UnsynchronizedBuffer buffer;

   // lambda expression that produces the values 1-10 and sums them 
   auto produce{
      [&buffer]() {
         // set up random-number generation 
         std::random_device rd;
         std::default_random_engine engine{rd()};
         std::uniform_int_distribution ints{0, 3000};

         int sum{0};

         for (int count{1}; count <= 10; ++count) {
            // get random sleep time then sleep
            std::chrono::milliseconds sleepTime{ints(engine)};
            std::this_thread::sleep_for(sleepTime);

            buffer.put(count); // set value in buffer
            sum += count; // add count to sum of values produced
            std::cout << fmt::format("\t{:2d}\n", sum);
         }
   
         std::cout << "Producer done producing\nTerminating Producer\n";      
      }
   };

   // lambda expression that consumes the values 1-10 and sums them
   auto consume{
      [&buffer]() {
         // set up random-number generation 
         std::random_device rd;
         std::default_random_engine engine{rd()};
         std::uniform_int_distribution ints{0, 3000};

         int sum{0};

         for (int count{1}; count <= 10; ++count) {
            // get random sleep time then sleep
            std::chrono::milliseconds sleepTime{ints(engine)};
            std::this_thread::sleep_for(sleepTime);

            sum += buffer.get(); // get buffer value and add to sum
            std::cout << fmt::format("\t\t\t{:2d}\n", sum);
        }

         std::cout << fmt::format("\n{} {}\n{}\n",
            "Consumer read values totaling", sum, "Terminating Consumer");
      }
   };

   std::cout << "Action\t\tValue\tSum of Produced\tSum of Consumed\n";
   std::cout << "------\t\t-----\t---------------\t---------------\n";

   std::jthread producer{produce}; // start producer jthread
   std::jthread consumer{consume}; // start consumer jthread 
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

