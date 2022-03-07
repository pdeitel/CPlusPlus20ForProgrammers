// fig14_14.cpp
// Demonstrating algorithms gcd, lcm, iota, reduce and partial_sum.
#include <array> 
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric> 

int main() {
   std::ostream_iterator<int> output{std::cout, " "};

   // calculate the greatest common divisor of two integers
   std::cout << "std::gcd(75, 20): " << std::gcd(75, 20)
      << "\nstd::gcd(17, 13): " << std::gcd(75, 13);

   // calculate the least common multiple of two integers
   std::cout << "\n\nstd::lcm(3, 5): " << std::lcm(3, 5)
      << "\nstd::lcm(12, 9): " << std::lcm(12, 9);

   // fill an array with integers using the std::iota algorithm
   std::array<int, 5> ints{};
   std::iota(ints.begin(), ints.end(), 1);
   std::cout << "\n\nints: ";
   std::ranges::copy(ints, output);

   // reduce elements of a container to a single value
   std::cout << "\n\nsum of ints: "
      << std::reduce(ints.begin(), ints.end())
      << "\nproduct of ints: "
      << std::reduce(ints.begin(), ints.end(), 1, std::multiplies{});

   // calculate the partial sums of ints' elements 
   std::cout << "\n\nints: ";
   std::ranges::copy(ints, output);
   std::cout << "\n\npartial_sum of ints using std::plus by default: ";
   std::partial_sum(ints.begin(), ints.end(), output);
   std::cout << "\npartial_sum of ints using std::multiplies: ";
   std::partial_sum(ints.begin(), ints.end(), output, std::multiplies{});
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
