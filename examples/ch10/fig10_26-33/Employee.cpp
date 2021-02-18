// Fig. 10.28: Employee.cpp
// Class Employee member-function definitions.
#include <string> 
#include <fmt/format.h> // In C++20, this will be #include <format> 
#include "CompensationModel.h"
#include "Employee.h" 
using namespace std;

// constructor performs "constructor injection" to initialize  
// the CompensationModel pointer to an CompensationModel implementation 
Employee::Employee(string_view name, CompensationModel* modelPtr)
   : m_name{name}, m_modelPtr{modelPtr} {}

// set function performs "property injection" to change the   
// CompensationModel pointer to a new CompensationModel implementation 
void Employee::setCompensationModel(CompensationModel* modelPtr) {
   m_modelPtr = modelPtr;
}

// use the CompensationModel to calculate the Employee's earnings
double Employee::earnings() const {
   return m_modelPtr->earnings();
}; 

// return string representation of an Employee object        
string Employee::toString() const {                       
   return fmt::format("{}\n{}", m_name, m_modelPtr->toString());
}            

/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
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
