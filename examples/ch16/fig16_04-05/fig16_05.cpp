// fig16_05.cpp
// Showing that a module's non-exported identifiers are inaccessible.
import <iostream>; 
import deitel.math; // import the deitel.math module

int main() {
   // can call square because it's exported from namespace deitel::math, 
   // which implicitly exports the namespace
   std::cout << "square(3) = " << deitel::math::square(3) << '\n';

   // cannot call cube because it's not exported 
   std::cout << "cube(3) = " << deitel::math::cube(3) << '\n';
}





 /*************************************************************************
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
