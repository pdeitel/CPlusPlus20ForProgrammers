// fig19_04.cpp 
// Inputting characters using cin member function getline.
#include <format>
#include <iostream>

int main() {
   const int size{80};
   char buffer[size]{}; // create array of 80 characters

   // input characters in buffer via cin function getline
   std::cout << "Enter a sentence:\n";
   std::cin.getline(buffer, size);

   // display buffer contents
   std::cout << std::format("\nYou entered:\n{}\n", buffer);
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
