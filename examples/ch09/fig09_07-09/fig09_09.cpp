// fig09_09.cpp
// Program to test class Time.                     
// NOTE: This file must be compiled with Time.cpp. 
#include <iostream>
#include <stdexcept> // invalid_argument exception class
#include <string_view> 
#include <fmt/format.h> // In C++20, this will be #include <format> 
#include "Time.h" // definition of class Time from Time.h 
using namespace std;

// displays a Time in 24-hour and 12-hour formats
void displayTime(string_view message, const Time& time) {
   cout << fmt::format("{}\n24-hour time: {}\n12-hour time: {}\n\n",
      message, time.to24HourString(), time.to12HourString());
}

int main() {
   Time t{}; // instantiate object t of class Time

   displayTime("Initial time:", t); // display t's initial value
   t.setTime(13, 27, 6); // change time
   displayTime("After setTime:", t); // display t's new value

   // attempt to set the time with invalid values
   try {
      t.setTime(99, 99, 99); // all values out of range
   }
   catch (const invalid_argument& e) {
      cout << fmt::format("Exception: {}\n\n", e.what());
   }

   // display t's value after attempting to set an invalid time
   displayTime("After attempting to set an invalid time:", t);
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
