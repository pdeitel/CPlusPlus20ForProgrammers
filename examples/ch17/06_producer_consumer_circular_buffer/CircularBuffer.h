// Fig. 17.9: CircularBuffer.h
// Synchronizing access to a shared three-element circular buffer.
#pragma once
#include <array> 
#include <condition_variable> 
#include <fmt/format.h> 
#include <mutex>
#include <iostream>
#include <string>

using namespace std::string_literals;

class CircularBuffer {
public:
   // place value into m_buffer
   void put(int value) {
      // critical section that requires a lock to modify shared data
      {
         // lock on m_mutex to be able to write to m_buffer
         std::unique_lock dataLock{m_mutex};

         // if no empty locations, wait on condition variable m_cv  
         if (m_occupiedCells == m_buffer.size()) {
            std::cout << "Buffer is full. Producer waits.\n\n";

            // wait on the condition variable; the lambda argument 
            // ensures that if the thread gets the processor before
            // the m_buffer has open cells, the thread continues waiting
            m_cv.wait(dataLock, 
               [&] {return m_occupiedCells < m_buffer.size();});
         }

         m_buffer[m_writeIndex] = value;  // write to m_buffer
         ++m_occupiedCells; // one more m_buffer cell is full
         m_writeIndex = (m_writeIndex + 1) % m_buffer.size(); 
         displayState(fmt::format("Producer writes {}", value));
      } // dataLock's destructor releases the lock on m_mutex here

      m_cv.notify_one(); // notify threads waiting to read from m_buffer
   }
 
   // return value from m_buffer
   int get() const {
      int readValue; // will temporarily hold the next value read 

      // critical section that requires a lock to modify shared data
      {
         // lock on the condition variable to be able to write to m_buffer
         std::unique_lock dataLock{m_mutex};

         // if no data to read, place thread in waiting state
         if (m_occupiedCells == 0) {
            std::cout << "Buffer is empty. Consumer waits.\n\n";

            // wait on the condition variable; the lambda argument 
            // ensures that if the thread gets the processor before
            // there is data in the m_buffer, the thread continues waiting
            m_cv.wait(dataLock, [&]() {return m_occupiedCells > 0;});
         }

         readValue = m_buffer[m_readIndex]; // read value from m_buffer
         m_readIndex = (m_readIndex + 1) % m_buffer.size(); 
         --m_occupiedCells; // one fewer m_buffer cells are occupied
         displayState(fmt::format("Consumer reads {}", readValue));
      } // dataLock's destructor releases the lock on m_mutex here

      m_cv.notify_one(); // notify threads waiting to write to m_buffer
      return readValue;
   }

   // display current operation and m_buffer state
   void displayState(std::string operation) const {
      std::string s;
      
      // add operation argument and number of occupied m_buffer cells
      s += fmt::format("{} (buffer cells occupied: {})\n{:<15}",
         operation, m_occupiedCells, "buffer cells:");

      // add values in m_buffer 
      for (auto value : m_buffer) {
         s += fmt::format(" {:2d}  ", value);
      }

      s += fmt::format("\n{:<15}", ""); // padding

      // add underlines
      for (int i{0}; i < m_buffer.size(); ++i) {
         s += "---- "s;
      }

      s += fmt::format("\n{:<15}", ""); // padding

      for (int i{0}; i < m_buffer.size(); ++i) {
         if (i == m_writeIndex && i == m_readIndex) {
            s += " WR"; // both write and read index
         }
         else if (i == m_writeIndex) {
            s += " W   "; // just write index  
         }
         else if (i == m_readIndex) {
            s += "  R  "; // just read index
         }
         else {
            s += "     "; // neither index
         }
      }

      s += "\n\n";
      std::cout << s; // display the state string
   } 
private:
   mutable std::condition_variable m_cv;
   mutable std::mutex m_mutex;

   std::array<int, 3> m_buffer{-1, -1, -1}; // shared m_buffer
   mutable int m_occupiedCells{0}; // count number of buffers used
   int m_writeIndex{0}; // index of next element to write to
   mutable int m_readIndex{0}; // index of next element to read
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