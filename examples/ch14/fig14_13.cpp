// fig14_13.cpp
// Algorithms min, max, minmax and minmax_element.
#include <array>
#include <algorithm>
#include <iostream>

int main() {
   std::cout << "Minimum of 12 and 7 is: " << std::min(12, 7)
      << "\nMaximum of 12 and 7 is: " << std::max(12, 7)
      << "\nMinimum of 'G' and 'Z' is: '" << std::min('G', 'Z') << "'"
      << "\nMaximum of 'G' and 'Z' is: '" << std::max('G', 'Z') << "'"
      << "\nMinimum of 'z' and 'Z' is: '" << std::min('z', 'Z') << "'";

   // determine which argument is the min and which is the max
   auto [smaller, larger]{std::minmax(12, 7)};
   std::cout << "\n\nMinimum of 12 and 7 is: " << smaller
      << "\nMaximum of 12 and 7 is: " << larger;

   std::array items{3, 100, 52, 77, 22, 31, 1, 98, 13, 40};
   std::ostream_iterator<int> output{std::cout, " "};

   std::cout << "\n\nitems: ";
   std::ranges::copy(items, output);
   
   const auto& [smallest, largest]{std::ranges::minmax(items)};
   std::cout << "\nMinimum value in items: " << smallest
      << "\nMaximum value in items is: " << largest << "\n";
} 



/**************************************************************************
 * (C) Copyright 1992-2021 by Deitel & Associates, Inc. and               *
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
