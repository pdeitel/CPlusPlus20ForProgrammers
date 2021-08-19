// Fig. 16.11: deitel.time-impl.cpp
// deitel.time module implementation unit containing the 
// Time class member function definitions. 
module deitel.time; // module implementation unit for deitel.time

import <stdexcept>;
import <string>;
using namespace deitel::time;

// Time constructor initializes each data member    
Time::Time(int hour, int minute, int second) {
   // validate hour, minute and second
   if ((hour < 0 || hour >= 24) || (minute < 0 || minute >= 60) ||
      (second < 0 || second >= 60)) {
      throw std::invalid_argument{
         "hour, minute or second was out of range" };
   }

   m_hour = hour;
   m_minute = minute;
   m_second = second;
}

// return a string representation of the Time
std::string Time::toString() const {
   using namespace std::string_literals;

   return "Hour: "s + std::to_string(m_hour) +
      "\nMinute: "s + std::to_string(m_minute) +
      "\nSecond: "s + std::to_string(m_second);
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
