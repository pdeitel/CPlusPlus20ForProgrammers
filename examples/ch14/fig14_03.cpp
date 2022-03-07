// fig14_03.cpp
// Algorithms equal, mismatch and lexicographical_compare.
#include <algorithm> // algorithm definitions
#include <array> // array class-template definition
#include <fmt/format.h> // C++20: This will be #include <format>
#include <iomanip>
#include <iostream>
#include <iterator> // ostream_iterator
#include <string>

int main() {
   std::array a1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   std::array a2{a1}; // initializes a2 with copy of a1
   std::array a3{1, 2, 3, 4, 1000, 6, 7, 8, 9, 10};
   std::ostream_iterator<int> output{std::cout, " "};

   std::cout << "a1 contains: ";
   std::ranges::copy(a1, output);
   std::cout << "\na2 contains: ";
   std::ranges::copy(a2, output);
   std::cout << "\na3 contains: ";
   std::ranges::copy(a3, output);

   // compare a1 and a2 for equality                        
   std::cout << fmt::format("\n\na1 is equal to a2: {}\n",
      std::ranges::equal(a1, a2));

   // compare a1 and a3 for equality                     
   std::cout << fmt::format("a1 is equal to a3: {}\n",
      std::ranges::equal(a1, a3));

   // check for mismatch between a1 and a3 
   auto location{std::ranges::mismatch(a1, a3)};
   std::cout << fmt::format("a1 and a3 mismatch at index {} ({} vs. {})\n",
      (location.in1 - a1.begin()), *location.in1, *location.in2);

   std::string s1{"HELLO"};
   std::string s2{"BYE BYE"};

   // perform lexicographical comparison of c1 and c2  
   std::cout << fmt::format("\"{}\" < \"{}\": {}\n", s1, s2,
      std::ranges::lexicographical_compare(s1, s2));
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
