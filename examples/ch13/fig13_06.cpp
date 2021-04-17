// fig13_06.cpp
// Standard library multiset class template
#include <algorithm> // copy algorithm
#include <fmt/format.h> // C++20: This will be #include <format>
#include <iostream>
#include <iterator> // ostream_iterator
#include <ranges> 
#include <set> // multiset class-template definition
#include <vector>

int main() {
   std::multiset<int, std::less<int>> ints{}; // multiset of int values
   std::cout << fmt::format("15s in ints: {}\n", ints.count(15));

   std::cout << "\nInserting two 15s into ints\n";
   ints.insert(15); // insert 15 in ints
   ints.insert(15); // insert 15 in ints
   std::cout << fmt::format("15s in ints: {}\n\n", ints.count(15));

   // search for 15 and 20 in ints; find returns an iterator
   for (int i : {15, 20}) {
      if (auto result{ints.find(i)}; result != ints.end()) {
         std::cout << fmt::format("Found {} in ints\n", i);
      }
      else {
         std::cout << fmt::format("Did not find {} in ints\n", i);
      }
   }

   // search for 15 and 20 in ints; contains returns a bool
   for (int i : {15, 20}) {
      if (ints.contains(i)) {
         std::cout << fmt::format("Found {} in ints\n", i);
      }
      else {
         std::cout << fmt::format("Did not find {} in ints\n", i);
      }
   }

   // insert elements of vector values into ints
   const std::vector values{7, 22, 9, 1, 18, 30, 100, 22, 85, 13};
   ints.insert(values.cbegin(), values.cend());
   std::cout << "\nAfter insert, ints contains:\n";
   std::ranges::copy(ints, std::ostream_iterator<int>{std::cout, " "});

   // determine lower and upper bound of 22 in ints
   std::cout << fmt::format(
                   "\n\nlower_bound(22): {}\nupper_bound(22): {}\n\n",
                   *(ints.lower_bound(22)), *(ints.upper_bound(22)));

   // use equal_range to determine lower and upper bound of 22 in ints 
   auto p{ints.equal_range(22)};
   std::cout << fmt::format(
                   "lower_bound(22): {}\nupper_bound(22): {}\n",
                   *(p.first), *(p.second));
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
