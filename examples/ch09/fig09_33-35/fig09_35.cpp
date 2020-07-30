// fig09_35.cpp
// static data member tracking the number of objects of a class.
#include <iostream>
#include "fmt/format.h" // In C++20, this will be #include <format> 
#include "Employee.h" // Employee class definition
using namespace std;

int main() {
   // no objects exist; use class name and binary scope resolution 
   // operator to access static member function getCount
   cout << fmt::format("Initial employee count: {}\n",
              Employee::getCount()); // use class name

   // the following scope creates and destroys 
   // Employee objects before main terminates
   {
      const Employee e1{"Susan", "Baker"};
      const Employee e2{"Robert", "Jones"};

      // two objects exist; call static member function getCount again 
      // using the class name and the scope resolution operator
      cout << fmt::format("Employee count after creating objects: {}\n\n",
                 Employee::getCount());

      cout << fmt::format("Employee 1: {} {}\nEmployee 2: {} {}\n\n",
                 e1.getFirstName(), e1.getLastName(),
                 e2.getFirstName(), e2.getLastName());
   }

   // no objects exist, so call static member function getCount again 
   // using the class name and the scope resolution operator
   cout << fmt::format("Employee count after objects are deleted: {}\n",
              Employee::getCount());
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
