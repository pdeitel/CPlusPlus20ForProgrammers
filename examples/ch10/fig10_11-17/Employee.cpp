// Fig. 10.12: Employee.cpp
// Abstract-base-class Employee member-function definitions.
// Note: No definitions are given for pure virtual functions.
#include <fmt/format.h> // In C++20, this will be #include <format> 
#include "Employee.h" // Employee class definition
using namespace std;

// constructor                                                        
Employee::Employee(string_view name) : m_name{name} {} // empty body

// set name
void Employee::setName(string_view name) {m_name = name;}

// return string representation of an Employee
string Employee::toString() const {                       
   return fmt::format("name: {}", m_name);
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
