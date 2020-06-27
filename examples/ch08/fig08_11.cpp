// fig08_11.cpp
// Reading and printing a sequential file.
#include <iostream>
#include <fstream> // file stream        
#include <string>
#include <cstdlib> 
#include "fmt/format.h" // In C++20, this will be #include <format>  
using namespace std;

int main() {
   // ifstream opens the file          
   if (ifstream input{"clients.txt", ios::in}; input) {
      cout << fmt::format("{:<10}{:<13}{}\n",
                 "Account", "Name", "Balance");

      int account; 
      string name;
      double balance;

      // display each record in file
      while (input >> account >> name >> balance) {
         cout << fmt::format("{:<10}{:<13}{:>7.2f}\n",
            account, name, balance);
      }
   }
   else {
      cerr << "File could not be opened\n";
      exit(EXIT_FAILURE);
   }
}


/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
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
