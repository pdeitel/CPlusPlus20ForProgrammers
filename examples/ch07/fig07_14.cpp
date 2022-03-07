// fig07_14.cpp
// C++20: Creating std::arrays from string literals with to_array.
#include <fmt/format.h>
#include <iostream>
#include <array>

int main() {
   // lambda to display a collection of items
   const auto display{
      [](const auto& items) {
         for (const auto& item : items) {
            std::cout << fmt::format("{} ", item);
         }
       }
   };

   // initializing an array with a string literal
   // creates a one-element array<const char*>
   const auto array1{std::array{"abc"}};
   std::cout << fmt::format("array1.size() = {}\narray1: ",
      array1.size());
   display(array1); // use lambda to display contents

   // creating std::array of characters from a string literal 
   const auto array2{std::to_array("C++20")};
   std::cout << fmt::format("\n\narray2.size() = {}\narray2: ",
      array2.size());
   display(array2); // use lambda to display contents

   std::cout << '\n';
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
