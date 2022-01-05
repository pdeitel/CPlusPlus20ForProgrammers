// fig08_06.cpp
// Demonstrating the string find member functions.
#include <fmt/format.h> 
#include <iostream>
#include <string>

int main() {
   const std::string s{"noon is 12pm; midnight is not"};
   std::cout << "Original string: " << s;

   // find "is" from the beginning and end of s
   std::cout << fmt::format("\ns.find(\"is\"): {}\ns.rfind(\"is\"): {}",
      s.find("is"), s.rfind("is"));

   // find 'o' from beginning
   int location{s.find_first_of("misop")};
   std::cout << fmt::format("\ns.find_first_of(\"misop\") found {} at {}",
      s.at(location), location);

   // find 'o' from end
   location = s.find_last_of("misop");
   std::cout << fmt::format("\ns.find_last_of(\"misop\") found {} at {}",
      s.at(location), location);

   // find '1' from beginning
   location = s.find_first_not_of("noi spm");
   std::cout << fmt::format(
      "\ns.find_first_not_of(\"noi spm\") found {} at {}",
      s.at(location), location);

   // find ';' at location 12
   location = s.find_first_not_of("12noi spm");
   std::cout << fmt::format(
      "\ns.find_first_not_of(\"12noi spm\") found {} at {}",
      s.at(location), location);

   // search for characters not in "noon is 12pm; midnight is not"
   location = s.find_first_not_of("noon is 12pm; midnight is not");
   std::cout << fmt::format("\n{}: {}\n",
      "s.find_first_not_of(\"noon is 12pm; midnight is not\")",
      location);
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
