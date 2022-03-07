// fig05_17.cpp
// Iterative function factorial.
#include <iostream>
#include <iomanip>
using namespace std;

long factorial(int number); // function prototype

int main() {
   // calculate the factorials of 0 through 10
   for (int counter{0}; counter <= 10; ++counter) {
      cout << setw(2) << counter << "! = " << factorial(counter) 
         << '\n';
   }
} 

// iterative method factorial
long factorial(int number) {
   long result{1};

   // iterative factorial calculation 
   for (int i{number}; i >= 1; --i) {
      result *= i;
   }

   return result;
} 



/*************************************************************************
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
