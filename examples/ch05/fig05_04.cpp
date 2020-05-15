// fig05_04.cpp
// Randomizing the die-rolling program.
#include <iostream>
#include <iomanip>
#include <cstdlib> // contains prototypes for functions srand and rand 
using namespace std;

int main() {
   int seed{0}; // stores the seed entered by the user

   cout << "Enter seed: ";
   cin >> seed;
   srand(seed); // seed random number generator

   // loop 10 times
   for (int counter{1}; counter <= 10; ++counter) {
      // pick random number from 1 to 6 and output it
      cout << (1 + rand() % 6) << " ";
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
