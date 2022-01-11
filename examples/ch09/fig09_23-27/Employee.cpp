// Fig. 9.26: Employee.cpp
// Employee class member-function definitions.
#include <fmt/format.h>
#include <iostream>
#include "Employee.h" // Employee class definition
using namespace std;

// constructor uses member initializer list to pass initializer 
// values to constructors of member objects 
Employee::Employee(std::string_view firstName, std::string_view lastName,
   const Date& birthDate, const Date& hireDate)
   : m_firstName{firstName}, m_lastName{lastName},
   m_birthDate{birthDate}, m_hireDate{hireDate} {
   // output Employee object to show when constructor is called
   std::cout << fmt::format("Employee object constructor: {} {}\n",
      m_firstName, m_lastName);
}

// gets string representation of an Employee object
std::string Employee::toString() const {
   return fmt::format("{}, {}  Hired: {}  Birthday: {}", m_lastName,
      m_firstName, m_hireDate.toString(), m_birthDate.toString());
}

// output Employee object to show when its destructor is called
Employee::~Employee() {
   cout << fmt::format("Employee object destructor: {}, {}\n",
      m_lastName, m_firstName);
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
