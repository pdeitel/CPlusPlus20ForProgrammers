// fig08_18.cpp
// Matching patterns throughout a string.
#include <iostream>
#include <regex>
#include <string>
#include "fmt/format.h" // In C++20, this will be #include <format>  
using namespace std;

int main() {
   // performing a simple match
   string s1{"Programming is fun"};
   cout << fmt::format("s1: {}\n\n", s1);
   cout << "Search anywhere in s1:\n"
      << fmt::format("Programming: {}; fun: {}; fn: {}\n\n",
            regex_search(s1, regex{"Programming"}),
            regex_search(s1, regex{"fun"}),
            regex_search(s1, regex{"fn"}));

   // ignoring case
   string s2{"SAM WHITE"};
   smatch match; // store the text that matches the pattern
   cout << fmt::format("s2: {}\n\n", s2);
   cout << "Case insensitive search for Sam in s2:\n"
      << fmt::format("Sam: {}\n",
            regex_search(s2, match, regex{"Sam", regex_constants::icase}))
      << fmt::format("Matched text: {}\n\n", match.str());

   // finding all matches
   string contact{"Wally White, Home: 555-555-1234, Work: 555-555-4321"};
   regex phone{R"(\d{3}-\d{3}-\d{4})"};

   cout << "\nFinding all phone numbers in:\n" << contact << "\n";
   while (regex_search(contact, match, phone)) {
      cout << fmt::format("   {}\n", match.str());
      contact = match.suffix();
   }
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
