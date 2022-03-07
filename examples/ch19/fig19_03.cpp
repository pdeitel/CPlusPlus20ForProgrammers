// fig19_03.cpp 
// Contrasting input of a string via cin and cin.get.
#include <format>
#include <iostream>

int main() {
   // create two char arrays, each with 80 elements
   constexpr int size{80};
   char buffer1[size]{}; 
   char buffer2[size]{};

   // use cin to input characters into buffer1
   std::cout << "Enter a sentence:\n";
   std::cin >> buffer1;

   // display buffer1 contents
   std::cout << std::format("\nThe cin input was:\n{}\n\n", buffer1);
 
   // use cin.get to input characters into buffer2
   std::cin.get(buffer2, size);

   // display buffer2 contents
   std::cout << std::format("The cin.get input was:\n{}\n", buffer2);
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
