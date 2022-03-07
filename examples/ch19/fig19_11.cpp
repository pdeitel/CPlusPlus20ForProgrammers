// fig19_11.cpp 
// Left and right alignment with stream manipulators left and right.
#include <iomanip>
#include <iostream>

int main() {
   int x{12345};

   // display x right aligned (default)
   std::cout << "Default is right aligned:\n\""
      << std::setw(10) << x << "\"";

   // use left manipulator to display x left aligned
   std::cout << "\n\nUse left to left align x:\n\""
      << std::left << std::setw(10) << x << "\"";

   // use right manipulator to display x right aligned
   std::cout << "\n\nUse right to right align x:\n\""
      << std::right << std::setw(10) << x << "\"\n";
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
