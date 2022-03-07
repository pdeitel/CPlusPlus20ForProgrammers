// Fig. 10.23: CommissionEmployee.h
// CommissionEmployee class derived from Employee.
#pragma once
#include <string> 
#include <string_view> 
#include "Employee.h" // Employee class definition

class CommissionEmployee final : public Employee {
public:
   CommissionEmployee(std::string_view name, double grossSales,
      double commissionRate);
   virtual ~CommissionEmployee() = default; // virtual destructor

   void setGrossSales(double grossSales);
   double getGrossSales() const;

   void setCommissionRate(double commissionRate);
   double getCommissionRate() const;
private:
   double m_grossSales{0.0};
   double m_commissionRate{0.0};

   // keyword override signals intent to override                 
   double getPay() const override; // calculate earnings        
   std::string getString() const override; // string representation
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
