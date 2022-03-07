// fig03_06.cpp
// C++20 string formatting.
#include <iostream>
#include <fmt/format.h> // C++20: This will be #include <format>
using namespace std;
using namespace fmt; // not needed in C++20

int main() {
   string student{"Paul"};
   int grade{87};

   cout << format("{}'s grade is {}\n", student, grade);
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
