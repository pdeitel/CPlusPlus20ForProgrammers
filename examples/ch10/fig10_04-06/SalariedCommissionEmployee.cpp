// Fig. 10.5: SalariedCommissionEmployee.cpp
// Class SalariedCommissionEmployee member-function definitions.
#include <fmt/format.h> // In C++20, this will be #include <format> 
#include <stdexcept>
#include "SalariedCommissionEmployee.h"
using namespace std;

// constructor
SalariedCommissionEmployee::SalariedCommissionEmployee(string_view name,
   double salary, double grossSales,  double commissionRate)
   : SalariedEmployee(name, salary) { // call base-class constructor 

   setGrossSales(grossSales); // validate & store gross sales   
   setCommissionRate(commissionRate); // validate & store commission rate
}                                                              

// set gross sales amount
void SalariedCommissionEmployee::setGrossSales(double grossSales) {
   if (grossSales < 0.0) {
      throw invalid_argument("Gross sales must be >= 0.0");
   } 

   m_grossSales = grossSales;
} 

// return gross sales amount
double SalariedCommissionEmployee::getGrossSales() const {
   return m_grossSales;
}

// set commission rate
void SalariedCommissionEmployee::setCommissionRate(
   double commissionRate) {

   if (commissionRate <= 0.0 || commissionRate >= 1.0) {
      throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
   } 

   m_commissionRate = commissionRate;
} 

// get commission rate
double SalariedCommissionEmployee::getCommissionRate() const {
   return m_commissionRate;
}

// calculate earnings--uses SalariedEmployee::earnings()
double SalariedCommissionEmployee::earnings() const {
   return SalariedEmployee::earnings() + 
      getGrossSales() * getCommissionRate();
} 

// returns string representation of SalariedCommissionEmployee object
string SalariedCommissionEmployee::toString() const {
   return fmt::format(
      "{}gross sales: ${:.2f}\ncommission rate: {:.2f}\n",
      SalariedEmployee::toString(), getGrossSales(), getCommissionRate());
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
