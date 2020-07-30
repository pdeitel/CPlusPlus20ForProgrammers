// Fig. 9.10: Time.h
// Time class containing a constructor with default arguments.
// Member functions defined in Time.cpp.
#include <string>

// prevent multiple inclusions of header
#ifndef TIME_H
#define TIME_H

// Time class definition
class Time {
public:
   explicit Time(int h = 0, int m = 0, int s = 0); // default constructor

   // set functions
   void setTime(int h, int m, int s); // set hour, minute, second
   void setHour(int h); // set hour (after validation)
   void setMinute(int m); // set minute (after validation)
   void setSecond(int s); // set second (after validation)

   // get functions
   int getHour() const; // return hour
   int getMinute() const; // return minute
   int getSecond() const; // return second

   std::string toUniversalString() const; // 24-hour time format string
   std::string toStandardString() const; // 12-hour time format string
private:
   int hour{0}; // 0 - 23 (24-hour clock format)
   int minute{0}; // 0 - 59
   int second{0}; // 0 - 59
};

#endif

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
