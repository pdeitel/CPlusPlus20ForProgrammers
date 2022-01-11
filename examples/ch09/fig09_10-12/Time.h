// Fig. 9.10: Time.h
// Time class containing a constructor with default arguments.
// Member functions defined in Time.cpp.
#pragma once // prevent multiple inclusions of header
#include <string>

// Time class definition
class Time {
public:
   // default constructor because it can be called with no arguments
   explicit Time(int hour = 0, int minute = 0, int second = 0);

   // set functions
   void setTime(int hour, int minute, int second);
   void setHour(int hour); // set hour (after validation)
   void setMinute(int minute); // set minute (after validation)
   void setSecond(int second); // set second (after validation)

   // get functions
   int getHour() const; // return hour
   int getMinute() const; // return minute
   int getSecond() const; // return second

   std::string to24HourString() const; // 24-hour time format string
   std::string to12HourString() const; // 12-hour time format string
private:
   int m_hour{0}; // 0 - 23 (24-hour clock format)
   int m_minute{0}; // 0 - 59
   int m_second{0}; // 0 - 59
};


/**************************************************************************
 * (C) Copyright 1992-2022 by Deitel & Associates, Inc. and               *
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
