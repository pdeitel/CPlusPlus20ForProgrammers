// Fig. 9.33: Employee.h
// Employee class definition with a static data member to 
// track the number of Employee objects in memory
#pragma once
#include <string>
#include <string_view>

class Employee {
public:
   Employee(std::string_view firstName, std::string_view lastName);
   ~Employee(); // destructor
   const std::string& getFirstName() const; // return first name
   const std::string& getLastName() const; // return last name

   // static member function                                          
   static int getCount(); // return # of objects instantiated
private:
   const std::string m_firstName;
   const std::string m_lastName;

   // static data
   inline static int m_count{0}; // number of objects instantiated
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
