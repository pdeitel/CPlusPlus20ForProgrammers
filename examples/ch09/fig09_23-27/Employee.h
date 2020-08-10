// Fig. 9.25: Employee.h
// Employee class definition showing composition.
// Member functions defined in Employee.cpp.
#pragma once // prevent multiple inclusions of header
#include <string>
#include <string_view>
#include "Date.h" // include Date class definition

class Employee {
public:
   Employee(std::string_view firstName, std::string_view lastName,
      const Date& birthDate, const Date& hireDate);
   std::string toString() const;
   ~Employee(); // provided to confirm destruction order
private:
   const std::string m_firstName; // composition: member object
   const std::string m_lastName; // composition: member object
   const Date m_birthDate; // composition: member object
   const Date m_hireDate; // composition: member object
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
