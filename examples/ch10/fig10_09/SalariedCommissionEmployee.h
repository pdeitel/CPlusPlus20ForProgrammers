// Fig. 10.4: SalariedCommissionEmployee.h
// SalariedCommissionEmployee class derived from class SalariedEmployee.
#pragma once
#include <string> 
#include <string_view> 
#include "SalariedEmployee.h" 

class SalariedCommissionEmployee : public SalariedEmployee {
public:
   SalariedCommissionEmployee(std::string_view name, double salary,
      double grossSales, double commissionRate);

   void setGrossSales(double grossSales);
   double getGrossSales() const;

   void setCommissionRate(double commissionRate);
   double getCommissionRate() const;

   double earnings() const;
   std::string toString() const;
private:
   double m_grossSales{0.0};
   double m_commissionRate{0.0};
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
