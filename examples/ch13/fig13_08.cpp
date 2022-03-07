// fig13_08.cpp
// Standard library multimap class template.
#include <fmt/format.h> // C++20: This will be #include <format>
#include <iostream>
#include <map> // multimap class-template definition

int main() {
   std::multimap<int, double> pairs{}; // create multimap
   std::cout << fmt::format("Number of 15 keys in pairs: {}\n",
      pairs.count(15));

   // insert two pairs
   pairs.insert(std::make_pair(15, 99.3));
   pairs.insert(std::make_pair(15, 2.7));
   std::cout << fmt::format("Number of 15 keys in pairs: {}\n\n",
      pairs.count(15));

   // insert five pairs
   pairs.insert({30, 111.11});
   pairs.insert({10, 22.22});
   pairs.insert({25, 33.333});
   pairs.insert({20, 9.345});
   pairs.insert({5, 77.54});

   std::cout << "Multimap pairs contains:\nKey\tValue\n";

   // walk through elements of pairs                    
   for (const auto& mapItem : pairs) {
      std::cout << fmt::format("{}\t{}\n", mapItem.first, mapItem.second);
   }
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
