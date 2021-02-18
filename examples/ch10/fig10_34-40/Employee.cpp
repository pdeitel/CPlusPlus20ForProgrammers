// Fig. 10.39: Employee.cpp
// Class Employee member-function definitions.
#include <string> 
#include <fmt/format.h> // In C++20, this will be #include <format> 
#include "Employee.h" 
using namespace std;

// constructor 
Employee::Employee(string_view name, CompensationModel model)
   : m_name{name}, m_model{model} {}

// change the Employee's CompensationModel
void Employee::setCompensationModel(CompensationModel model) {
   m_model = model;
}

// return the Employee's earnings
double Employee::earnings() const {
   auto getEarnings = [](const auto& model){return model.earnings();};
   return std::visit(getEarnings, m_model);
}

// return string representation of an Employee object        
string Employee::toString() const {                       
   auto getString = [](const auto& model){return model.toString();};
   return fmt::format("{}\n{}", m_name, std::visit(getString, m_model));
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
