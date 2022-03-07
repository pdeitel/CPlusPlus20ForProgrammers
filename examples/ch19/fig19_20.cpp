// fig19_20.cpp 
// C++20 text-formatting presentation types.
#include <format>
#include <iostream>

int main() {
   // floating-point presentation types
   std::cout << "Display 17.489 with and default, .1 and .2 precisions:\n"
      << std::format("f: {0:f}\n.1f: {0:.1f}\n.2f: {0:.2f}\n\n", 17.489);

   std::cout << "Display 10000000000000000.0 with f, e, g and a\n"
      << std::format("f: {0:f}\ne: {0:e}\ng: {0:g}\na: {0:a}\n\n", 
            10000000000000000.0);

   // integer presentation types; # displays a base prefix
   std::cout << "Display 100 with d, #b, #o and #x:\n"
      << std::format(
            "d: {0:d}\n#b: {0:#b}\n#o: {0:#o}\n#x: {0:#x}\n\n", 100);

   // character presentation type
   std::cout << "Display 65 and 97 with c:\n"
      << std::format("{:c} {:c}\n\n", 65, 97);

   // string presentation type
   std::cout << "Display \"hello\" with s:\n" 
      << std::format("{:s}\n", "hello");
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
