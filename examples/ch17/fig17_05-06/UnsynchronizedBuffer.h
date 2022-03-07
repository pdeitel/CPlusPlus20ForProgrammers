// Fig. 17.5: UnsynchronizedBuffer.h
// UnsynchronizedBuffer incorrectly maintains a shared integer that is 
// accessed by a producer thread and a consumer thread.
#pragma once
#include <fmt/format.h>
#include <iostream>
#include <string>

class UnsynchronizedBuffer {
public:
   // place value into buffer
   void put(int value) {
      std::cout << fmt::format("Producer writes\t{:2d}", value);
      m_buffer = value;
   }

   // return value from buffer
   int get() const {
      std::cout << fmt::format("Consumer reads\t{:2d}", m_buffer);
      return m_buffer;
   }
private:
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

