// fig15_13.cpp
// Manipulating tuples.
#include <fmt/format.h> 
#include <iostream>
#include <string>
#include <tuple>

// type alias for a tuple representing a hardware part's inventory
using Part = std::tuple<int, std::string, int, double>;

// return a part's inventory tuple 
Part getInventory(int partNumber) {
   using namespace std::string_literals; // for string object literals 

   switch (partNumber) {
   case 1:
      return {1, "Hammer"s, 32, 9.95}; // return a Part tuple
   case 2:
      return {2, "Screwdriver"s, 106, 6.99}; // return a Part tuple
   default:
      return {0, "INVALID PART"s, 0, 0.0}; // return a Part tuple
   }
}

int main() {
   // display the hardware part inventory
   for (int i{1}; i <= 2; ++i) {
      // unpack the returned tuple into four variables;
      // variables' types are inferred from the tuple's element values
      auto [partNumber, partName, quantity, price] {getInventory(i)};

      std::cout << fmt::format("{}: {}, {}: {}, {}: {}, {}: {:.2f}\n",
         "Part number", partNumber, "Tool", partName,
         "Quantity", quantity, "Price", price);
   }

   std::cout << "\nAccessing a tuple's elements by index number:\n";
   auto hammer{getInventory(1)};
   std::cout << fmt::format("{}: {}, {}: {}, {}: {}, {}: {:.2f}\n",
      "Part number", std::get<0>(hammer), "Tool", std::get<1>(hammer),
      "Quantity", std::get<2>(hammer), "Price", std::get<3>(hammer));

   std::cout << fmt::format("A Part tuple has {} elements\n",
      std::tuple_size<Part>{});
}



/**************************************************************************
 * (C) Copyright 1992-2020 by Deitel & Associates, Inc. and               *
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
