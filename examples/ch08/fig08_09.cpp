// fig08_09.cpp
// C++17 string_view.
#include <iostream>
#include <string>
#include <string_view>
#include "fmt/format.h" // In C++20, this will be #include <format>  
using namespace std;

int main() {
   string s1{"red"};
   string s2{s1};
   string_view v1{s1}; // v2 "sees" the contents of s1
   cout << fmt::format("s1: {}\ns2: {}\nv1: {}\n\n", s1, s2, v1);

   // string_views see changes to the characters they view
   s1.at(0) = 'R'; // capitalize s1
   cout << fmt::format("s1: {}\ns2: {}\nv1: {}\n\n", s1, s2, v1);

   // string_views are comparable with strings or string_views
   cout << fmt::format("s1 == v1: {}\ns2 == v1: {}\n\n", 
              s1 == v1, s2 == v1);

   // string_view can remove a prefix or suffix
   v1.remove_prefix(1); // remove one character from the front
   v1.remove_suffix(1); // remove one character from the back
   cout << fmt::format("s1: {}\nv1: {}\n\n", s1, v1);

   // string_views are iterable
   string_view v2{"C-string"};
   cout << "The characters in v2 are: ";
   for (const char c : v2) {
      cout << c << " ";
   }

   // string_views enable various string operations on C-strings
   cout << fmt::format("\n\nv2.size(): {}\n", v2.size());
   cout << fmt::format("v2.find('-'): {}\n", v2.find('-'));
   cout << fmt::format("v2.starts_with('C'): {}\n", v2.starts_with('C'));
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
