// fig07_02.cpp
// Pass-by-value used to cube a variable's value.
#include <fmt/format.h>
#include <iostream>

int cubeByValue(int n); // prototype 

int main() {
   int number{5};

   std::cout << fmt::format("Original value of number is {}\n", number);
   number = cubeByValue(number); // pass number by value to cubeByValue
   std::cout << fmt::format("New value of number is {}\n", number);
}

// calculate and return cube of integer argument                
int cubeByValue(int n) {
   return n * n * n; // cube local variable n and return result 
}



/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
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
