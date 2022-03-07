// fig19_21.cpp 
// C++20 text-formatting with field widths and alignment.
#include <format>
#include <iostream>

int main() {
   std::cout << "Default alignment with field width 10:\n"
      << std::format("[{:10d}]\n[{:10f}]\n[{:10}]\n\n", 27, 3.5, "hello");
   
   std::cout << "Specifying left or right alignment in a field:\n"
      << std::format("[{:<15d}]\n[{:<15f}]\n[{:>15}]\n\n", 
            27, 3.5, "hello");

   std::cout << "Centering text in a field:\n"
      << std::format("[{:^7d}]\n[{:^7.1f}]\n[{:^7}]\n", 27, 3.5, "hello");
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
