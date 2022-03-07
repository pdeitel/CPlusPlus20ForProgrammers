// fig19_13.cpp 
// Using member function fill and stream manipulator setfill to change
// the padding character for fields larger than the printed value.
#include <iomanip>
#include <iostream>

int main() {
   int x{10000};

   // display x
   std::cout << x << " printed as int right and left aligned\n"
      << "and as hex with internal justification.\n"
      << "Using the default pad character (space):\n";

   // display x 
   std::cout << std::setw(10) << x << "\n";

   // display x with left justification
   std::cout << std::left << std::setw(10) << x << "\n";

   // display x with base as hex with internal justification
   std::cout << std::showbase << std::internal << std::setw(10) 
      << std::hex << x << "\n\n";

   std::cout << "Using various padding characters:\n";

   // display x using padded characters (right justification)
   std::cout << std::right;
   std::cout.fill('*');
   std::cout << std::setw(10) << std::dec << x << "\n";

   // display x using padded characters (left justification)
   std::cout << std::left << std::setw(10) << std::setfill('%') 
      << x << "\n";

   // display x using padded characters (internal justification)
   std::cout << std::internal << std::setw(10) 
      << std::setfill('^') << std::hex << x << "\n";
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
