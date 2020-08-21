// Fig. 9.17: Time.cpp
// Time class member-function definitions.
#include <stdexcept>
#include "Time.h" // include definition of class Time
using namespace std;

// set values of hour, minute and second
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

// return hour value
int Time::getHour() const {return m_hour;}

// poor practice: returning a reference to a private data member. 
int& Time::badSetHour(int hour) {
   if (hour < 0 || hour >= 24) {
      throw invalid_argument{"hour must be 0-23"};
   } 

   m_hour = hour;
   return m_hour; // dangerous reference return                    
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
