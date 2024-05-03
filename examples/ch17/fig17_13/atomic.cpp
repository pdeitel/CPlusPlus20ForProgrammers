// Fig. 17.13: atomic.cpp
// Incrementing integers from concurrent threads 
// with and without atomics.
#include <atomic>
#include <fmt/format.h>
#include <iostream>
#include <thread>

int main() {
   int count1{0};
   std::atomic<int> atomicCount{0};
   int count2{0};
   std::atomic_ref<int> atomicRefCount{count2};

   {
      std::cout << "Two concurrent threads incrementing int count1, "
         << "atomicCount and atomicRefCount\n\n";

      // lambda to increment counters 
      auto incrementer{
         [&]() {
            for (int i{0}; i < 1000; ++i) {
               ++count1; // no synchronization
               ++atomicCount; // ++ is an atomic operation
               ++atomicRefCount; // ++ is an atomic operation
               std::this_thread::yield(); // force thread to give up CPU
            }
         }
      };

      std::jthread t1{incrementer};
      std::jthread t2{incrementer};
   }

   std::cout << fmt::format("Final count1: {}\n", count1);
   std::cout << fmt::format("Final atomicCount: {}\n", atomicCount.load());
   std::cout << fmt::format("Final count2: {}\n", count2);
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
