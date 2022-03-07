// fig10_33.cpp
// Processing Employees with various CompensationModels.
#include <fmt/format.h>
#include <iostream>
#include <vector>
#include "Employee.h"
#include "Salaried.h" 
#include "Commission.h"  

int main() {
   // create CompensationModels and Employees
   Salaried salaried{800.0};
   Employee salariedEmployee{"John Smith", &salaried};

   Commission commission{10000, .06};
   Employee commissionEmployee{"Sue Jones", &commission};

   // create and initialize vector of Employees
   std::vector employees{salariedEmployee, commissionEmployee};

   // print each Employee's information and earnings 
   for (const Employee& employee : employees) {
      std::cout << fmt::format("{}\nearned: ${:.2f}\n\n",
         employee.toString(), employee.earnings());
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
