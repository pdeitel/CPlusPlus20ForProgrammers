// fig09_21.cpp 
// Demonstrating that class objects can be assigned
// to each other using the default assignment operator.
#include <fmt/format.h>
#include <iostream>
#include "Date.h" // include definition of class Date from Date.h
using namespace std;

int main() {
   const Date date1{2006, 7, 4};
   Date date2{2022, 1, 1};

   std::cout << fmt::format("date1: {}\ndate2: {}\n\n",
      date1.toString(), date2.toString());
   date2 = date1; // uses the default assignment operator
   std::cout << fmt::format("After assignment, date2: {}\n",
      date2.toString());
}




/**************************************************************************
 * (C) Copyright 1992-2022 by Deitel & Associates, Inc. and               *
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
