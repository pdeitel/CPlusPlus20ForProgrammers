// Fig. 10.22: SalariedEmployee.cpp
// SalariedEmployee class member-function definitions.
#include <stdexcept>
#include <fmt/format.h> // In C++20, this will be #include <format> 
#include "SalariedEmployee.h" // SalariedEmployee class definition
using namespace std;

// constructor 
SalariedEmployee::SalariedEmployee(string_view name, double salary)
   : Employee{name} {
   setSalary(salary); 
} 

// set salary
void SalariedEmployee::setSalary(double salary) {
   if (salary < 0.0) {
      throw invalid_argument("Weekly salary must be >= 0.0");
   } 

   m_salary = salary;
} 

// return salary
double SalariedEmployee::getSalary() const {return m_salary;}

// calculate earnings; 
// override pure virtual function getPay in Employee
double SalariedEmployee::getPay() const {return getSalary();}

// return a string representation of SalariedEmployee
string SalariedEmployee::getString() const {
   return fmt::format("{}\n{}: ${:.2f}", Employee::getString(), 
             "salary", getSalary());
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
