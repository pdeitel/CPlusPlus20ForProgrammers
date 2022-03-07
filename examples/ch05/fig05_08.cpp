// fig05_08.cpp
// Passing arguments by value and by reference.
#include <iostream>
using namespace std;

int squareByValue(int number); // prototype (for value pass)          
void squareByReference(int& numberRef); // prototype (for reference pass)

int main() {
   int x{2}; // value to square using squareByValue
   int z{4}; // value to square using squareByReference

   // demonstrate squareByValue
   cout << "x = " << x << " before squareByValue\n";
   cout << "Value returned by squareByValue: "
      << squareByValue(x) << endl;
   cout << "x = " << x << " after squareByValue\n\n";

   // demonstrate squareByReference
   cout << "z = " << z << " before squareByReference\n";
   squareByReference(z);
   cout << "z = " << z << " after squareByReference\n";
}

// squareByValue multiplies number by itself, stores the     
// result in number and returns the new value of number      
int squareByValue(int number) {
   return number *= number; // caller's argument not modified 
}

// squareByReference multiplies numberRef by itself and stores the result
// in the variable to which numberRef refers in function main            
void squareByReference(int& numberRef) {
   numberRef *= numberRef; // caller's argument modified 
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
