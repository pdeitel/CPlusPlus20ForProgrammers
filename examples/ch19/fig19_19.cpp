// fig19_19.cpp 
// Testing error states.
#include <iostream>

int main() {
   int integerValue{0};

   // display results of cin functions
   std::cout << std::boolalpha << "Before a bad input operation:"
      << "\ncin.rdstate(): " << std::cin.rdstate()
      << "\n    cin.eof(): " << std::cin.eof()
      << "\n   cin.fail(): " << std::cin.fail()
      << "\n    cin.bad(): " << std::cin.bad() 
      << "\n   cin.good(): " << std::cin.good()
      << "\n\nExpects an integer, but enter a character: ";

   std::cin >> integerValue; // enter character value

   // display results of cin functions after bad input
   std::cout << "\nAfter a bad input operation:"
      << "\ncin.rdstate(): " << std::cin.rdstate()
      << "\n    cin.eof(): " << std::cin.eof() 
      << "\n   cin.fail(): " << std::cin.fail()
      << "\n    cin.bad(): " << std::cin.bad()
      << "\n   cin.good(): " << std::cin.good();

   std::cin.clear(); // clear stream

   // display results of cin functions after clearing cin
   std::cout << "\n\nAfter cin.clear()" 
      << "\ncin.fail(): " << std::cin.fail()
      << "\ncin.good(): " << std::cin.good() << "\n";
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
