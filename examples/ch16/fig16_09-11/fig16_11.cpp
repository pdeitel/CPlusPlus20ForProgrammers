// fig16_11.cpp 
// Importing the deitel.time module and using its Time class.
import <iostream>;
import <stdexcept>;
import <string>;

import deitel.time;
using namespace deitel::time;

int main() {
   const Time t{ 12, 25, 42 }; // hour, minute and second specified      

   std::cout << "Time t:\n" << t.toString() << "\n\n";

   // attempt to initialize t2 with invalid values
   try {
      const Time t2{ 27, 74, 99 }; // all bad values specified
   }
   catch (const std::invalid_argument& e) {
      std::cout << "t2 not created: " << e.what() << '\n';
   }
}


/**************************************************************************
 * (C) Copyright 1992-2021 by Deitel & Associates, Inc. and               *
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
