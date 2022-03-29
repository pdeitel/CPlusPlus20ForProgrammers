// fig19_22.cpp 
// C++20 text-formatting numeric formatting options.
#include <format>
#include <iostream>

int main() {
   std::cout << "Displaying signs and padding with leading 0s:\n"
      << std::format("[{0:+10d}]\n[{0:+010d}]\n\n", 27);

   std::cout << "Displaying a space before a positive value:\n"
      << std::format("{0:d}\n{0: d}\n{1: d}\n\n", 27, -27);
   
   std::cout << "Displaying a base indicator before a number:\n"
      << std::format("{0:d}\n{0:#b}\n{0:#o}\n{0:#x}\n", 100);
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
