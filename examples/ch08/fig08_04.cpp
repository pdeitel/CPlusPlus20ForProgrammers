// fig08_04.cpp
// Using the swap function to swap two strings.
#include <fmt/format.h> 
#include <iostream>
#include <string>

int main() {
   std::string s1{"one"};
   std::string s2{"two"};

   std::cout << fmt::format("Before swap:\ns1: {}; s2: {}", s1, s2);
   s1.swap(s2); // swap strings
   std::cout << fmt::format("\n\nAfter swap:\ns1: {}; s2: {}", s1, s2);
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
