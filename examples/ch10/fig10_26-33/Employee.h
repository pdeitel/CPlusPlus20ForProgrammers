// Fig. 10.27: Employee.h
// An Employee "has a" CompensationModel.
#pragma once // prevent multiple inclusions of header
#include <string> 
#include <string_view> 
#include "CompensationModel.h"

class Employee {
public:
   Employee(std::string_view name, CompensationModel* modelPtr);
   void setCompensationModel(CompensationModel *modelPtr);
   double earnings() const;
   std::string toString() const;
private:
   std::string m_name{};
   CompensationModel* m_modelPtr{}; // pointer to an implementation object
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
