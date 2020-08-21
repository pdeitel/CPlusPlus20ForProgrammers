// fig09_18.cpp
// public member function that
// returns a reference to private data.
#include <iostream>
#include <fmt/format.h>
#include "Time.h" // include definition of class Time
using namespace std;

int main() {
   Time t{}; // create Time object

   // initialize hourRef with the reference returned by badSetHour
   int& hourRef{t.badSetHour(20)}; // 20 is a valid hour 

   cout << fmt::format("Valid hour before modification: {}\n", hourRef);
   hourRef = 30; // use hourRef to set invalid value in Time object t
   cout << fmt::format("Invalid hour after modification: {}\n\n", 
              t.getHour());

   // Dangerous: Function call that returns a reference can be 
   // used as an lvalue! POOR PROGRAMMING PRACTICE!!!!!!!!
   t.badSetHour(12) = 74; // assign another invalid value to hour

   cout << "After using t.badSetHour(12) as an lvalue, "
        << fmt::format("hour is: {}\n", t.getHour());
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
