// fig08_11.cpp
// Reading and printing a sequential file.
#include <cstdlib> 
#include <fmt/format.h> 
#include <fstream> // file stream        
#include <iostream>
#include <string>

int main() {
   // ifstream opens the file          
   if (std::ifstream input{"clients.txt", std::ios::in}) {
      std::cout << fmt::format("{:<10}{:<13}{:>7}\n",
         "Account", "Name", "Balance");

      int account;
      std::string name;
      double balance;

      // display each record in file
      while (input >> account >> name >> balance) {
         std::cout << fmt::format("{:<10}{:<13}{:>7.2f}\n",
            account, name, balance);
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
