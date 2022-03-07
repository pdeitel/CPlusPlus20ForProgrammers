// fig14_09.cpp
// Algorithms copy_backward, merge, unique, reverse, copy_if and copy_n.
#include <algorithm> 
#include <array>  
#include <iostream>
#include <iterator> 
#include <vector>

int main() {
   std::array a1{1, 3, 5, 7, 9};
   std::array a2{2, 4, 5, 7, 9};
   std::ostream_iterator<int> output{std::cout, " "};

   std::cout << "array a1 contains: ";
   std::ranges::copy(a1, output); // display a1
   std::cout << "\narray a2 contains: ";
   std::ranges::copy(a2, output); // display a2

   // place elements of a1 into results in reverse order  
   std::array<int, a1.size()> results{};
   std::ranges::copy_backward(a1, results.end());
   std::cout << "\n\nAfter copy_backward, results contains: ";
   std::ranges::copy(results, output);

   // merge elements of a1 and a2 into results2 in sorted order
   std::array<int, a1.size() + a2.size()> results2{};
   std::ranges::merge(a1, a2, results2.begin());

   std::cout << "\n\nAfter merge of a1 and a2, results2 contains: ";
   std::ranges::copy(results2, output);

   // eliminate duplicate values from v 
   std::vector v(results2.begin(), results2.end());
   auto [first, last] {std::ranges::unique(v)};
   v.erase(first, last); // remove elements that no longer contain values

   std::cout << "\n\nAfter unique v contains: ";
   std::ranges::copy(v, output);

   std::cout << "\n\nAfter reverse, a1 contains: ";
   std::ranges::reverse(a1); // reverse elements of a1
   std::ranges::copy(a1, output);

   // copy odd elements of a2 into v2
   std::vector<int> v2{};
   std::cout << "\n\nAfter copy_if, v2 contains: ";
   std::ranges::copy_if(a2, std::back_inserter(v2),
      [](auto x) {return x % 2 == 0; });
   std::ranges::copy(v2, output);

   // copy three elements of a2 into v3
   std::vector<int> v3{};
   std::cout << "\n\nAfter copy_n, v3 contains: ";
   std::ranges::copy_n(a2.begin(), 3, std::back_inserter(v3));
   std::ranges::copy(v3, output);
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
