// fig20_03.cpp
// Demonstrating namespaces.
#include <fmt/format.h>
#include <iostream>

int integer1{98}; // global variable

// create namespace Example                           
namespace Example {
   // declare two constants and one variable          
   const double pi{3.14159};
   const double e{2.71828};
   int integer1{8};

   void printValues(); // prototype                   

   // nested namespace                                
   namespace Inner {
      // define enumeration                           
      enum Years { fiscal1 = 2020, fiscal2, fiscal3 };
   }
}

// create unnamed namespace                           
namespace {
   double doubleInUnnamed{88.22}; // declare variable
}

int main() {
   // output value doubleInUnnamed of unnamed namespace
   std::cout << fmt::format("doubleInUnnamed = {}\n", doubleInUnnamed);

   // output global variable
   std::cout << fmt::format("(global) integer1 = {}\n", integer1);

   // output values of Example namespace
   std::cout << fmt::format(
      "pi = {}\ne = {}\ninteger1 = {}\nfiscal3 = {}\n", Example::pi,
      Example::e, Example::integer1, Example::Inner::fiscal3);

   Example::printValues(); // invoke printValues function
}

// display variable and constant values
void Example::printValues() {
   std::cout << "\nIn printValues:\n";
   std::cout << fmt::format(
      "integer1 = {}\npi = {}\ne = {}\n", pi, e, integer1);
   std::cout << fmt::format(
      "doubleInUnnamed = {}\n(global) integer1 = {}\nfiscal3 = {}\n",
      doubleInUnnamed, ::integer1, Inner::fiscal3);
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
