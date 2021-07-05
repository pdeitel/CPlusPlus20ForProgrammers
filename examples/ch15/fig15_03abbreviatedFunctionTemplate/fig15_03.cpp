// fig15_03.cpp
// Abbreviated function template.
#include <array>
#include <iostream>
#include <string>
#include <vector>

// abbreviated function template printContainer displays a 
// container's elements separated by spaces.
void printContainer(const auto& items) {
   for (const auto& item : items) {
      std::cout << item << " ";
   }
}

int main() {
   using namespace std::string_literals; // for string object literals

   std::array ints{1, 2, 3, 4, 5};
   std::vector strings{"red"s, "green"s, "blue"s};

   std::cout << "ints: ";
   printContainer(ints);
   std::cout << "\nstrings: ";
   printContainer(strings);
   std::cout << "\n";
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
