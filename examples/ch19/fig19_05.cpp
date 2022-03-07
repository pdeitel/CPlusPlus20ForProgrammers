// fig19_05.cpp 
// Unformatted I/O using read, gcount and write.
#include <iostream>

int main() {
   char buffer[80]{}; // create array of 80 characters

   // use function read to input characters into buffer
   std::cout << "Enter a sentence:\n";
   std::cin.read(buffer, 20);

   // use functions write and gcount to display buffer characters
   std::cout << "\nThe sentence entered was:\n";
   std::cout.write(buffer, std::cin.gcount());
   std::cout << '\n';
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
