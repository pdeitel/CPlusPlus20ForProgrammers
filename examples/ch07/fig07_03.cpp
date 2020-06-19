// fig07_03.cpp
// Pass-by-reference with a pointer argument used to cube a 
// variable's value.
#include <iostream>
using namespace std;

void cubeByReference(int* nPtr); // prototype 

int main() {
   int number{5};

   cout << "The original value of number is " << number;
   cubeByReference(&number); // pass number address to cubeByReference
   cout << "\nThe new value of number is " << number << endl;
}

// calculate cube of *nPtr; modifies variable number in main 
void cubeByReference(int* nPtr) {
   *nPtr = *nPtr * *nPtr * *nPtr; // cube *nPtr              
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
