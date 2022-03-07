// Fig. 10.13: SalariedEmployee.h
// SalariedEmployee class derived from Employee.
#pragma once
#include <string> // C++ standard string class
#include <string_view> 
#include "Employee.h" // Employee class definition

class SalariedEmployee final : public Employee {
public:
   SalariedEmployee(std::string_view name, double salary);
   virtual ~SalariedEmployee() = default; // virtual destructor

   void setSalary(double salary);
   double getSalary() const;

   // keyword override signals intent to override               
   double earnings() const override; // calculate earnings        
   std::string toString() const override; // string representation
private:
   double m_salary{0.0};
};


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
