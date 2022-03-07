// Fig. 17.16: SynchronizedBuffer.h 
// SynchronizedBuffer using two binary_semaphores to  
// maintain synchronized access to a shared mutable int.
#pragma once
#include <fmt/format.h> 
#include <iostream>
#include <semaphore>
#include <string>

using namespace std::string_literals;

class SynchronizedBuffer {
public:
   // place value into m_buffer
   void put(int value) {
      // acquire m_produce semaphore to be able to write to m_buffer
      m_produce.acquire(); // blocks if it's not the producer's turn 

      m_buffer = value; // write to m_buffer
      m_occupied = true;

      std::cout << fmt::format("{:<40}{}\t\t{}\n",
         "Producer writes "s + std::to_string(value),
         m_buffer, m_occupied);

      m_consume.release(); // allow consumer to read
   }

   // return value from m_buffer
   int get() {
      int value; // will store the value returned by get

      // acquire m_consume semaphore to be able to read from m_buffer
      m_consume.acquire(); // blocks if it's not the consumer's turn

      value = m_buffer; // read from m_buffer
      m_occupied = false;

      std::cout << fmt::format("{:<40}{}\t\t{}\n",
         "Consumer reads "s + std::to_string(m_buffer),
         m_buffer, m_occupied);

      m_produce.release(); // allow producer to write
      return value;
   }
private:
   std::binary_semaphore m_produce{1}; // producer can produce
   std::binary_semaphore m_consume{0}; // consumer can't consume
   bool m_occupied{false};
   int m_buffer{-1}; // shared by producer and consumer threads
};



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

