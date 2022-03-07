// fig14_10.cpp
// Algorithms inplace_merge, unique_copy and reverse_copy.
#include <algorithm>
#include <array> 
#include <iostream>
#include <iterator> 
#include <vector> 

int main() {
   std::array a1{1, 3, 5, 7, 9, 1, 3, 5, 7, 9};
   std::ostream_iterator<int> output{std::cout, " "};

   std::cout << "array a1 contains: ";
   std::ranges::copy(a1, output);

   // merge first half of a1 with second half of a1 such that
   // a1 contains sorted set of elements after merge         
   std::ranges::inplace_merge(a1, a1.begin() + 5);
   std::cout << "\nAfter inplace_merge, a1 contains: ";
   std::ranges::copy(a1, output);

   // copy only unique elements of a1 into results1                 
   std::vector<int> results1{};
   std::ranges::unique_copy(a1, std::back_inserter(results1));
   std::cout << "\nAfter unique_copy, results1 contains: ";
   std::ranges::copy(results1, output);

   // copy elements of a1 into results2 in reverse order             
   std::vector<int> results2{};
   std::ranges::reverse_copy(a1, std::back_inserter(results2));
   std::cout << "\nAfter reverse_copy, results2 contains: ";
   std::ranges::copy(results2, output);
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
