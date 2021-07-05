// fig15_15.cpp
// Unary fold expressions.
#include <fmt/format.h> 
#include <iostream>

template <typename... Items>
auto unaryLeftAdd(Items... items) {
   return (... + items); // unary left fold
}

template <typename... Items>
auto unaryRightAdd(Items... items) {
   return (items + ...); // unary right fold
}

template <typename... Items>
auto unaryLeftSubtract(Items... items) {
   return (... - items); // unary left fold
}

template <typename... Items>
auto unaryRightSubtract(Items... items) {
   return (items - ...); // unary right fold
}

int main() {
   std::cout << "Unary left and right fold with addition:"
      << fmt::format("\n{}{}\n{}{}\n\n",
            "unaryLeftAdd(1, 2, 3, 4): ", unaryLeftAdd(1, 2, 3, 4),
            "unaryRightAdd(1, 2, 3, 4): ", unaryRightAdd(1, 2, 3, 4));

   std::cout << "Unary left and right fold with subtraction:"
      << fmt::format("\n{}{}\n{}{}\n",
            "unaryLeftSubtract(1, 2, 3, 4): ", 
            unaryLeftSubtract(1, 2, 3, 4),
            "unaryRightSubtract(1, 2, 3, 4): ", 
            unaryRightSubtract(1, 2, 3, 4));
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
