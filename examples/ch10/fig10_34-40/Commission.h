// Fig. 10.36: Commission.h
// Commission compensation model.
#pragma once
#include <string> 

class Commission {
public:
   Commission(double grossSales, double commissionRate);
   double earnings() const;        
   std::string toString() const; 
private:
   double m_grossSales{0.0};      
   double m_commissionRate{0.0}; 
}; 



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
