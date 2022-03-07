// fig15_16.cpp
// Binary fold expressions.
#include <fmt/format.h> 
#include <iostream>

template <typename... Items>
auto binaryLeftAdd(Items... items) {
   return (0 + ... + items); // binary left fold
}

template <typename... Items>
auto binaryRightAdd(Items... items) {
   return (items + ... + 0); // binary right fold
}

template <typename... Items>
auto binaryLeftSubtract(Items... items) {
   return (0 - ... - items); // binary left fold
}

template <typename... Items>
auto binaryRightSubtract(Items... items) {
   return (items - ... - 0); // binary right fold
}

int main() {
   std::cout << "Binary left and right fold with addition:"
      << fmt::format("\n{}{}\n{}{}\n{}{}\n{}{}\n\n",
         "binaryLeftAdd(): ", binaryLeftAdd(),
         "binaryLeftAdd(1, 2, 3, 4): ", binaryLeftAdd(1, 2, 3, 4),
         "binaryRightAdd(): ", binaryRightAdd(),
         "binaryRightAdd(1, 2, 3, 4): ", binaryRightAdd(1, 2, 3, 4));

   std::cout << "Binary left and right fold with subtraction:"
      << fmt::format("\n{}{}\n{}{}\n{}{}\n{}{}\n",
         "binaryLeftSubtract(): ", binaryLeftSubtract(),
         "binaryLeftSubtract(1, 2, 3, 4): ",
         binaryLeftSubtract(1, 2, 3, 4),
         "binaryRightSubtract(): ", binaryRightSubtract(),
         "binaryRightSubtract(1, 2, 3, 4): ",
         binaryRightSubtract(1, 2, 3, 4));
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
