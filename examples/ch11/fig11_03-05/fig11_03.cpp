// fig11_03.cpp
// MyArray class test program.
#include <iostream>
#include <stdexcept>
#include <utility> // for std::move
#include "MyArray.h"
using namespace std;

// function to return a MyArray by value
MyArray getArrayByValue() {
   MyArray localInts{10, 20, 30}; // create three-element MyArray
   return localInts; // return by value creates an rvalue
}

int main() {
   MyArray ints1(7); // 7-element MyArray; note () rather than {}
   MyArray ints2(10); // 10-element MyArray; note () rather than {}

   // print ints1 size and contents
   cout << "\nints1 size: " << ints1.size()
      << "\ncontents: " << ints1; // uses overloaded <<

   // print ints2 size and contents
   cout << "\n\nints2 size: " << ints2.size()
      << "\ncontents: " << ints2; // uses overloaded <<

   // input and print ints1 and ints2
   cout << "\n\nEnter 17 integers: ";
   cin >> ints1 >> ints2; // uses overloaded >>

   cout << "\nints1: " << ints1 << "\nints2: " << ints2;

   // use overloaded inequality (!=) operator
   cout << "\n\nEvaluating: ints1 != ints2\n";

   if (ints1 != ints2) {
      cout << "ints1 and ints2 are not equal\n\n";
   }

   // create MyArray ints3 by copying ints1      
   MyArray ints3{ints1}; // invokes copy constructor 

   // print ints3 size and contents                
   cout << "\nints3 size: " << ints3.size() << "\ncontents: " << ints3;

   // use overloaded copy assignment (=) operator
   cout << "\n\nAssigning ints2 to ints1:\n";
   ints1 = ints2; // note target MyArray is smaller

   cout << "\nints1: " << ints1 << "\nints2: " << ints2;

   // use overloaded equality (==) operator
   cout << "\n\nEvaluating: ints1 == ints2\n";

   if (ints1 == ints2) {
      cout << "ints1 and ints2 are equal\n\n";
   }

   // use overloaded subscript operator to create an rvalue
   cout << "ints1[5] is " << ints1[5];

   // use overloaded subscript operator to create an lvalue
   cout << "\n\nAssigning 1000 to ints1[5]\n";
   ints1[5] = 1000;
   cout << "ints1: " << ints1;

   // attempt to use out-of-range subscript
   try {                                                              
      cout << "\n\nAttempt to assign 1000 to ints1[15]\n";
      ints1[15] = 1000; // ERROR: subscript out of range
   } 
   catch (const out_of_range& ex) {                                       
      cout << "An exception occurred: " << ex.what() << "\n";
   } 

   // initialize ints4 with contents of the MyArray returned by 
   // getArrayByValue; print size and contents
   cout << "\nInitialize ints4 with temporary MyArray object\n";
   MyArray ints4{getArrayByValue()}; 

   cout << "\nints4 size: " << ints4.size() << "\ncontents: " << ints4;

   // convert ints4 to an rvalue reference with std::move and
   // use the result to initialize MyArray ints5
   cout << "\n\nInitialize ints5 with the result of std::move(ints4)\n";
   MyArray ints5{std::move(ints4)}; // invokes move constructor

   cout << "\nints5 size: " << ints5.size() << "\ncontents: " << ints5;
   cout << "\n\nSize of ints4 is now: " << ints4.size();

   // move contents of ints5 into ints4
   cout << "\n\nMove ints5 into ints4 via move assignment\n";
   ints4 = std::move(ints5); // invokes move assignment

   cout << "\nints4 size: " << ints4.size() << "\ncontents: " << ints4;
   cout << "\n\nSize of ints5 is now: " << ints5.size();

   // check if ints5 is empty by contextually converting it to a bool
   if (ints5) {
      cout << "\n\nints5 contains elements\n";
   }
   else {
      cout << "\n\nints5 is empty\n";
   }

   // add one to every element of ints4 using preincrement
   cout << "\nints4: " << ints4;
   cout << "\npreincrementing ints4: " << ++ints4;

   // add one to every element of ints4 using postincrement
   cout << "\n\npostincrementing ints4: " << ints4++ << "\n";
   cout << "\nints4 now contains: " << ints4;

   // add a value to every element of ints4 using +=
   cout << "\n\nAdd 7 to every ints4 element: " << (ints4 += 7) << "\n\n";
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
