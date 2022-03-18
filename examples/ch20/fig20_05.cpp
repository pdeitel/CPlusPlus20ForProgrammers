// fig20_05.cpp
// Demonstrating operators .* and ->*.
#include <iostream>

// class Test definition
class Test {
public:
   Test(int x) : value{x} {};

   void testFunction() {
      std::cout << "testFunction called\n";
   }

   int value; // public data member
};

void arrowStar(Test* ptr); // prototype
void dotStar(Test* ptr); // prototype

int main() {
   Test test{8};
   arrowStar(&test); // pass address to arrowStar
   dotStar(&test); // pass address to dotStar
}

// access member function of Test object using ->*
void arrowStar(Test* ptr) {
   auto functionPtr{&Test::testFunction}; // pointer to a member function
   (ptr->*functionPtr)(); // invoke function indirectly              
}

// access members of Test object data member using .*
void dotStar(Test* ptr) {
   auto valuePtr{&Test::value}; // pointer to a data member  
   std::cout << "value is " << (*ptr).*valuePtr << "\n"; // access value
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
