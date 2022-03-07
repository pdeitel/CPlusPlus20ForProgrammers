// fig19_07.cpp 
// Controlling precision of floating-point values.
#include <iomanip>      
#include <iostream>
#include <cmath> 

int main() {
   double root2{std::sqrt(2.0)}; // calculate square root of 2

   std::cout << "Square root of 2 with precisions 0-9.\n"
      << "Precision set by ostream member function precision:\n";
   std::cout << std::fixed; // use fixed-point notation

   // display square root using ostream function precision
   for (int places{0}; places <= 9; ++places) {
      std::cout.precision(places);
      std::cout << root2 << "\n";
   } 

   std::cout << "\nPrecision set by stream manipulator setprecision:\n"; 

   // set precision for each digit, then display square root
   for (int places{0}; places <= 9; ++places) {
      std::cout << std::setprecision(places) << root2 << "\n";
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
