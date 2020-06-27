// fig08_06.cpp
// Demonstrating the string find member functions.
#include <iostream>
#include <string>
#include "fmt/format.h" // In C++20, this will be #include <format>  
using namespace std;

int main() {
   const string s{"noon is 12pm; midnight is not"};
   cout << "Original string: " << s;

   // find "is" from the beginning and end of s
   cout << fmt::format("\ns.find(\"is\"): {}\ns.rfind(\"is\"): {}",
      s.find("is"), s.rfind("is"));

   // find 'o' from beginning
   int location = s.find_first_of("misop");
   cout << fmt::format("\ns.find_first_of(\"misop\") found {} at {}",
      s.at(location), location);

   // find 'o' from end
   location = s.find_last_of("misop");
   cout << fmt::format("\ns.find_last_of(\"misop\") found {} at {}",
      s.at(location), location);

   // find '1' from beginning
   location = s.find_first_not_of("noi spm");
   cout << fmt::format(
      "\ns.find_first_not_of(\"noi spm\") found {} at {}",
      s.at(location), location);

   // find ';'
   location = s.find_first_not_of("12noi spm");
   cout << fmt::format(
      "\ns.find_first_not_of(\"12noi spm\") found {} at {}",
      s.at(location), location);

   // search for characters not in "noon is 12pm; midnight is not"
   location = s.find_first_not_of("noon is 12pm; midnight is not");
   cout << fmt::format("\ns.find_first_not_of("s +
      "\"noon is 12pm; midnight is not\"): {}"s, location);
}




/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
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
