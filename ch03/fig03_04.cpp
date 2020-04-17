// fig03_04.cpp
// Prefix increment and postfix increment operators.
#include <iostream>
using namespace std;

int main() {
   // demonstrate postfix increment operator
   int c{5}; 
   cout << "c before postincrement: " << c << endl; // prints 5
   cout << "    postincrementing c: " << c++ << endl; // prints 5
   cout << " c after postincrement: " << c << endl; // prints 6                     

   cout << endl; // skip a line

   // demonstrate prefix increment operator
   c = 5;  
   cout << " c before preincrement: " << c << endl; // prints 5
   cout << "     preincrementing c: " << ++c << endl; // prints 6
   cout << "  c after preincrement: " << c << endl; // prints 6                     
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
 *************************************************************************/
