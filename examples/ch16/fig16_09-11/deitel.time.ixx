// Fig. 16.09: deitel.time.ixx
// Primary module interface for a simple Time class.
export module deitel.time; // declare the primary module interface

import <string>; // rather than #include <string>

export namespace deitel::time {
   class Time { 
   public:
      // default constructor because it can be called with no arguments
      explicit Time(int hour = 0, int minute = 0, int second = 0);

      std::string toString() const; 
   private:
      int m_hour{0}; // 0 - 23 (24-hour clock format)
      int m_minute{0}; // 0 - 59
      int m_second{0}; // 0 - 59
   };
}

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
