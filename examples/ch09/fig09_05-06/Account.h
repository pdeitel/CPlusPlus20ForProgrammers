// Fig. 9.5: Account.h
// Account class with m_name and m_balance data members, and a 
// constructor and deposit function that each perform validation.
#include <string>
#include <string_view>

class Account {
public:
   // Account constructor with two parameters  
   Account(std::string_view name, double balance)
      : m_name{name} { // member initializer for m_name  

      // validate that balance is greater than 0.0; if not,  
      // data member m_balance keeps its default initial value of 0.0     
      if (balance > 0.0) { // if the balance is valid     
         m_balance = balance; // assign it to data member m_balance  
      }
   }

   // function that deposits (adds) only a valid amount to the balance
   void deposit(double amount) {
      if (amount > 0.0) { // if the amount is valid
         m_balance += amount; // add it to m_balance      
      }
   }

   // function returns the account balance
   double getBalance() const {
      return m_balance;
   }

   // function that sets the account name
   void setName(std::string_view name) {
      m_name = name; // replace m_name's value with name
   }

   // function that returns the account name
   const std::string& getName() const {
      return m_name;
   }
private:
   std::string m_name; // account name data member 
   double m_balance{0.0}; // data member with default initial value
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
