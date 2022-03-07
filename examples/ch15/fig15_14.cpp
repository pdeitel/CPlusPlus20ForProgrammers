// fig15_14.cpp
// Variadic function templates.
#include <fmt/format.h> 
#include <iostream>
#include <string>

// base-case function for one argument 
template <typename T>
auto sum(T item) {
   return item;
}

// recursively add one or more arguments
template <typename FirstItem, typename... RemainingItems>
auto sum(FirstItem first, RemainingItems... theRest) {
   return first + sum(theRest...); // expand parameter pack for next call
}

// add one or more arguments with a fold expression
template <typename FirstItem, typename... RemainingItems>
auto foldingSum(FirstItem first, RemainingItems... theRest) {
   return (first + ... + theRest); // expand the parameter 
}

int main() {
   using namespace std::literals;

   std::cout << "Recursive variadic function template sum:"
      << fmt::format("\n{}{}\n{}{}\n{}{}\n{}{}\n\n",
         "sum(1): ", sum(1), "sum(1, 2): ", sum(1, 2),
         "sum(1, 2, 3): ", sum(1, 2, 3),
         "sum(\"s\"s, \"u\"s, \"m\"s): ", sum("s"s, "u"s, "m"s));

   std::cout << "Variadic function template foldingSum:"
      << fmt::format("\n{}{}\n{}{}\n{}{}\n{}{}\n",
         "sum(1): ", foldingSum(1), "sum(1, 2): ", foldingSum(1, 2),
         "sum(1, 2, 3): ", foldingSum(1, 2, 3),
         "sum(\"s\"s, \"u\"s, \"m\"s): ",
         foldingSum("s"s, "u"s, "m"s));
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
