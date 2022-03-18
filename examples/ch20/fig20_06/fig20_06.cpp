// fig20_06.cpp
// Demonstrating downcasting and runtime type information (RTTI). 
#include <fmt/format.h> 
#include <iostream>
#include <typeinfo>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h" 
#include "CommissionEmployee.h"  

int main() {
   // create derived-class objects                        
   SalariedEmployee salaried{"John Smith", 800.0}; 
   CommissionEmployee commission{"Sue Jones", 10000.0, .06};

   // create and initialize vector of base-class pointers        
   std::vector<Employee*> employees{&salaried, &commission};
 
   // polymorphically process each element in vector employees
   for (Employee* employeePtr : employees) {
      std::cout << fmt::format("{}\n", employeePtr->toString());

      // determine whether employeePtr points to a SalariedEmployee; 
      // if not, dynamic_cast returns nullptr which evaluates to false
      if (auto ptr{dynamic_cast<SalariedEmployee*>(employeePtr)}) {
         double oldBaseSalary = ptr->getSalary();
         std::cout << fmt::format("old salary: ${:.2f}\n", oldBaseSalary);
         ptr->setSalary(1.10 * oldBaseSalary);
         std::cout << fmt::format(
            "new salary with 10% increase is: ${:.2f}\n",
            ptr->getSalary());
      } 
      
      std::cout << fmt::format("earned ${:.2f}\n\n", 
         employeePtr->earnings());
   } 
 
   // display each object’s type
   for (const Employee* employeePtr : employees) {
      std::cout << fmt::format("{}\n", typeid(*employeePtr).name());
   } 
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
