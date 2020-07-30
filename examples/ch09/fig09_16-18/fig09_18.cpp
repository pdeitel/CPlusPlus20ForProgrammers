// fig09_18.cpp
// public member function that
// returns a reference to private data.
#include <iostream>
#include "Time.h" // include definition of class Time
using namespace std;

int main() {
   Time t{}; // create Time object

   // initialize hourRef with the reference returned by badSetHour
   int& hourRef{t.badSetHour(20)}; // 20 is a valid hour 

   cout << "Valid hour before modification: " << hourRef;
   hourRef = 30; // use hourRef to set invalid value in Time object t
   cout << "\nInvalid hour after modification: " << t.getHour();

   // Dangerous: Function call that returns                      
   // a reference can be used as an lvalue!                      
   t.badSetHour(12) = 74; // assign another invalid value to hour

   cout << "\n\n*************************************************\n"
      << "POOR PROGRAMMING PRACTICE!!!!!!!!\n"
      << "t.badSetHour(12) as an lvalue, invalid hour: "
      << t.getHour()
      << "\n*************************************************" << endl;
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
