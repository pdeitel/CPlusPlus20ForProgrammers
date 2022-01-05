// fig08_02.cpp
// Comparing strings.
#include <fmt/format.h>
#include <iostream>
#include <string>

void displayResult(const std::string& s, int result) {
   if (result == 0) {
      std::cout << fmt::format("{} == 0\n", s);
   }
   else if (result > 0) {
      std::cout << fmt::format("{} > 0\n", s);
   }
   else { // result < 0
      std::cout << fmt::format("{} < 0\n", s);
   }
}

int main() {
   const std::string s1{"Testing the comparison functions."};
   const std::string s2{"Hello"};
   const std::string s3{"stinger"};
   const std::string s4{s2}; // "Hello"

   std::cout << fmt::format("s1: {}\ns2: {}\ns3: {}\ns4: {}",
      s1, s2, s3, s4);

   // comparing s1 and s4
   if (s1 > s4) {
      std::cout << "\n\ns1 > s4\n";
   }

   // comparing s1 and s2
   displayResult("s1.compare(s2)", s1.compare(s2));

   // comparing s1 (elements 2-6) and s3 (elements 0-4)
   displayResult("s1.compare(2, 5, s3, 0, 5)",
      s1.compare(2, 5, s3, 0, 5));

   // comparing s2 and s4
   displayResult("s4.compare(0, s2.size(), s2)",
      s4.compare(0, s2.size(), s2));

   // comparing s2 and s4
   displayResult("s2.compare(0, 3, s4)", s2.compare(0, 3, s4));
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
