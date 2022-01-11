// Fig. 9.11: Time.cpp
// Member-function definitions for class Time.
#include <fmt/format.h>
#include <stdexcept>
#include <string>
#include "Time.h" // include definition of class Time from Time.h

// Time constructor initializes each data member    
Time::Time(int hour, int minute, int second) {             
   setTime(hour, minute, second);
}

// set new Time value using 24-hour time
void Time::setTime(int hour, int minute, int second) {
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
} 

// set hour value
void Time::setHour(int hour) {setTime(hour, m_minute, m_second);}

// set minute value
void Time::setMinute(int minute) {setTime(m_hour, minute, m_second);}

// set second value
void Time::setSecond(int second) {setTime(m_hour, m_minute, second);}

// return hour value
int Time::getHour() const {return m_hour;}

// return minute value
int Time::getMinute() const {return m_minute;}

// return second value
int Time::getSecond() const {return m_second;}

// return Time as a string in 24-hour format (HH:MM:SS)
std::string Time::to24HourString() const {
   return fmt::format("{:02d}:{:02d}:{:02d}", 
      getHour(), getMinute(), getSecond());
} 

// return Time as string in 12-hour format (HH:MM:SS AM or PM)
std::string Time::to12HourString() {
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
