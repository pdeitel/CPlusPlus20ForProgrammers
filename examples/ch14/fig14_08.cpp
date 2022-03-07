// fig14_08.cpp
// Algorithms swap, iter_swap and swap_ranges.
#include <algorithm> 
#include <array>
#include <iostream>
#include <iterator> 

int main() {
   std::array values{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   std::ostream_iterator<int> output{std::cout, " "};

   std::cout << "values contains: ";
   std::ranges::copy(values, output);

   std::swap(values[0], values[1]); // swap elements at index 0 and 1

   std::cout << "\nafter std::swap of values[0] and values[1]: ";
   std::ranges::copy(values, output);

   // use iterators to swap elements at locations 0 and 1 
   std::iter_swap(values.begin(), values.begin() + 1);
   std::cout << "\nafter std::iter_swap of values[0] and values[1]: ";
   std::ranges::copy(values, output);

   // swap values and values2  
   std::array values2{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
   std::cout << "\n\nBefore swap_ranges\nvalues contains: ";
   std::ranges::copy(values, output);
   std::cout << "\nvalues2 contains: ";
   std::ranges::copy(values2, output);
   std::ranges::swap_ranges(values, values2);
   std::cout << "\n\nAfter swap_ranges\nvalues contains: ";
   std::ranges::copy(values, output);
   std::cout << "\nvalues2 contains: ";
   std::ranges::copy(values2, output);

   // swap first five elements of values and values2
   std::ranges::swap_ranges(values.begin(), values.begin() + 5,
      values2.begin(), values2.begin() + 5);

   std::cout << "\n\nAfter swap_ranges for 5 elements"
      << "\nvalues contains: ";
   std::ranges::copy(values, output);
   std::cout << "\nvalues2 contains: ";
   std::ranges::copy(values2, output);
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
