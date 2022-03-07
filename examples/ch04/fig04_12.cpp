// fig04_12.cpp
// Compound-interest example with C++20 text formatting.
#include <iostream>
#include <cmath> // for pow function
#include "fmt/format.h" // in C++20, this will be #include <format>
using namespace std;
using namespace fmt; // not needed in C++20

int main() {
   double principal{1000.00}; // initial amount before interest
   double rate{0.05}; // interest rate

   cout << format("Initial principal: {:>7.2f}\n", principal)
        << format("    Interest rate: {:>7.2f}\n", rate);

   // display headers
   cout << format("\n{}{:>20}\n", "Year", "Amount on deposit");

   // calculate amount on deposit for each of ten years
   for (int year{1}; year <= 10; ++year) {
      double amount{principal * pow(1.0 + rate, year)};
      cout << format("{:>4d}{:>20.2f}\n", year, amount);
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
