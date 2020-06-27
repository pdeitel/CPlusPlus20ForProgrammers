// fig08_17.cpp
// Regular expression replacements.
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include "fmt/format.h" // In C++20, this will be #include <format>  
using namespace std;

int main() {
   // replace tabs with commas
   string s1("1\t2\t3\t4");
   cout << "Original string: 1\\t2\\t3\\t4\n";
   cout << fmt::format("After replacing tabs with commas: {}\n", 
      regex_replace(s1, regex{R"(\t)"}, ","));
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
