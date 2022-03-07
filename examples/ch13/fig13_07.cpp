// fig13_07.cpp
// Standard library set class template.
#include <algorithm>
#include <fmt/format.h> // C++20: This will be #include <format>
#include <iostream>
#include <iterator> // ostream_iterator
#include <set>

int main() {
   std::set doubles{2.1, 4.2, 9.5, 2.1, 3.7}; // CTAD 

   std::ostream_iterator<double> output{std::cout, " "};
   std::cout << "doubles contains: ";
   std::ranges::copy(doubles, output);

   // insert 13.8 in doubles; insert returns pair in which
   // p.first represents location of 13.8 in doubles and  
   // p.second represents whether 13.8 was inserted         
   auto p{doubles.insert(13.8)}; // value not in set   
   std::cout << fmt::format("\n{} {} inserted\n", *(p.first),
      (p.second ? "was" : "was not"));
   std::cout << "doubles contains: ";
   std::ranges::copy(doubles, output);

   // insert 9.5 in doubles                          
   p = doubles.insert(9.5); // value already in set
   std::cout << fmt::format("\n{} {} inserted\n", *(p.first),
      (p.second ? "was" : "was not"));
   std::cout << "doubles contains: ";
   std::ranges::copy(doubles, output);
   std::cout << "\n";
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
