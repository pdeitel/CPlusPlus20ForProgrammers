// fig10_09.cpp
// Attempting to call derived-class-only functions
// via a base-class pointer.
#include <string>
#include "SalariedEmployee.h"
#include "SalariedCommissionEmployee.h"

int main() {
   SalariedCommissionEmployee salariedCommission{
      "Bob Lewis", 300.0, 5000.0, .04};
   
   // aim base-class pointer at derived-class object (allowed)
   SalariedEmployee* salariedPtr{&salariedCommission};

   // invoke base-class member functions on derived-class
   // object through base-class pointer (allowed)
   std::string name{salariedPtr->getName()};
   double salary{salariedPtr->getSalary()};        
   
   // attempt to invoke derived-class-only member functions          
   // on derived-class object through base-class pointer (disallowed)
   double grossSales{salariedPtr->getGrossSales()};  
   double commissionRate{salariedPtr->getCommissionRate()}; 
   salariedPtr->setGrossSales(8000.0);                      
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
