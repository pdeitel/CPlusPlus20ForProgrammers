// Fig. 17.8: SharedBufferTest.cpp
// Concurrent threads correctly manipulating a synchronized buffer.
#include <chrono>
#include <fmt/format.h>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include "SynchronizedBuffer.h"

int main() {
   // set up random number generation and the mutext to protect it
   std::random_device rd;
   std::mt19937_64 random{rd()};
   std::uniform_int_distribution ints{0, 3000};
   std::mutex intsMutex;

   // lambda for synchronized random sleep time generation
   auto getSleepTime{
      [&]() {
         std::lock_guard lock{intsMutex};
         return std::chrono::milliseconds{ints(random)};
      }
   };
 
   // create SynchronizedBuffer to store ints       
   SynchronizedBuffer buffer;

   // lambda expression that produces the values 1-10 and sums them 
   auto produce{
      [&]() {
         int sum{0};

         for (int count{1}; count <= 10; ++count) {
            // get random sleep time and sleep 
            std::this_thread::sleep_for(getSleepTime());

            buffer.put(count); // set value in m_buffer
            sum += count; // add count to sum of values produced
         }
   
         std::cout << "Producer done producing\nTerminating Producer\n";
      }
   };

   // lambda expression that consumes the values 1-10 and sums them
   auto consume{
      [&]() {
         int sum{0};

         for (int count{1}; count <= 10; ++count) {
            // get random sleep time and sleep 
            std::this_thread::sleep_for(getSleepTime());

            sum += buffer.get(); // get m_buffer value and add to sum
         }

         std::cout << fmt::format("\n{} {}\n{}\n",
            "Consumer read values totaling", sum, "Terminating Consumer");
      }
   };

   std::cout << fmt::format("{:<40}{}\t\t{}\n{:<40}{}\t\t{}\n\n",
      "Operation", "Buffer", "Occupied", 
      "---------", "------", "--------");

   std::jthread producer{produce}; // start producer thread
   std::jthread consumer{consume}; // start consumer thread 
} 

/*
OUTPUT1:
Action          Value   Sum of Produced Sum of Consumed
Operation                               Buffer          Occupied
---------                               ------          --------

Producer writes 1                       1               true

Producer tries to write.
Buffer full. Producer waits.            1               true

Consumer reads 1                        1               false

Producer writes 2                       2               true

Consumer reads 2                        2               false

Producer writes 3                       3               true

Consumer reads 3                        3               false

Consumer tries to read.
Buffer empty. Consumer waits.           3               false

Producer writes 4                       4               true

Consumer reads 4                        4               false

Producer writes 5                       5               true

Consumer reads 5                        5               false

Producer writes 6                       6               true

Producer tries to write.
Buffer full. Producer waits.            6               true

Consumer reads 6                        6               false

Producer writes 7                       7               true

Producer tries to write.
Buffer full. Producer waits.            7               true

Consumer reads 7                        7               false

Producer writes 8                       8               true

Consumer reads 8                        8               false

Producer writes 9                       9               true

Consumer reads 9                        9               false

Producer writes 10                      10              true

Producer done producing
Terminating Producer
Consumer reads 10                       10              false


Consumer read values totaling 55
Terminating Consumer

OUTPUT2: 
Operation                               Buffer          Occupied
---------                               ------          --------

Consumer tries to read.
Buffer empty. Consumer waits.           -1              false

Producer writes 1                       1               true

Consumer reads 1                        1               false

Producer writes 2                       2               true

Producer tries to write.
Buffer full. Producer waits.            2               true

Consumer reads 2                        2               false

Producer writes 3                       3               true

Consumer reads 3                        3               false

Consumer tries to read.
Buffer empty. Consumer waits.           3               false

Producer writes 4                       4               true

Consumer reads 4                        4               false

Producer writes 5                       5               true

Producer tries to write.
Buffer full. Producer waits.            5               true

Consumer reads 5                        5               false

Producer writes 6                       6               true

Producer tries to write.
Buffer full. Producer waits.            6               true

Consumer reads 6                        6               false

Producer writes 7                       7               true

Producer tries to write.
Buffer full. Producer waits.            7               true

Consumer reads 7                        7               false

Producer writes 8                       8               true

Producer tries to write.
Buffer full. Producer waits.            8               true

Consumer reads 8                        8               false

Producer writes 9                       9               true

Consumer reads 9                        9               false

Producer writes 10                      10              true

Producer done producing
Terminating Producer
Consumer reads 10                       10              false


Consumer read values totaling 55
Terminating Consumer
*/

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

