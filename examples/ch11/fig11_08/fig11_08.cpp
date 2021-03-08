// fig11_08.cpp
// Demonstrating an explicit constructor.
#include <iostream>
#include "MyArray.h"
using namespace std;

void outputArray(const MyArray&); // prototype

int main() {
   MyArray ints1{7}; // 7-element MyArray
   outputArray(ints1); // output MyArray ints1
   outputArray(3); // convert 3 to a MyArray and output its contents
   outputArray(MyArray(3)); // explicit single-argument constructor call
}  

// print MyArray contents
void outputArray(const MyArray& arrayToOutput) {
   cout << "The MyArray received has " << arrayToOutput.size() 
      << " elements. The contents are: " << arrayToOutput << ;
} 



/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
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
