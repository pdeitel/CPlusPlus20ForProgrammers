// Fig. 9.31: Time.cpp 
// Time class member-function definitions.
#include <fmt/format.h>
#include <stdexcept>
#include "Time.h" // Time class definition

// Time constructor initializes each data member    
Time::Time(int hour, int minute, int second) {             
   setTime(hour, minute, second);
}

// set new Time value using 24-hour time
Time& Time::setTime(int hour, int minute, int second) {
   // validate hour, minute and second
   if (hour < 0 || hour >= 24) {
      throw std::invalid_argument{"hour was out of range"};
   } 

   if (minute < 0 || minute >= 60) { 
      throw std::invalid_argument{"minute was out of range"};
   } 

   if (second < 0 || second >= 60) {
      throw std::invalid_argument{"second was out of range"};
   } 

   m_hour = hour;
   m_minute = minute;
   m_second = second;
   return *this; // enables cascading
} 

// set hour value
Time& Time::setHour(int hour) {
   return setTime(hour, m_minute, m_second);
}

// set minute value
Time&  Time::setMinute(int minute) {
   return setTime(m_hour, minute, m_second);
}

// set second value
Time&  Time::setSecond(int second) {
   return setTime(m_hour, m_minute, second);
}

// get hour value
int Time::getHour() const {return m_hour;}

// get minute value
int Time::getMinute() const {return m_minute;}

// get second value
int Time::getSecond() const {return m_second;}

// return Time as a string in 24-hour format (HH:MM:SS)
std::string Time::to24HourString() const {
   return fmt::format("{:02d}:{:02d}:{:02d}", 
      getHour(), getMinute(), getSecond());
} 

// return Time as string in 12-hour format (HH:MM:SS AM or PM)
std::string Time::to12HourString() const {
   return fmt::format("{}:{:02d}:{:02d} {}", 
      ((getHour() % 12 == 0) ? 12 : getHour() % 12), 
      getMinute(), getSecond(), (getHour() < 12 ? "AM" : "PM"));
} 



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
