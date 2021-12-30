// fig06_14.cpp
// Demonstrating C++ standard library class template vector.
#include <iostream>
#include <vector>    
#include <stdexcept> 

void outputVector(const std::vector<int>& items); // display the vector
void inputVector(std::vector<int>& items); // input values into the vector

int main() {
   std::vector<int> integers1(7); // 7-element vector<int>  
   std::vector<int> integers2(10); // 10-element vector<int>

   // print integers1 size and contents
   std::cout << "Size of vector integers1 is " << integers1.size()
      << "\nvector after initialization:";
   outputVector(integers1);

   // print integers2 size and contents
   std::cout << "\nSize of vector integers2 is " << integers2.size()
      << "\nvector after initialization:";
   outputVector(integers2);

   // input and print integers1 and integers2
   std::cout << "\nEnter 17 integers:\n";
   inputVector(integers1);
   inputVector(integers2);

   std::cout << "\nAfter input, the vectors contain:\n"
      << "integers1:";
   outputVector(integers1);
   std::cout << "integers2:";
   outputVector(integers2);

   // use inequality (!=) operator with vector objects
   std::cout << "\nEvaluating: integers1 != integers2\n";

   if (integers1 != integers2) {
      std::cout << "integers1 and integers2 are not equal\n";
   }

   // create vector integers3 using integers1 as an     
   // initializer; print size and contents              
   std::vector integers3{integers1}; // copy constructor

   std::cout << "\nSize of vector integers3 is " << integers3.size()
      << "\nvector after initialization: ";
   outputVector(integers3);

   // use overloaded assignment (=) operator              
   std::cout << "\nAssigning integers2 to integers1:\n";
   integers1 = integers2; // assign integers2 to integers1

   std::cout << "integers1: ";
   outputVector(integers1);
   std::cout << "integers2: ";
   outputVector(integers2);

   // use equality (==) operator with vector objects
   std::cout << "\nEvaluating: integers1 == integers2\n";

   if (integers1 == integers2) {
      std::cout << "integers1 and integers2 are equal\n";
   }

   // use the value at location 5 as an rvalue
   std::cout << "\nintegers1.at(5) is " << integers1.at(5);

   // use integers1.at(5) as an lvalue
   std::cout << "\n\nAssigning 1000 to integers1.at(5)\n";
   integers1.at(5) = 1000;
   std::cout << "integers1: ";
   outputVector(integers1);

   // attempt to use out-of-range index                   
   try {
      std::cout << "\nAttempt to display integers1.at(15)\n";
      std::cout << integers1.at(15) << '\n'; // ERROR: out of range
   }
   catch (const std::out_of_range& ex) {
      std::cerr << "An exception occurred: " << ex.what() << '\n';
   }

   // changing the size of a vector
   std::cout << "\nCurrent integers3 size is: " << integers3.size();
   integers3.push_back(1000); // add 1000 to the end of the vector
   std::cout << "\nNew integers3 size is: " << integers3.size()
      << "\nintegers3 now contains: ";
   outputVector(integers3);
}

// output vector contents
void outputVector(const std::vector<int>& items) {
   for (const int& item : items) {
      std::cout << item << " ";
   }

   std::cout << '\n';
}

// input vector contents
void inputVector(std::vector<int>& items) {
   for (int& item : items) {
      std::cin >> item;
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
