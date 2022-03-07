// fig06_05.cpp
// Compute the sum of an array's elements.
#include <fmt/format.h>
#include <iostream>
#include <array>

int main() {
   std::array items{10, 20, 30, 40}; // type inferred as array<int, 4>
   int total{0};

   // sum the contents of items            
   for (const int& item : items) {
      total += item;
   }

   std::cout << fmt::format("Total of array elements: {}\n", total);
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
