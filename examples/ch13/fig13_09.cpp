// fig13_09.cpp
// Standard library class map class template.
#include <iostream>
#include <fmt/format.h> // C++20: This will be #include <format>
#include <map> // map class-template definition

int main() {
   // create a map; duplicate keys are ignored
   std::map<int, double> pairs{{15, 2.7}, {30, 111.11}, {5, 1010.1},
      {10, 22.22}, {25, 33.333}, {5, 77.54}, {20, 9.345}, {15, 99.3}};

   // walk through elements of pairs
   std::cout << "pairs contains:\nKey\tValue\n";
   for (const auto& pair : pairs) {
      std::cout << fmt::format("{}\t{}\n", pair.first, pair.second);
   }
   
   pairs[25] = 9999.99; // use subscripting to change value for key 25
   pairs[40] = 8765.43; // use subscripting to insert value for key 40

   // use const_iterator to walk through elements of pairs
   std::cout << "\nAfter updates, pairs contains:\nKey\tValue\n";
   for (const auto& pair : pairs) {
      std::cout << fmt::format("{}\t{}\n", pair.first, pair.second);
   }
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
