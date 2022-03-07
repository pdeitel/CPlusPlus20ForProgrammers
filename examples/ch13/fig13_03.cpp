// fig13_03.cpp
// Testing standard library vector class template
// element-manipulation functions.
#include <algorithm> // copy algorithm
#include <fmt/format.h> // C++20: This will be #include <format>
#include <iostream>
#include <ranges> 
#include <iterator> // ostream_iterator iterator
#include <vector> 

int main() {
   std::vector values{1, 2, 3, 4, 5}; // class template argument deduction
   std::vector<int> integers{values.cbegin(), values.cend()};
   std::ostream_iterator<int> output{std::cout, " "};

   std::cout << "integers contains: ";
   std::copy(integers.cbegin(), integers.cend(), output);

   std::cout << fmt::format("\nfront: {}\nback: {}\n\n",
      integers.front(), integers.back());

   integers[0] = 7; // set first element to 7             
   integers.at(2) = 10; // set element at position 2 to 10

   // insert 22 as second element                  
   integers.insert(integers.cbegin() + 1, 22);

   std::cout << "Contents of vector integers after changes: ";
   std::ranges::copy(integers, output);

   integers.erase(integers.cbegin()); // erase first element
   std::cout << "\n\nintegers after erasing first element: ";
   std::ranges::copy(integers, output);

   // erase remaining elements                          
   integers.erase(integers.cbegin(), integers.cend());
   std::cout << fmt::format("\nErased all elements: integers {} empty\n",
      integers.empty() ? "is" : "is not");

   // insert elements from the vector values                             
   integers.insert(integers.cbegin(), values.cbegin(), values.cend());
   std::cout << "\nContents of vector integers before clear: ";
   std::ranges::copy(integers, output);

   // empty integers; clear empties a collection
   integers.clear();
   std::cout << fmt::format("\nAfter clear, integers {} empty\n",
      integers.empty() ? "is" : "is not");
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
