// fig13_02.cpp
// Standard library vector class template.
#include <fmt/format.h> // C++20: This will be #include <format>
#include <iostream>
#include <ranges>
#include <vector> // vector class-template definition

// display value appended to vector and updated vector size and capacity
void showResult(int value, size_t size, size_t capacity) {
   std::cout << fmt::format("appended: {}; size: {}; capacity: {}\n",
      value, size, capacity);
}

int main() {
   std::vector<int> integers{}; // create vector of ints

   std::cout << "Size of integers: " << integers.size()
      << "\nCapacity of integers: " << integers.capacity() << "\n\n";

   // append 1-10 to integers and display updated size and capacity
   for (int i : std::views::iota(1, 11)) {
      integers.push_back(i); // push_back is in vector, deque and list
      showResult(i, integers.size(), integers.capacity());
   }

   std::cout << "\nOutput integers using iterators: ";

   for (auto constIterator{integers.cbegin()};
      constIterator != integers.cend(); ++constIterator) {
      std::cout << *constIterator << ' ';
   }

   std::cout << "\nOutput integers in reverse using iterators: ";

   // display vector in reverse order using const_reverse_iterator
   for (auto reverseIterator{integers.crbegin()};
      reverseIterator != integers.crend(); ++reverseIterator) {
      std::cout << *reverseIterator << ' ';
   }

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
