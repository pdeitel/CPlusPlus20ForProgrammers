// fig06_02.cpp
// Initializing an array in a declaration.
#include <iostream>
#include <array>
using namespace std;

int main() {
   array<int, 5> n{32, 27, 64, 18, 95}; // list initializer

   // output each array element's value
   for (size_t i{0}; i < n.size(); ++i) {
      cout << n.at(i) << "  ";
   }

   cout << endl;
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
