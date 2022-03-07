// fig19_01.cpp
// Printing the address stored in a char* variable.
#include <iostream>

int main() {
   const char* const word{"again"};

   // display the value of char* variable word, then display 
   // the value of word after a static_cast to void*
   std::cout << "Value of word is: " << word 
      << "\nValue of static_cast<const void*>(word) is: " 
      << static_cast<const void*>(word) << '\n';
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
