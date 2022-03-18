// fig20_01.cpp
// Demonstrating const_cast.
#include <cctype> // contains prototype for function toupper
#include <iostream>
#include <string>

// returns the larger of two strings
const std::string& maximum(
   const std::string& first, const std::string& second) {
   return (first > second ? first : second);
}

int main() {
   std::string s1{"hello"}; // non-const string
   std::string s2{"goodbye"}; // non-const string

   // const_cast required to allow the const reference returned by 
   // maximum to be assigned to the std::string reference max
   std::string& max{const_cast<std::string&>(maximum(s1, s2))};

   std::cout << "The larger string is: " << max << "\n";

   for (char& character : max) {
      character = std::toupper(character);
   }

   std::cout << "The larger string capitalized is: " << max << "\n";
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
