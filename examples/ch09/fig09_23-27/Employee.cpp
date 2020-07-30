// Fig. 9.26: Employee.cpp
// Employee class member-function definitions.
#include <iostream>
#include "fmt/format.h" // In C++20, this will be #include <format> 
#include "Employee.h" // Employee class definition
#include "Date.h" // Date class definition
using namespace std;

// constructor uses member initializer list to pass initializer 
// values to constructors of member objects 
Employee::Employee(const string& first, const string& last,
   const Date& dateOfBirth, const Date& dateOfHire)
   : firstName{first}, // initialize firstName      
   lastName{last}, // initialize lastName         
   birthDate{dateOfBirth}, // initialize birthDate
   hireDate{dateOfHire} { // initialize hireDate    
   // output Employee object to show when constructor is called
   cout << fmt::format("Employee object constructor: {} {}\n",
              firstName, lastName);
}

// print Employee object
string Employee::toString() const {
   return fmt::format("{}, {}  Hired: {}  Birthday: {}", lastName,
             firstName, hireDate.toString(), birthDate.toString());
}

// output Employee object to show when its destructor is called
Employee::~Employee() {
   cout << fmt::format("Employee object destructor: {}, {}\n",
              lastName, firstName);
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
