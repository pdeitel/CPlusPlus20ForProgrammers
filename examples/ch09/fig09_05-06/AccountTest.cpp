// Fig. 9.6: AccountTest.cpp
// Displaying and updating Account balances.
#include <iostream>
#include <fmt/format.h> // In C++20, this will be #include <format> 
#include "Account.h"

using namespace std;

int main() {
   Account account1{"Jane Green", 50.00};
   Account account2{"John Blue", -7.00};

   // display initial balance of each object
   cout << fmt::format("account1: {} balance is ${:.2f}\n",
      account1.getName(), account1.getBalance());
   cout << fmt::format("account2: {} balance is ${:.2f}\n\n",
      account2.getName(), account2.getBalance());

   cout << "Enter deposit amount for account1: "; // prompt
   double amount;
   cin >> amount; // obtain user input
   cout << fmt::format("adding ${:.2f} to account1 balance", amount);
   account1.deposit(amount); // add to account1's balance

   // display balances
   cout << fmt::format("\n\naccount1: {} balance is ${:.2f}\n",
      account1.getName(), account1.getBalance());
   cout << fmt::format("account2: {} balance is ${:.2f}\n\n",
      account2.getName(), account2.getBalance());

   cout << "Enter deposit amount for account2: "; // prompt
   cin >> amount; // obtain user input
   cout << fmt::format("adding ${:.2f} to account2 balance", amount);
   account2.deposit(amount); // add to account2 balance

   // display balances
   cout << fmt::format("\n\naccount1: {} balance is ${:.2f}\n",
      account1.getName(), account1.getBalance());
   cout << fmt::format("account2: {} balance is ${:.2f}\n",
      account2.getName(), account2.getBalance());
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
 *************************************************************************/
