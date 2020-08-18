// Fig. 9.11: Time.cpp
// Member-function definitions for class Time.
#include <stdexcept>
#include <string>
#include <fmt/format.h> // In C++20, this will be #include <format> 
#include "Time.h" // include definition of class Time from Time.h
using namespace std;

// Time constructor initializes each data member    
Time::Time(int hour, int minute, int second) {
   setHour(hour); // validate and set private field m_hour
   setMinute(minute); // validate and set private field m_minute
   setSecond(second); // validate and set private field m_second
}

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

// set hour value
void Time::setHour(int hour) {
   if (hour < 0 || hour >= 24) {
      throw invalid_argument{"hour must be 0-23"};
   }

   m_hour = hour;
}

// set minute value
void Time::setMinute(int minute) {
   if (minute < 0 || minute >= 60) {
      throw invalid_argument{"minute must be 0-59"};
   }

   m_minute = minute;
}

// set second value
void Time::setSecond(int second) {
   if (second < 0 && second >= 60) {
      throw invalid_argument{"second must be 0-59"};
   }

   m_second = second;
}

// return hour value
int Time::getHour() const { return m_hour; }

// return minute value
int Time::getMinute() const { return m_minute; }

// return second value
int Time::getSecond() const { return m_second; }

// return Time as a string in 24-hour format (HH:MM:SS)
string Time::to24HourString() const {
   return fmt::format("{:02d}:{:02d}:{:02d}",
      getHour(), getMinute(), getSecond());
}

// return Time as string in 12-hour format (HH:MM:SS AM or PM)
string Time::to12HourString() const {
   return fmt::format("{}:{:02d}:{:02d} {}",
      ((getHour() % 12 == 0) ? 12 : getHour() % 12),
      getMinute(), getSecond(), (getHour() < 12 ? "AM" : "PM"));
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
