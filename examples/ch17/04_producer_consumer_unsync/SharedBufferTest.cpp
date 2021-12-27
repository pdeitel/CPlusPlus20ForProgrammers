// Fig. 17.6: SharedBufferTest.cpp
// Application with concurrent jthreads sharing an unsynchronized buffer.
#include <chrono>
#include <fmt/format.h>
#include <iostream>
#include <random>
#include <thread>
#include "UnsynchronizedBuffer.h"

int main() {
   // set up random number generation 
   std::random_device rd;
   std::mt19937_64 random{rd()};
   std::uniform_int_distribution ints{0, 3000};

   // create UnsynchronizedBuffer to store ints       
   UnsynchronizedBuffer buffer;

   // lambda expression that produces the values 1-10 and sums them 
   auto produce{
      [&]() {
         int sum{0};

         for (int count{1}; count <= 10; ++count) {
            // get random sleep time then sleep
            std::chrono::milliseconds sleepTime{ints(random)};
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
      [&]() {
         int sum = 0;

         for (int count = 1; count <= 10; ++count) {
            // get random sleep time then sleep
            std::chrono::milliseconds sleepTime{ints(random)};
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

/*
OUTPUT1:
Action          Value   Sum of Produced Sum of Consumed
------          -----   --------------- ---------------
Consumer reads  -1                      -1
Producer writes  1       1
Consumer reads   1                       0
Producer writes  2       3
Consumer reads   2                       2
Producer writes  3       6
Producer writes  4      10
Producer writes  5      15
Producer writes  6      21
Consumer reads   6                       8
Producer writes  7      28
Consumer reads   7                      15
Consumer reads   7                      22
Producer writes  8      36
Producer writes  9      45
Producer writes 10      55
Producer done producing
Terminating Producer
Consumer reads  10                      32
Consumer reads  10                      42
Consumer reads  10                      52
Consumer reads  10                      62

Consumer read values totaling 62
Terminating Consumer


OUTPUT2: 
Action          Value   Sum of Produced Sum of Consumed
------          -----   --------------- ---------------
Consumer reads  -1                      -1
Consumer reads  -1                      -2
Consumer reads  -1                      -3
Producer writes  1       1
Producer writes  2       3
Producer writes  3       6
Producer writes  4      10
Consumer reads   4                       1
Consumer reads   4                       5
Producer writes  5      15
Producer writes  6      21
Producer writes  7      28
Consumer reads   7                      12
Consumer reads   7                      19
Producer writes  8      36
Consumer reads   8                      27
Consumer reads   8                      35
Producer writes  9      45
Consumer reads   9                      44

Consumer read values totaling 44
Terminating Consumer
Producer writes 10      55
Producer done producing
Terminating Producer
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

