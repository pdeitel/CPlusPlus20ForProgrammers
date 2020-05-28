// fig06_01.cpp
// Initializing an array's elements to zeros and printing the array.
#include "fmt/format.h" // C++20: This will be #include <format>
#include <iostream>
#include <array>
using namespace std;

int main() {
   array<int, 5> n; // n is an array of 5 int values

   // initialize elements of array n to 0        
   for (size_t i{0}; i < n.size(); ++i) {
      n[i] = 0; // set element at location i to 0
   }

   cout << fmt::format("{}{:>10}\n", "Element", "Value");

   // output each array element's value                
   for (size_t i{0}; i < n.size(); ++i) {
      cout << fmt::format("{:>7}{:>10}\n", i, n[i]);
   }

   cout << fmt::format("\n{}{:>10}\n", "Element", "Value");

   // access elements via the at member function                
   for (size_t i{0}; i < n.size(); ++i) {
      cout << fmt::format("{:>7}{:>10}\n", i, n.at(i));
   }

   // accessing an element outside the array's bounds with at
   cout << n.at(10) << endl;
}

/**************************************************************************
 * (C) Copyright 1992-2020 by Deitel & Associates, Inc. and               *
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
