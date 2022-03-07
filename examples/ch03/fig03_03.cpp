// fig03_03.cpp
// Analysis of examination results using nested control statements.
#include <iostream>
using namespace std;

int main() {
   // initializing variables in declarations
   int passes{0}; 
   int failures{0};
   int studentCounter{1}; 

   // process 10 students using counter-controlled loop
   while (studentCounter <= 10) {
      // prompt user for input and obtain value from user
      cout << "Enter result (1 = pass, 2 = fail): ";
      int result;
      cin >> result;

      // if...else is nested in the while statement           
      if (result == 1) {         
         passes = passes + 1;  
      }
      else {    
         failures = failures + 1; 
      }

      // increment studentCounter so loop eventually terminates
      studentCounter = studentCounter + 1;  
   } 

   // termination phase; prepare and display results
   cout << "Passed: " << passes << "\nFailed: " << failures << "\n";

   // determine whether more than 8 students passed
   if (passes > 8) {
      cout << "Bonus to instructor!\n";
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
 *************************************************************************/
