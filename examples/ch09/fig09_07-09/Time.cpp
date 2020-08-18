// Fig. 9.8: Time.cpp
// Time class member-function definitions. 
#include <stdexcept> // for invalid_argument exception class     
#include <string>
#include <fmt/format.h> // In C++20, this will be #include <format> 
#include "Time.h" // include definition of class Time from Time.h 

using namespace std;

// set new Time value using 24-hour time
void Time::setTime(int hour, int minute, int second) {
   // validate hour, minute and second
   if ((hour < 0 || hour >= 24) || (minute < 0 || minute >= 60) ||
      (second < 0 || second >= 60)) {
      throw invalid_argument{"hour, minute or second was out of range"};
   }

   m_hour = hour;
   m_minute = minute;
   m_second = second;
}

// return Time as a string in 24-hour format (HH:MM:SS)
string Time::to24HourString() const {
   return fmt::format("{:02d}:{:02d}:{:02d}", m_hour, m_minute, m_second);
}

// return Time as string in 12-hour format (HH:MM:SS AM or PM)
string Time::to12HourString() const {
   return fmt::format("{}:{:02d}:{:02d} {}",
      ((m_hour % 12 == 0) ? 12 : m_hour % 12), m_minute, m_second,
      (m_hour < 12 ? "AM" : "PM"));
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
