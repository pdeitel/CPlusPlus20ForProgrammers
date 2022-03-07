// fig06_09.cpp
// Sorting and searching arrays.
#include <array>
#include <algorithm> // contains sort and binary_search
#include <fmt/format.h>
#include <iostream>
#include <string>

int main() {
   using namespace std::string_literals; // enables string object literals

   // colors is inferred to be an array<string, 7>
   std::array colors{"red"s, "orange"s, "yellow"s,
      "green"s, "blue"s, "indigo"s, "violet"s};

   // output original array
   std::cout << "Unsorted colors array:\n   ";
   for (const std::string& color : colors) {
      std::cout << fmt::format("{} ", color);
   }

   // sort contents of colors
   std::sort(std::begin(colors), std::end(colors));

   // output sorted array
   std::cout << "\nSorted colors array:\n   ";
   for (const std::string& color : colors) {
      std::cout << fmt::format("{} ", color);
   }

   // search for "indigo" in colors
   bool found{std::binary_search(
      std::begin(colors), std::end(colors), "indigo")};
   std::cout << fmt::format("\n\n\"indigo\" {} found in colors array\n",
      found ? "was" : "was not");

   // search for "cyan" in colors
   found = std::binary_search(
      std::begin(colors), std::end(colors), "cyan");
   std::cout << fmt::format("\"cyan\" {} found in colors array\n",
      found ? "was" : "was not");
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
