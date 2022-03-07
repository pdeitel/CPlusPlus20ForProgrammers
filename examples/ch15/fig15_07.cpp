// fig15_07.cpp
// Constrained multiply abbreviated function template.
#include <concepts>
#include <iostream>

// Numeric concept aggregates std::integral and std::floating_point
template<typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

// abbreviated function template with constrained auto
auto multiply(Numeric auto first, Numeric auto second) {
   return first * second;
}

int main() {
   std::cout << "Product of 5 and 3: " << multiply(5, 3)
      << "\nProduct of 7.25 and 2.0: " << multiply(7.25, 2.0)
      << "\nProduct of 5 and 7.25: " << multiply(5, 7.25) << "\n";
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
