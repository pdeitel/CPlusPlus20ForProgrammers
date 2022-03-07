// fig04_10.cpp
// Logical operators.
#include <iostream>
#include <fmt/format.h>
using namespace std;
using namespace fmt;

int main() {
   // create truth table for && (logical AND) operator
   cout << "Logical AND (&&)\n"
      << format("false && false: {}\n", false && false)
      << format("false && true: {}\n", false && true)
      << format("true && false: {}\n", true && false)
      << format("true && true: {}\n\n", true && true);

   // create truth table for || (logical OR) operator
   cout << "Logical OR (||)\n"
      << format("false || false: {}\n", false || false)
      << format("false || true: {}\n", false || true)
      << format("true || false: {}\n", true || false)
      << format("true || true: {}\n\n", true || true);

   // create truth table for ! (logical negation) operator
   cout << "Logical negation (!)\n"
      << format("!false: {}\n", !false)
      << format("!true: {}\n", !true);
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
 *************************************************************************/
