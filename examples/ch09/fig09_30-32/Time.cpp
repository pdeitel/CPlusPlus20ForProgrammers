// Fig. 9.31: Time.cpp 
// Time class member-function definitions.
#include <iomanip>
#include <stdexcept>
#include "fmt/format.h" // In C++20, this will be #include <format> 
#include "Time.h" // Time class definition
using namespace std;

// constructor function to initialize private data;
// calls member function setTime to set variables;
// default values are 0 (see class definition)
Time::Time(int h, int m, int s) {
   setTime(h, m, s); 
} 

// set values of hour, minute, and second
Time& Time::setTime(int h, int m, int s) { // note Time& return
   setHour(h);
   setMinute(m);
   setSecond(s); 
   return *this; // enables cascading
} 

// set hour value
Time& Time::setHour(int h) { // note Time& return 
   if (h < 0 || h >= 24) {
      throw invalid_argument("hour must be 0-23");
   } 

   hour = h;
   return *this; // enables cascading
} 

// set minute value
Time& Time::setMinute(int m) { // note Time& return
   if (m < 0 || m >= 60) {
      throw invalid_argument("minute must be 0-59");
   } 

   minute = m;
   return *this; // enables cascading
} 

// set second value
Time& Time::setSecond(int s) { // note Time& return
   if (s < 0 || s >= 60) {
      throw invalid_argument("second must be 0-59");
   } 

   second = s;
   return *this; // enables cascading
} 

// get hour value
int Time::getHour() const {return hour;}

// get minute value
int Time::getMinute() const {return minute;}

// get second value
int Time::getSecond() const {return second;}

// return Time as a string in universal-time format (HH:MM:SS)
string Time::toUniversalString() const {
   return fmt::format("{:02d}:{:02d}:{:02d}", 
             getHour(), getMinute(), getSecond());
} 

// return Time as string in standard-time format (HH:MM:SS AM or PM)
string Time::toStandardString() const {
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
