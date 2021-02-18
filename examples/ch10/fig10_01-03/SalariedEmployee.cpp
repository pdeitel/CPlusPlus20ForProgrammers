// Fig. 10.2: SalariedEmployee.cpp
// Class SalariedEmployee member-function definitions.
#include <stdexcept>
#include <fmt/format.h> // In C++20, this will be #include <format> 
#include "SalariedEmployee.h" // SalariedEmployee class definition
using namespace std;

// constructor                                                        
SalariedEmployee::SalariedEmployee(string_view name, double salary)
   : m_name{name} {
   setSalary(salary); 
}                                                                     

// set name
void SalariedEmployee::setName(string_view name) {
   m_name = name; // should validate
} 

// return name
string SalariedEmployee::getName() const {return m_name;}

// set salary
void SalariedEmployee::setSalary(double salary) {
   if (salary < 0.0) {                                       
      throw invalid_argument("Salary must be >= 0.0");       
   } 

   m_salary = salary;                                     
} 

// return salary
double SalariedEmployee::getSalary() const {return m_salary;}

// calculate earnings                        
double SalariedEmployee::earnings() const {
   return getSalary();       
}                                            

// return string representation of SalariedEmployee object        
string SalariedEmployee::toString() const { 
   return fmt::format("name: {}\nsalary: ${:.2f}\n", getName(), 
             getSalary());
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
