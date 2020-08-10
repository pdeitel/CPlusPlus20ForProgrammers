// Fig. 9.3: Account.h
// Account class with a constructor that initializes the account name.
#include <string>
#include <string_view>

class Account {
public:
   // constructor initializes data member m_name with the parameter name
   explicit Account(std::string_view name)
      : m_name{name} { // member initializer  
     // empty body                                 
   }

   // function to set the account name
   void setName(std::string_view name) {
      m_name = name; // replace m_name's value with name
   }

   // function to retrieve the account name
   const std::string& getName() const {
      return m_name;
   }
private:
   std::string m_name; // account name data member
}; // end class Account



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
 *************************************************************************/
