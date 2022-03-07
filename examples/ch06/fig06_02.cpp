// fig06_02.cpp
// Initializing an array in a declaration.
#include <fmt/format.h>
#include <iostream>
#include <array>

int main() {
   std::array<int, 5> values{32, 27, 64, 18, 95}; // braced initializer

   // output each array element's value
   for (size_t i{0}; i < values.size(); ++i) {
      std::cout << fmt::format("{}  ", values.at(i));
   }

   std::cout << "\n\n";

   // using class template argument deduction to determine values2's type
   std::array values2{1.1, 2.2, 3.3, 4.4};

   // output each array element's value
   for (size_t i{0}; i < values.size(); ++i) {
      std::cout << fmt::format("{}  ", values.at(i));
   }

   std::cout << "\n";
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
