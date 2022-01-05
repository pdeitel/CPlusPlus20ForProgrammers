// fig08_08.cpp
// Demonstrating std::string insert member functions.
#include <fmt/format.h> 
#include <iostream>
#include <string>

int main() {
   std::string s1{"beginning end"};
   std::string s2{"12345678"};

   std::cout << fmt::format("Initial strings:\ns1: {}\ns2: {}\n\n",
      s1, s2);

   s1.insert(10, "middle "); // insert "middle " at location 10 
   s2.insert(3, "xx", 0, std::string::npos); // insert "xx" at location 3

   std::cout << fmt::format("Strings after insert:\ns1: {}\ns2: {}\n",
      s1, s2);
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
