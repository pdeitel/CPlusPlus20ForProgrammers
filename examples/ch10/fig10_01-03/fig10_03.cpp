// fig10_03.cpp
// SalariedEmployee class test program.
#include <iostream>
#include <fmt/format.h> // In C++20, this will be #include <format> 
#include "SalariedEmployee.h" 
using namespace std;

int main() {
   // instantiate a SalariedEmployee object     
   SalariedEmployee employee{"Sue Jones", 300.0};
   
   // get SalariedEmployee data
   cout << "Employee information obtained by get functions:\n"
        << fmt::format("name: {}\nsalary: ${:.2f}\n", employee.getName(),
              employee.getSalary());

   employee.setSalary(500.0); // change salary      
   cout << "\nUpdated employee information from function toString:\n" 
      << employee.toString();

   // display only the employee's earnings
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
