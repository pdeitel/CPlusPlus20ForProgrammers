// fig06_11.cpp
// Compute the sum of the elements of an array using accumulate.
#include <array>
#include <fmt/format.h>
#include <iostream>
#include <numeric>

int main() {
   constexpr std::array integers{10, 20, 30, 40};
   std::cout << fmt::format("Total of array elements: {}\n",
      std::accumulate(std::begin(integers), std::end(integers), 0));
}

/**************************************************************************
 * (C) Copyright 1992-2020 by Deitel & Associates, Inc. and               *
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
