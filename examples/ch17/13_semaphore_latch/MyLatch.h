// Fig. 17.17: MyLatch.h
// Custom latch implemented with a binary_semaphore and an atomic_int.
#pragma once
#include <semaphore>

class MyLatch {
public:
   // initialize latch count 
   MyLatch(int count) : m_count{count} {}

   // disallow copying latches
   MyLatch(const MyLatch&) = delete;
   MyLatch& operator=(const MyLatch&) = delete;

   // signal the latch
   void count_down() {
      ++m_currentCount;

      // if all threads reached the latch, waiting threads are unblocked
      if (m_currentCount == m_count) {
         m_semaphore.release();
      }
   }

   // Wait if m_count threads have not reached the latch. 
   // Once able to proceed, call m_semaphore's release function 
   // to ensure another waiting thread can proceed.
   void wait() const {
      if (m_currentCount < m_count) {
         m_semaphore.acquire(); // calling thread waits on m_semaphore
         m_semaphore.release(); // unblock waiting threads
      }
   }
private:
   const int m_count; // latch's starting count
   mutable std::binary_semaphore m_semaphore{0};
   std::atomic_int m_currentCount{0}; // # of threads that have arrived
};


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
