// fig12_02.cpp
// Example that throws an exception on 
// an attempt to divide by zero.
#include <iostream>
#include "DivideByZeroException.h" // DivideByZeroException class 
using namespace std;

// perform division and throw DivideByZeroException object if 
// divide-by-zero exception occurs
double quotient(double numerator, double denominator) {
   // throw DivideByZeroException if trying to divide by zero
   if (denominator == 0.0) {
      throw DivideByZeroException{}; // terminate function
   }

   // return division result
   return numerator / denominator;
}

int main() {
   int number1{0}; // user-specified numerator
   int number2{0}; // user-specified denominator

   cout << "Enter two integers (end-of-file to end): ";

   // enable user to enter two integers to divide
   while (cin >> number1 >> number2) {
      // try block contains code that might throw exception       
      // and code that will not execute if an exception occurs    
      try {                                                       
         double result{quotient(number1, number2)};               
         cout << "The quotient is: " << result << '\n';           
      }
      catch (const DivideByZeroException& divideByZeroException) {
         cout << "Exception occurred: "                           
            << divideByZeroException.what() << '\n';              
      }

      cout << "\nEnter two integers (end-of-file to end): ";
   } 

   cout << '\n';
} 


/**************************************************************************
 * (C) Copyright 1992-2021 by Deitel & Associates, Inc. and               *
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
