// fig06_14.cpp
// Demonstrating C++ standard library class template vector.
#include <iostream>
#include <vector>   
#include <stdexcept>
using namespace std;

void outputVector(const vector<int>& items); // display the vector
void inputVector(vector<int>& items); // input values into the vector

int main() {
   vector<int> integers1(7); // 7-element vector<int>  
   vector<int> integers2(10); // 10-element vector<int>

   // print integers1 size and contents
   cout << "Size of vector integers1 is " << integers1.size()
      << "\nvector after initialization: ";
   outputVector(integers1);

   // print integers2 size and contents
   cout << "\nSize of vector integers2 is " << integers2.size()
      << "\nvector after initialization: ";
   outputVector(integers2);

   // input and print integers1 and integers2
   cout << "\nEnter 17 integers:" << endl;
   inputVector(integers1);
   inputVector(integers2);

   cout << "\nAfter input, the vectors contain:\n" 
      << "integers1: ";
   outputVector(integers1);
   cout << "integers2: ";
   outputVector(integers2);

   // use inequality (!=) operator with vector objects
   cout << "\nEvaluating: integers1 != integers2" << endl;

   if (integers1 != integers2) {
      cout << "integers1 and integers2 are not equal" << endl;
   }

   // create vector integers3 using integers1 as an         
   // initializer; print size and contents                  
   vector<int> integers3{integers1}; // copy constructor

   cout << "\nSize of vector integers3 is " << integers3.size()
      << "\nvector after initialization: ";
   outputVector(integers3);

   // use overloaded assignment (=) operator              
   cout << "\nAssigning integers2 to integers1:" << endl;
   integers1 = integers2; // assign integers2 to integers1

   cout << "integers1: ";
   outputVector(integers1);
   cout << "integers2: ";
   outputVector(integers2);

   // use equality (==) operator with vector objects
   cout << "\nEvaluating: integers1 == integers2" << endl;

   if (integers1 == integers2) {
      cout << "integers1 and integers2 are equal" << endl;
   }

   // use the value at location 5 as an rvalue
   cout << "\nintegers1.at(5) is " << integers1.at(5);

   // use integers1.at(5) as an lvalue
   cout << "\n\nAssigning 1000 to integers1.at(5)" << endl;
   integers1.at(5) = 1000;
   cout << "integers1: ";
   outputVector(integers1);

   // attempt to use out-of-range index                     
   try {
      cout << "\nAttempt to display integers1.at(15)" << endl;
      cout << integers1.at(15) << endl; // ERROR: out of range
   }
   catch (const out_of_range& ex) {
      cerr << "An exception occurred: " << ex.what() << endl;
   }

   // changing the size of a vector
   cout << "\nCurrent integers3 size is: " << integers3.size() << endl;
   integers3.push_back(1000); // add 1000 to the end of the vector
   cout << "New integers3 size is: " << integers3.size() << endl;
   cout << "integers3 now contains: ";
   outputVector(integers3);
}

// output vector contents
void outputVector(const vector<int>& items) {
   for (const int item : items) {
      cout << item << " ";
   }

   cout << endl;
}

// input vector contents
void inputVector(vector<int>& items) {
   for (int& item : items) {
      cin >> item;
   }
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
