// fig19_10.cpp 
// Displaying trailing zeros and decimal points in floating-point values.
#include <iostream>

int main() {
   // display double values with default stream format
   std::cout << "Before using showpoint"
      << "\n9.9900 prints as: " << 9.9900 
      << "\n9.9000 prints as: " << 9.9000 
      << "\n9.0000 prints as: " << 9.0000;

   // display double value after showpoint
   std::cout << std::showpoint
      << "\n\nAfter using showpoint" 
      << "\n9.9900 prints as: " << 9.9900 
      << "\n9.9000 prints as: " << 9.9000 
      << "\n9.0000 prints as: " << 9.0000 << '\n';
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
