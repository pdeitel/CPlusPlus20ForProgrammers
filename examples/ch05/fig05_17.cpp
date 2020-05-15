// fig05_17.cpp
// Recursive function fibonacci.
#include <iostream>
using namespace std;

long fibonacci(long number); // function prototype

int main() {
   // calculate the fibonacci values of 0 through 10
   for (int counter{0}; counter <= 10; ++counter)
      cout << "fibonacci(" << counter << ") = "
         << fibonacci(counter) << endl;

   // display higher fibonacci values
   cout << "\nfibonacci(20) = " << fibonacci(20) << endl;
   cout << "fibonacci(30) = " << fibonacci(30) << endl;
   cout << "fibonacci(35) = " << fibonacci(35) << endl;
}

// recursive function fibonacci                            
long fibonacci(long number) {
   if ((0 == number) || (1 == number)) { // base cases     
      return number;
   }
   else { // recursion step                                
      return fibonacci(number - 1) + fibonacci(number - 2);
   }
}


/*************************************************************************
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
*************************************************************************/
