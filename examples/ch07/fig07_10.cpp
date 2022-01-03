// fig07_10.cpp
// Sizeof operator when used on a built-in array's name
// returns the number of bytes in the built-in array.
#include <fmt/format.h>
#include <iostream>

size_t getSize(double* ptr); // prototype

int main() {
   double numbers[20]; // 20 doubles; occupies 160 bytes on our system

   std::cout << fmt::format("Number of bytes in numbers is {}\n\n",
      sizeof(numbers));

   std::cout << fmt::format("Number of bytes returned by getSize is {}\n",
      getSize(numbers));
}

// return size of ptr         
size_t getSize(double* ptr) {
   return sizeof(ptr);
}



/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
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
