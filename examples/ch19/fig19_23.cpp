// fig19_23.cpp 
// C++20 text-formatting field width and precision placeholders.
#include <format>
#include <iostream>

int main() {
   std::cout << "Demonstrating field width and precision placeholders:\n";

   double value{123.456};
   int width{8};

   for (int precision{0}; precision < 5; ++precision) {
      std::cout << std::format("{:{}.{}f}\n", value, width, precision);
   }
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
