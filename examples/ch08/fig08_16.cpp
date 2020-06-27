// fig08_16.cpp
// Matching entire strings to regular expressions.
#include <iostream>
#include <regex>
#include "fmt/format.h" // In C++20, this will be #include <format>  
using namespace std;

int main() {
   // fully match a pattern of literal characters
   regex r1("02215"); 
   cout << "Matching against: 02215\n" 
        << fmt::format("02215: {}; 51220: {}\n\n", 
              regex_match("02215", r1), regex_match("51220", r1));

   // fully match five digits
   regex r2(R"(\d{5})");
   cout << R"(Matching against: \d{5})" << "\n"
        << fmt::format("02215: {}; 9876: {}\n\n",
              regex_match("02215", r2), regex_match("9876", r2));

   // match a word that starts with a capital letter
   regex r3("[A-Z][a-z]*");
   cout << "Matching against: [A-Z][a-z]*\n"
        << fmt::format("Wally: {}; eva: {}\n\n",
              regex_match("Wally", r3), regex_match("eva", r3));

   // match any character that's not a lowercase letter
   regex r4("[^a-z]");
   cout << "Matching against: [^a-z]\n"
        << fmt::format("A: {}; a: {}\n\n",
              regex_match("A", r4), regex_match("a", r4));

   // match metacharacters as literals in a custom character class
   regex r5("[*+$]");
   cout << "Matching against: [*+$]\n"
        << fmt::format("*: {}; !: {}\n\n",
              regex_match("*", r5), regex_match("!", r5));

   // matching a capital letter followed by at least one lowercase letter 
   regex r6("[A-Z][a-z]+");
   cout << "Matching against: [A-Z][a-z]*\n"
        << fmt::format("Wally: {}; E: {}\n\n",
              regex_match("Wally", r6), regex_match("E", r6));

   // matching zero or one occurrence of a subexpression
   regex r7("labell?ed");
   cout << "Matching against: labell?ed\n"
        << fmt::format("labelled: {}; labeled: {}; labellled: {}\n\n",
              regex_match("labelled", r7), regex_match("labeled", r7), 
              regex_match("labellled", r7));

   // matching n (3) or more occurrences of a subexpression
   regex r8(R"(\d{3,})");
   cout << R"(Matching against: \d{3,})" << "\n"
        << fmt::format("123: {}; 1234567890: {}; 12: {}\n\n",
              regex_match("123", r8), regex_match("1234567890", r8),
              regex_match("12", r8));

   // matching n to m inclusive (3-6), occurrences of a subexpression
   regex r9(R"(\d{3,6})");
   cout << R"(Matching against: \d{3,6})" << "\n"
        << fmt::format("123: {}; 123456: {}; 1234567: {}; 12: {}\n",
              regex_match("123", r9), regex_match("123456", r9),
              regex_match("1234567", r9), regex_match("12", r9));
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
