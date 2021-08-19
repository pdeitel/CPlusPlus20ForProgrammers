// fig16_03.cpp
// Importing a module and using its exported items.
import <iostream>; 
import welcome; // import the welcome module

int main() {
   std::cout << welcomeStandalone() << '\n' 
      << welcomeFromExportBlock() << '\n'
      << TestNamespace1::welcomeFromTestNamespace1() << '\n'
      << TestNamespace2::welcomeFromTestNamespace2() << '\n';
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
