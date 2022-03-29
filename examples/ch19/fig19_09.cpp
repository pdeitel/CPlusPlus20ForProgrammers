// fig19_09.cpp
// Creating and testing user-defined, nonparameterized 
// stream manipulators.
#include <iostream>

// bell manipulator (using escape sequence \a)
std::ostream& bell(std::ostream& output) {             
   return output << '\a'; // issue system beep
}

// tab manipulator (using escape sequence \t)
std::ostream& tab(std::ostream& output) {            
   return output << '\t'; // issue tab 
}

int main() {
   // use tab and bell manipulators
   std::cout << "Testing the tab manipulator:\n"
      << 'a' << tab << 'b' << tab << 'c' << '\n';

   std::cout << "Testing the bell manipulator\n" << bell;
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
