// fig06_03.cpp
// Using range-based for.
#include <fmt/format.h>
#include <iostream>
#include <array>

int main() {
   std::array items{1, 2, 3, 4, 5}; // type inferred as array<int, 5>

   // display items before modification
   std::cout << "items before modification: ";
   for (const int& item : items) { // item is a reference to a const int
      std::cout << fmt::format("{} ", item); 
   }                       
 
   // multiply the elements of items by 2
   for (int& item : items) { // item is a reference to an int
      item *= 2;
   }

   // display items after modification
   std::cout << "\nitems after modification: ";
   for (const int& item : items) {
      std::cout << fmt::format("{} ", item);
   }

   // sum elements of items using range-based for with initialization
   std::cout << "\n\ncalculating a running total of items' values:\n";
   for (int runningTotal{0}; const int& item : items) {
      runningTotal += item;
      std::cout << fmt::format("item: {}; running total: {}\n",
         item, runningTotal);
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
