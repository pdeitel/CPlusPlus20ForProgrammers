// fig19_14.cpp 
// Stream manipulator showbase.
#include <iostream>

int main() {
   int x{100};

   // use showbase to show number base
   std::cout << "Printing octal and hexadecimal values with showbase:\n" 
      << std::showbase;

   std::cout << x << "\n"; // print decimal value
   std::cout << std::oct << x << "\n"; // print octal value
   std::cout << std::hex << x << "\n"; // print hexadecimal value
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
