// Fig. 9.31: Time.cpp 
// Time class member-function definitions.
#include <stdexcept>
#include <fmt/format.h> // In C++20, this will be #include <format> 
#include "Time.h" // Time class definition
using namespace std;

// Time constructor initializes each data member    
Time::Time(int hour, int minute, int second) {
   setHour(hour); // validate and set private field m_hour
   setMinute(minute); // validate and set private field m_minute
   setSecond(second); // validate and set private field m_second
}

// set new Time value using universal time
Time& Time::setTime(int hour, int minute, int second) {
   Time time{hour, minute, second}; // create a temporary Time object
   *this = time; // assign time's members to current object
   return *this; // enables cascading
}

// set hour value
Time& Time::setHour(int hour) { // note Time& return 
   if (hour < 0 || hour >= 24) {
      throw invalid_argument{"hour must be 0-23"};
   }

   m_hour = hour;
   return *this; // enables cascading
}

// set minute value
Time& Time::setMinute(int m) { // note Time& return
   if (m < 0 || m >= 60) {
      throw invalid_argument{"minute must be 0-59"};
   }

   m_minute = m;
   return *this; // enables cascading
}

// set second value
Time& Time::setSecond(int s) { // note Time& return
   if (s < 0 || s >= 60) {
      throw invalid_argument{"second must be 0-59"};
   }

   m_second = s;
   return *this; // enables cascading
}

// get hour value
int Time::getHour() const { return m_hour; }

// get minute value
int Time::getMinute() const { return m_minute; }

// get second value
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
