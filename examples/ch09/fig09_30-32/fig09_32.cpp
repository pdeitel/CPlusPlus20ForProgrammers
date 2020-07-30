// fig09_32.cpp
// Cascading member-function calls with the this pointer.
#include <iostream>
#include "fmt/format.h" // In C++20, this will be #include <format> 
#include "Time.h" // Time class definition
using namespace std;

int main() {
   Time t{}; // create Time object

   t.setHour(18).setMinute(30).setSecond(22); // cascaded function calls

   // output time in universal and standard formats
   cout << fmt::format("Universal time: {}\nStandard time: {}\n\n",
              t.toUniversalString(), t.toStandardString());

   // cascaded function calls        
   cout << fmt::format("New standard time: {}\n",
              t.setTime(20, 20, 20).toStandardString());
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
