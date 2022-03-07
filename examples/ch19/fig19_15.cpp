// fig19_15.cpp 
// Floating-point values displayed in system default,
// scientific and fixed formats.
#include <iostream>

int main() {
   double x{0.001234567};
   double y{1.946e9};

   // display x and y in default format
   std::cout << "Displayed in default format:\n" << x << '\t' << y;

   // display x and y in scientific format
   std::cout << "\n\nDisplayed in scientific format:\n"
      << std::scientific << x << '\t' << y;

   // display x and y in fixed format
   std::cout << "\n\nDisplayed in fixed format:\n"
      << std::fixed << x << '\t' << y << "\n";
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
