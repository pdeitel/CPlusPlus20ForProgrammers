// fig09_27.cpp
// Demonstrating composition--an object with member objects.
#include <fmt/format.h>
#include <iostream>
#include "Date.h" // Date class definition
#include "Employee.h" // Employee class definition

int main() {
   const Date birth{1987 ,7, 24};
   const Date hire{2018, 3, 12};
   const Employee manager{"Sue", "Green", birth, hire};

   std::cout << fmt::format("\n{}\n\n", manager.toString());
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
