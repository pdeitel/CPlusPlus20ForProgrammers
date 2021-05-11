// fig14_01.cpp
// Lambda expressions.
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

int main() {
   std::array values{1, 2, 3, 4}; // initialize values
   std::ostream_iterator<int> output{std::cout, " "};

   std::cout << "values contains: ";
   std::ranges::copy(values, output);

   // output each element multiplied by two
   std::cout << "\nDisplay each element multiplied by two: ";
   std::ranges::for_each(values, [](auto i) {std::cout << i * 2 << " "; });

   // add each element to sum
   int sum{0}; // initialize sum to zero
   std::ranges::for_each(values, [&sum](auto i) {sum += i; });
   std::cout << "\nSum of value's elements is: " << sum << "\n";
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
