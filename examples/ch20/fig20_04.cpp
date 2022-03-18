// fig20_04.cpp
// Demonstrating operator keywords.
//#include <ciso646> // enables operator keywords in Microsoft Visual C++
#include <fmt/format.h>
#include <iostream>

int main() {
   bool a{true};
   bool b{false};

   std::cout << fmt::format("a = {}; b = {}\n\n", a, b);

   std::cout << "Logical operator keywords:\n"
      << fmt::format("   a and a: {}\n", a and a)
      << fmt::format("   a and b: {}\n", a and b)
      << fmt::format("    a or a: {}\n", a or a)
      << fmt::format("    a or b: {}\n", a or b)
      << fmt::format("     not a: {}\n", not a)
      << fmt::format("     not b: {}\n", not b)
      << fmt::format("a not_eq b: {}\n", a not_eq b);
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
