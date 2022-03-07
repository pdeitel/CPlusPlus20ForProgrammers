// fig15_10.cpp
// A custom algorithm to calculate the average of 
// a numeric input range's elements.
#include <algorithm>
#include <array>
#include <concepts>
#include <iostream>
#include <iterator>
#include <list>
#include <ranges>
#include <vector>

// concept for an input range containing integer or floating-point values
template<typename T>
concept NumericInputRange = std::ranges::input_range<T> &&
(std::integral<typename T::value_type> ||
   std::floating_point<typename T::value_type>);

// calculate the average of a NumericInputRange's elements
auto average(NumericInputRange auto const& range) {
   long double total{0};

   for (auto i{range.begin()}; i != range.end(); ++i) {
      total += *i; // dereference iterator and add value to total  
   }

   // divide total by the number of elements in range
   return total / std::ranges::distance(range);
}

int main() {
   std::ostream_iterator<int> outputInt(std::cout, " ");
   const std::array ints{1, 2, 3, 4, 5};
   std::cout << "array ints: ";
   std::ranges::copy(ints, outputInt);
   std::cout << "\naverage of ints: " << average(ints);

   std::ostream_iterator<double> outputDouble(std::cout, " ");
   const std::vector doubles{10.1, 20.2, 35.3};
   std::cout << "\n\nvector doubles: ";
   std::ranges::copy(doubles, outputDouble);
   std::cout << "\naverage of doubles: " << average(doubles);

   std::ostream_iterator<long double> outputLongDouble(std::cout, " ");
   const std::list longDoubles{10.1L, 20.2L, 35.3L};
   std::cout << "\n\nlist longDoubles: ";
   std::ranges::copy(longDoubles, outputLongDouble);
   std::cout << "\naverage of longDoubles: " << average(longDoubles)
      << "\n";
}



/**************************************************************************
 * (C) Copyright 1992-2022 by Deitel & Associates, Inc. and               *
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
