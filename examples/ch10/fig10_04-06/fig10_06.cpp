// fig10_06.cpp
// SalariedCommissionEmployee class test program.
#include <iostream>
#include <fmt/format.h> // In C++20, this will be #include <format> 
#include "SalariedCommissionEmployee.h" 
using namespace std;

int main() {
   // instantiate SalariedCommissionEmployee object             
   SalariedCommissionEmployee employee{"Bob Lewis", 300.0, 5000.0, .04};

   // get SalariedCommissionEmployee data
   cout << "Employee information obtained by get functions:\n" 
        << fmt::format("{}: {}\n{}: ${:.2f}\n{}: ${:.2f}\n{}: {:.2f}\n",
              "name", employee.getName(), "salary", employee.getSalary(),
              "gross sales", employee.getGrossSales(),
              "commission", employee.getCommissionRate());

   employee.setGrossSales(8000.0); // change gross sales      
   employee.setCommissionRate(0.1); // change commission rate
   cout << "\nUpdated employee information from function toString:\n"
      << employee.toString();

   // display the employee
   cout << fmt::format("\nearnings: ${:.2f}\n", employee.earnings());
} 

/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
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
