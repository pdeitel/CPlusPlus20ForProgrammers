// fig19_08.cpp 
// width member function of classes istream and ostream.
#include <iostream>

int main() {
   int widthValue{4};
   char sentence[10]{};

   std::cout << "Enter a sentence:\n";
   std::cin.width(5); // input up to 4 characters from sentence

   // set field width, then display characters based on that width 
   while (std::cin >> sentence) {
      std::cout.width(widthValue++);
      std::cout << sentence << "\n";
      std::cin.width(5); // input up to 4 more characters from sentence
   } 
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
