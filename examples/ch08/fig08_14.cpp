// fig08_14.cpp
// Reading from a CSV file.
#include <fmt/format.h> 
#include <iostream>
#include <rapidcsv.h> 
#include <vector>

int main() {
   rapidcsv::Document document{"accounts.csv"}; // loads accounts.csv
   std::vector<int> accounts{document.GetColumn<int>("account")};
   std::vector<std::string> names{
      document.GetColumn<std::string>("name")};
   std::vector<double> balances{document.GetColumn<double>("balance")};

   std::cout << fmt::format(
      "{:<10}{:<13}{:>7}\n", "Account", "Name", "Balance");

   for (size_t i{0}; i < accounts.size(); ++i) {
      std::cout << fmt::format("{:<10}{:<13}{:>7.2f}\n",
         accounts.at(i), names.at(i), balances.at(i));
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
