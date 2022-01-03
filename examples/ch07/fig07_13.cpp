// fig07_13.cpp
// Reading in command-line arguments.
#include <fmt/format.h>
#include <iostream>

int main(int argc, char* argv[]) {
   std::cout << fmt::format("Number of arguments: {}\n\n", argc);

   for (int i{0}; i < argc; ++i) {
      std::cout << fmt::format("{}\n", argv[i]);
   }
}



/**************************************************************************
 * (C) Copyright 1992-2020 by Deitel & Associates, Inc. and               *
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
