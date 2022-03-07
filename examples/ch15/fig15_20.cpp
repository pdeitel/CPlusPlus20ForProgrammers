// fig15_20.cpp
// Implementing customDistance using template metaprogramming.
#include <array>
#include <iostream>
#include <iterator>
#include <list>
#include <ranges>
#include <type_traits>

// calculate the distance (number of items) between two iterators;
// requires at least input iterators
template <std::input_iterator Iterator>
auto customDistance(Iterator begin, Iterator end) {
   // for random-access iterators subtract the iterators
   if constexpr (std::is_base_of_v<std::random_access_iterator_tag,
      Iterator::iterator_category>) {

      std::cout << "customDistance with random-access iterators\n";
      return end - begin; // O(1) operation for random-access iterators
   }
   else { // for all other iterators
      std::cout << "customDistance with non-random-access iterators\n";
      std::ptrdiff_t count{0};

      // increment from begin to end and count number of iterations;
      // O(n) operation for non-random-access iterators
      for (auto iter{begin}; iter != end; ++iter) {
         ++count;
      }

      return count;
   }
}

int main() {
   const std::array ints1{1, 2, 3, 4, 5}; // has random-access iterators
   const std::list ints2{1, 2, 3}; // has bidirectional iterators

   auto result1{customDistance(ints1.begin(), ints1.end())};
   std::cout << "ints1 number of elements: " << result1 << "\n";
   auto result2{customDistance(ints2.begin(), ints2.end())};
   std::cout << "ints2 number of elements: " << result2 << "\n";
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
