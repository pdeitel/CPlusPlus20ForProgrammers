// Fig. 10.35: Salaried.cpp
// Salaried compensation model member-function definitions.
#include <fmt/format.h>
#include <stdexcept>
#include "Salaried.h" // class definition

// constructor 
Salaried::Salaried(double salary) : m_salary{salary} {
   if (m_salary < 0.0) {
      throw std::invalid_argument("Weekly salary must be >= 0.0");
   } 
} 

// calculate earnings
double Salaried::earnings() const {return m_salary;}

// return string containing Salaried compensation model information
std::string Salaried::toString() const {
   return fmt::format("salary: ${:.2f}", m_salary);
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
