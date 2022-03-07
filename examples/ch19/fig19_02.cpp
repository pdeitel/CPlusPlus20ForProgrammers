// fig19_02.cpp 
// get, put and eof member functions.
#include <format>
#include <iostream>

int main() {
   int character{0}; // use int, because char cannot represent EOF

   // prompt user to enter line of text
   std::cout << std::format("Before input, cin.eof(): {}", std::cin.eof())
      << "\nEnter a sentence followed by Enter and end-of-file:\n";

   // use get to read each character; use put to display it
   while ((character = std::cin.get()) != EOF) {
      std::cout.put(character);
   }

   // display end-of-file character
   std::cout << std::format("\nEOF on this system is: {}\n", character)
      << std::format("After EOF input, cin.eof(): {}\n", std::cin.eof());
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
