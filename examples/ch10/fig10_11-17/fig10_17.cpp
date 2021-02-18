// fig10_17.cpp
// Processing Employee derived-class objects with static binding 
// then polymorphically using dynamic binding.
#include <iostream>
#include <vector>
#include <fmt/format.h> // In C++20, this will be #include <format> 
#include "Employee.h"
#include "SalariedEmployee.h" 
#include "CommissionEmployee.h"  
using namespace std;

void virtualViaPointer(const Employee* baseClassPtr); // prototype
void virtualViaReference(const Employee& baseClassRef); // prototype

int main() {
   // create derived-class objects                        
   SalariedEmployee salaried{"John Smith", 800.0};
   CommissionEmployee commission{"Sue Jones", 10000, .06};
   
   // output each Employee
   cout << "EMPLOYEES PROCESSED INDIVIDUALLY USING STATIC BINDING\n"
        << fmt::format("{}\n{}{:.2f}\n\n{}\n{}{:.2f}\n\n",
              salaried.toString(), "earned $", salaried.earnings(),
              commission.toString(), "earned $", commission.earnings());

   // create and initialize vector of base-class pointers        
   vector<Employee*> employees{&salaried, &commission};

   cout << "EMPLOYEES PROCESSED POLYMORPHICALLY VIA DYNAMIC BINDING\n\n";

   // call virtualViaPointer to print each Employee
   // and earnings using dynamic binding
   cout << "VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS POINTERS\n";

   for (const Employee* employeePtr : employees) {
      virtualViaPointer(employeePtr);             
   }                                              

   // call virtualViaReference to print each Employee
   // and earnings using dynamic binding
   cout << "VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS REFERENCES\n";

   for (const Employee* employeePtr : employees) {            
      virtualViaReference(*employeePtr); // note dereferenced pointer
   }                                                          
} 

// call Employee virtual functions toString and earnings off a   
// base-class pointer using dynamic binding                   
void virtualViaPointer(const Employee* baseClassPtr) {
   cout << fmt::format("{}\nearned ${:.2f}\n\n", 
              baseClassPtr->toString(), baseClassPtr->earnings());
}                       

// call Employee virtual functions toString and earnings off a  
// base-class reference using dynamic binding                
void virtualViaReference(const Employee& baseClassRef) {     
   cout << fmt::format("{}\nearned ${:.2f}\n\n", 
              baseClassRef.toString(), baseClassRef.earnings());
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
