// fig10_10.cpp
// Introducing polymorphism, virtual functions and dynamic binding.
#include <iostream>
#include <fmt/format.h> // In C++20, this will be #include <format> 
#include "SalariedEmployee.h"
#include "SalariedCommissionEmployee.h" 
using namespace std;

int main() {
   // create base-class object
   SalariedEmployee salaried{"Sue Jones", 500.0};

   // create derived-class object
   SalariedCommissionEmployee salariedCommission{
      "Bob Lewis", 300.0, 5000.0, .04};

   // output objects using static binding
   cout << fmt::format("{}\n{}:\n{}\n{}\n",
              "INVOKING TOSTRING FUNCTION ON BASE-CLASS AND",
              "DERIVED-CLASS OBJECTS WITH STATIC BINDING",
              salaried.toString(), // static binding
              salariedCommission.toString()); // static binding

   cout << "INVOKING TOSTRING FUNCTION ON BASE-CLASS AND\n"
        << "DERIVED-CLASS OBJECTS WITH DYNAMIC BINDING\n\n";

   // natural: aim base-class pointer at base-class object        
   SalariedEmployee* salariedPtr{&salaried};
   cout << fmt::format("{}\n{}:\n{}\n",
              "CALLING VIRTUAL FUNCTION TOSTRING WITH BASE-CLASS POINTER",
              "TO BASE-CLASS OBJECT INVOKES BASE-CLASS FUNCTIONALITY",
              salariedPtr->toString()); // base-class version

   // natural: aim derived-class pointer at derived-class object
   SalariedCommissionEmployee* salariedCommissionPtr{&salariedCommission};
   cout << fmt::format("{}\n{}{}:\n{}\n",
              "CALLING VIRTUAL FUNCTION TOSTRING WITH DERIVED-CLASS",
              "POINTER TO DERIVED-CLASS OBJECT INVOKES DERIVED-CLASS ", 
              "FUNCTIONALITY",
              salariedCommissionPtr->toString()); // derived-class version

   // aim base-class pointer at derived-class object
   salariedPtr = &salariedCommission;

   // runtime polymorphism: invokes SalariedCommissionEmployee
   // via base-class pointer to derived-class object  
   cout << fmt::format("{}\n{}{}:\n{}\n",
              "CALLING VIRTUAL FUNCTION TOSTRING WITH BASE-CLASS POINTER",
              "TO DERIVED-CLASS OBJECT INVOKES DERIVED-CLASS ",
              "FUNCTIONALITY",
              salariedPtr->toString()); // derived-class version
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
