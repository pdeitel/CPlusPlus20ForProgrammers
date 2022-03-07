// fig12_08.cpp
// Division by zero with a precondition.
#include <iostream>

double quotient(double numerator, double denominator) 
   [[pre: denominator != 0.0]];

int main() {
   std::cout << "quotient(100, 7): " << quotient(100, 7)
      << "\nquotient(100, 0): " << quotient(100, 0) << '\n';
} 

// perform division 
double quotient(double numerator, double denominator) {
   return numerator / denominator;
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
