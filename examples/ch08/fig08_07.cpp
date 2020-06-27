// fig08_07.cpp
// Demonstrating string member functions erase and replace.
#include <iostream>
#include <string>
#include "fmt/format.h" // In C++20, this will be #include <format>  
using namespace std;

int main() {
   // compiler concatenates all parts into one string
   string string1{"The values in any left subtree"
      "\nare less than the value in the"
      "\nparent node and the values in"
      "\nany right subtree are greater"
      "\nthan the value in the parent node"};

   cout << fmt::format("Original string:\n{}\n\n", string1);

   string1.erase(62); // remove from index 62 through end of string1
      cout << fmt::format("string1 after erase:\n{}\n", string1);

   size_t position = string1.find(" "); // find first space

   // replace all spaces with period
   while (position != string::npos) {
      string1.replace(position, 1, ".");
      position = string1.find(" ", position + 1);
   }

   cout << fmt::format("After first replacement:\n{}\n", string1);

   position = string1.find("."); // find first period

   // replace all periods with two semicolons
   // NOTE: this will overwrite characters
   while (position != string::npos) {
      string1.replace(position, 2, "xxxxx;;yyy", 5, 2);
      position = string1.find(".", position + 1);
   }

   cout << fmt::format("After second replacement:\n{}\n", string1);
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

