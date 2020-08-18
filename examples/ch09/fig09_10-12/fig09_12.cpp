// fig09_12.cpp 
// Constructor with default arguments.
#include <iostream>
#include <stdexcept>
#include <string>
#include <fmt/format.h> // In C++20, this will be #include <format> 
#include "Time.h" // include definition of class Time from Time.h
using namespace std;

// displays a Time in 24-hour and 12-hour formats
void displayTime(string_view message, const Time& time) {
   cout << fmt::format("{}\n24-hour time: {}\n12-hour time: {}\n\n",
      message, time.to24HourString(), time.to12HourString());
}

int main() {
   const Time t1{}; // all arguments defaulted                            
   const Time t2{2}; // hour specified; minute and second defaulted     
   const Time t3{21, 34}; // hour and minute specified; second defaulted
   const Time t4{12, 25, 42}; // hour, minute and second specified      

   cout << "Constructed with:\n\n";
   displayTime("t1: all arguments defaulted", t1);
   displayTime("t2: hour specified; minute and second defaulted", t2);
   displayTime("t3: hour and minute specified; second defaulted", t3);
   displayTime("t4: hour, minute and second specified", t4);

   // attempt to initialize t5 with invalid values
   try {
      const Time t5{27, 74, 99}; // all bad values specified
   }
   catch (const invalid_argument& e) {
      cerr << fmt::format("t5 not created: {}\n", e.what());
   }
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
