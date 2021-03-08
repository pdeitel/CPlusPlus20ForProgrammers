// fig11_14.cpp
// Testing class MyArray with move semantics.
#include <iostream>
#include <stdexcept>
#include <utility> // for std::move
#include "MyArray.h"
using namespace std;

// function to return an MyArray by value
MyArray getArrayByValue() {
   MyArray localIntegers(3);
   localIntegers[0] = 10;
   localIntegers[1] = 20;
   localIntegers[2] = 30;
   return localIntegers; // return by value creates an rvalue
}

int main() {
   // create 7-element MyArray integers1 then print its size and contents
   cout << "Create 7 element MyArray integers1" << endl;
   MyArray integers1(7); // seven-element MyArray
   cout << "Size of MyArray integers1 is "
      << integers1.getSize()
      << "\nintegers1 contains: " << integers1;

   // input and print integers1 
   cout << "\nEnter 7 integers:" << endl;
   cin >> integers1;
   cout << "\nAfter input integers1 contains: " << integers1;

   // create MyArray integers2 using integers1 as an
   // initializer; print size and contents
   cout << "\nCreate MyArray integers2 as a copy of integers1" << endl;
   MyArray integers2(integers1); // invokes copy constructor

   cout << "Size of MyArray integers2 is "
      << integers2.getSize()
      << "\nintegers2 contains: " << integers2;

   // create MyArray integers3 using the contents of the MyArray 
   // returned by getArrayByValue; print size and contents
   cout << "\nCreate MyArray integers3 and initialize it with the "
      << "\nrvalue MyArray returned by getArrayByValue" << endl;
   MyArray integers3(getArrayByValue()); // invokes move constructor

   cout << "Size of MyArray integers3 is "
      << integers3.getSize()
      << "\nintegers3 contains: " << integers3;

   // convert integers3 to an rvalue reference with std::move and
   // use the result to initialize MyArray integers4
   cout << "\nCreate MyArray integers4 and initialize it with the "
      << "\nrvalue reference returned by std::move" << endl;
   MyArray integers4(std::move(integers3)); // invokes move constructor

   cout << "Size of MyArray integers4 is "
      << integers4.getSize()
      << "\nintegers4 contains: " << integers4;

   cout << "After moving integers3 to integers4, size of integers3 is "
      << integers3.getSize()
      << "\nintegers3 contains: " << integers3;

   // copy contents of integers4 into integers3
   cout << "\nUse copy assignment to copy contents "
      << "of integers4 into integers3" << endl;
   integers3 = integers4; // invokes copy constructor

   cout << "After assigning integers4 to integers3, "
      << "\nsize of MyArray integers3 is "
      << integers3.getSize()
      << "\nintegers3 contains: " << integers3;

   // move contents of integers4 into integers1
   cout << "\nUse move assignment to move contents "
      << "of integers4 into integers1" << endl;
   integers1 = std::move(integers4); // invokes move assignment

   cout << "Size of MyArray integers1 is "
      << integers1.getSize()
      << "\nintegers1 contains: " << integers1;

   cout << "After moving integers4 to integers1, size of integers4 is "
      << integers4.getSize()
      << "\nintegers4 contains: " << integers4;
}



/**************************************************************************
 * (C) Copyright 1992-2021 by Deitel & Associates, Inc. and               *
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
