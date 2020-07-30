// Fig. 9.11: Time.cpp
// Member-function definitions for class Time.
#include <stdexcept>
#include <string>
#include "fmt/format.h" // In C++20, this will be #include <format> 
#include "Time.h" // include definition of class Time from Time.h
using namespace std;

// Time constructor initializes each data member    
Time::Time(int hour, int minute, int second) {
   setTime(hour, minute, second); // validate and set time 
}

// set new Time value using universal time
void Time::setTime(int h, int m, int s) {
   setHour(h); // set private field hour
   setMinute(m); // set private field minute
   setSecond(s); // set private field second
}

// set hour value
void Time::setHour(int h) {
   if (h >= 0 && h < 24) {
      hour = h;
   }
   else {
      throw invalid_argument("hour must be 0-23");
   }
}

// set minute value
void Time::setMinute(int m) {
   if (m >= 0 && m < 60) {
      minute = m;
   }
   else {
      throw invalid_argument("minute must be 0-59");
   }
}

// set second value
void Time::setSecond(int s) {
   if (s >= 0 && s < 60) {
      second = s;
   }
   else {
      throw invalid_argument("second must be 0-59");
   }
}

// return hour value
int Time::getHour() const { return hour; }

// return minute value
int Time::getMinute() const { return minute; }

// return second value
int Time::getSecond() const { return second; }

// return Time as a string in universal-time format (HH:MM:SS)
string Time::toUniversalString() const {
   return fmt::format("{:02d}:{:02d}:{:02d}",
             getHour(), getMinute(), getSecond());
}

// return Time as string in standard-time format (HH:MM:SS AM or PM)
string Time::toStandardString() {
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
