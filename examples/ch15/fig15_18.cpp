// fig15_18.cpp
// Constraining a variadic-function-template parameter pack to
// elements of the same type.
#include <concepts> 
#include <iostream>
#include <string>

template <typename T, typename... Us>
concept SameTypeElements = (std::same_as<T, Us> && ...);

// add one or more arguments with a fold expression
template <typename FirstItem, typename... RemainingItems>
   requires SameTypeElements<FirstItem, RemainingItems...>
auto foldingSum(FirstItem first, RemainingItems... theRest) {
   return (first + ... + theRest); // expand the parameter 
}

int main() {
   using namespace std::literals;

   foldingSum(1, 2, 3); // valid: all are int values
   foldingSum("s"s, "u"s, "m"s); // valid: all are std::string objects
   foldingSum(1, 2.2, "hello"s); // error: three different types
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