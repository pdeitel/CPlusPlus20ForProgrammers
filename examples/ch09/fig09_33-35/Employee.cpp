// Fig. 9.34: Employee.cpp
// Employee class member-function definitions.
#include <iostream>
#include "fmt/format.h" // In C++20, this will be #include <format> 
#include "Employee.h" // Employee class definition 
using namespace std;

// define and initialize static data member at global namespace scope
int Employee::count{0}; // cannot include keyword static

// define static member function that returns number of         
// Employee objects instantiated (declared static in Employee.h)
int Employee::getCount() { return count; }

// constructor initializes non-static data members and 
// increments static data member count
Employee::Employee(const string& first, const string& last)
   : firstName(first), lastName(last) {
   ++count; // increment static count of employees
   cout << fmt::format("Employee constructor called for {} {}\n",
              firstName, lastName);
}

// destructor decrements the count
Employee::~Employee() {
   cout << fmt::format("~Employee() called for {} {}\n",
              firstName, lastName);
   --count; // decrement static count of employees
}

// return first name of employee
string Employee::getFirstName() const { return firstName; }

// return last name of employee
string Employee::getLastName() const { return lastName; }

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
