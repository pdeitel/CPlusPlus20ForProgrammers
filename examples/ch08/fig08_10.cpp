// fig08_10.cpp
// Creating a sequential file.
#include <cstdlib> // exit function prototype              
#include <fmt/format.h> 
#include <fstream> // contains file stream processing types
#include <iostream>
#include <string>

int main() {
   // ofstream opens the file                
   if (std::ofstream output{"clients.txt", std::ios::out}) {
      std::cout << "Enter the account, name, and balance.\n"
         << "Enter end-of-file to end input.\n? ";

      int account;
      std::string name;
      double balance;

      // read account, name and balance from cin, then place in file
      while (std::cin >> account >> name >> balance) {
         output << fmt::format("{} {} {}\n", account, name, balance);
         std::cout << "? ";
      }
   }
   else {
      std::cerr << "File could not be opened\n";
      std::exit(EXIT_FAILURE);
   }
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
