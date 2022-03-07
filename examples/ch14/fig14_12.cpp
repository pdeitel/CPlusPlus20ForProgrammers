// fig14_12.cpp
// Algorithms lower_bound, upper_bound and 
// equal_range for a sorted sequence of values.
#include <algorithm> 
#include <array> 
#include <iostream>
#include <iterator> 

int main() {
   std::array values{2, 2, 4, 4, 4, 6, 6, 6, 6, 8};
   std::ostream_iterator<int> output{std::cout, " "};

   std::cout << "values contains: ";
   std::ranges::copy(values, output);

   // determine lower-bound insertion point for 6 in values 
   auto lower{std::ranges::lower_bound(values, 6)};
   std::cout << "\n\nLower bound of 6 is index: "
      << (lower - values.begin());

   // determine upper-bound insertion point for 6 in values 
   auto upper{std::ranges::upper_bound(values, 6)};
   std::cout << "\nUpper bound of 6 is index: "
      << (upper - values.begin());

   // use equal_range to determine the lower and upper bound of 6
   auto [first, last]{std::ranges::equal_range(values, 6)};
   std::cout << "\nUsing equal_range:\n   Lower bound of 6 is index: "
      << (first - values.begin());
   std::cout << "\n   Upper bound of 6 is index: "
      << (last - values.begin());

   // determine lower-bound insertion point for 3 in values
   std::cout << "\n\nUse lower_bound to locate the first point "
      << "at which 3 can be inserted in order";
   lower = std::ranges::lower_bound(values, 3);
   std::cout << "\n   Lower bound of 3 is index: "
      << (lower - values.begin());

   // determine upper-bound insertion point for 7 in values
   std::cout << "\n\nUse upper_bound to locate the last point "
      << "at which 7 can be inserted in order";
   upper = std::ranges::upper_bound(values, 7);
   std::cout << "\n   Upper bound of 7 is index: "
      << (upper - values.begin()) << "\n";
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
