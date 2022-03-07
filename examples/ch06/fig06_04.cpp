// fig06_04.cpp
// Set array values to the even integers from 2 to 10.
#include <fmt/format.h>
#include <iostream>
#include <array>

int main() {
   // constant can be used to specify array size
   constexpr size_t arraySize{5}; // must initialize in declaration

   std::array<int, arraySize> values{}; // array values has 5 elements

   for (size_t i{0}; i < values.size(); ++i) { // set the values
      values.at(i) = 2 + 2 * i;
   }

   // output contents of array values in tabular format
   for (const int& value : values) {
      std::cout << fmt::format("{}  ", value);
   }

   std::cout << '\n';
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
