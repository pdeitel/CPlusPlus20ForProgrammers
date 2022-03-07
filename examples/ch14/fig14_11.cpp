// fig14_11.cpp
// Algorithms includes, set_difference, set_intersection, 
// set_symmetric_difference and set_union.
#include <array>
#include <algorithm>
#include <fmt/format.h> // C++20: This will be #include <format>
#include <iostream>
#include <iterator> 
#include <vector> 

int main() {
   std::array a1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   std::array a2{4, 5, 6, 7, 8};
   std::array a3{4, 5, 6, 11, 15};
   std::ostream_iterator<int> output{std::cout, " "};

   std::cout << "a1 contains: ";
   std::ranges::copy(a1, output); // display array a1
   std::cout << "\na2 contains: ";
   std::ranges::copy(a2, output); // display array a2
   std::cout << "\na3 contains: ";
   std::ranges::copy(a3, output); // display array a3

   // determine whether a2 is completely contained in a1
   std::cout << fmt::format("\n\na1 {} a2",
      std::ranges::includes(a1, a2) ? "includes" : "does not include");

   // determine whether a3 is completely contained in a1
   std::cout << fmt::format("\n\na1 {} a3",
      std::ranges::includes(a1, a3) ? "includes" : "does not include");

   // determine elements of a1 not in a2 
   std::vector<int> difference{};
   std::ranges::set_difference(a1, a2, std::back_inserter(difference));
   std::cout << "\n\nset_difference of a1 and a2 is: ";
   std::ranges::copy(difference, output);

   // determine elements in both a1 and a2                 
   std::vector<int> intersection{};
   std::ranges::set_intersection(a1, a2,
      std::back_inserter(intersection));
   std::cout << "\n\nset_intersection of a1 and a2 is: ";
   std::ranges::copy(intersection, output);

   // determine elements of a1 that are not in a3 and              
   // elements of a3 that are not in a1                            
   std::vector<int> symmetricDifference{};
   std::ranges::set_symmetric_difference(a1, a3,
      std::back_inserter(symmetricDifference));
   std::cout << "\n\nset_symmetric_difference of a1 and a3 is: ";
   std::ranges::copy(symmetricDifference, output);

   // determine elements that are in either or both sets
   std::vector<int> unionSet{};
   std::ranges::set_union(a1, a3, std::back_inserter(unionSet));
   std::cout << "\n\nset_union of a1 and a3 is: ";
   std::ranges::copy(unionSet, output);
   std::cout << "\n";
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
