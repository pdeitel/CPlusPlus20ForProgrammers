// fig10_45.cpp
// Driver for multiple-inheritance example.
#include <iostream>
#include <fmt/format.h> // In C++20, this will be #include <format> 
#include "Base1.h"
#include "Base2.h"
#include "Derived.h"
using namespace std;

int main() {
   Base1 base1{10}; // create Base1 object
   Base2 base2{'Z'}; // create Base2 object
   Derived derived{7, 'A', 3.5}; // create Derived object

   // print data members of base-class objects
   cout << fmt::format("{}: {}\n{}: {}\n{}: {}\n\n",
              "Object base1 contains", base1.getData(),
              "Object base2 contains the character", base2.getData(),
              "Object derived contains", derived.toString());

   // print data members of derived-class object
   // scope resolution operator resolves getData ambiguity
   cout << fmt::format("{}\n{}: {}\n{}: {}\n{}: {}\n\n", 
              "Data members of Derived can be accessed individually:", 
              "int", derived.Base1::getData(),  
              "char", derived.Base2::getData(), 
              "double", derived.getReal());

   cout << "Derived can be treated as an object of either base class:\n";

   // treat Derived as a Base1 object
   Base1* base1Ptr = &derived;
   cout << fmt::format("base1Ptr->getData() yields {}\n", 
              base1Ptr->getData());

   // treat Derived as a Base2 object
   Base2* base2Ptr = &derived;
   cout << fmt::format("base2Ptr->getData() yields {}\n",
              base2Ptr->getData());
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
