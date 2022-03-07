// Fig. 10.24: CommissionEmployee.cpp
// CommissionEmployee class member-function definitions.
#include <fmt/format.h>
#include <stdexcept>
#include "CommissionEmployee.h" // CommissionEmployee class definition

// constructor                                                        
CommissionEmployee::CommissionEmployee(std::string_view name, 
   double grossSales, double commissionRate) : Employee{name} {
   setGrossSales(grossSales); 
   setCommissionRate(commissionRate); 
}                                      

// set gross sales amount
void CommissionEmployee::setGrossSales(double grossSales) {
   if (grossSales < 0.0) {
      throw std::invalid_argument("Gross sales must be >= 0.0");
   } 

   m_grossSales = grossSales;
} 

// return gross sales amount
double CommissionEmployee::getGrossSales() const {return m_grossSales;}

// set commission rate
void CommissionEmployee::setCommissionRate(double commissionRate) {
   if (commissionRate <= 0.0 || commissionRate >= 1.0) {
      throw std::invalid_argument(
         "Commission rate must be > 0.0 and < 1.0");
   } 

   m_commissionRate = commissionRate;
} 

// return commission rate
double CommissionEmployee::getCommissionRate() const {
   return m_commissionRate;
} 

// calculate earnings                        
double CommissionEmployee::getPay() const {
   return getGrossSales() * getCommissionRate();
}                                            

// return string representation of CommissionEmployee object        
std::string CommissionEmployee::getString() const {                       
   return fmt::format(
      "{}\n{}: ${:.2f}\n{}: {:.2f}", Employee::getString(),
      "gross sales", getGrossSales(),
      "commission rate", getCommissionRate()); 
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
