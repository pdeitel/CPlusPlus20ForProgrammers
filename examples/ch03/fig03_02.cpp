// fig03_02.cpp
// Solving the class-average problem using sentinel-controlled iteration. 
#include <iostream>
#include <iomanip> // parameterized stream manipulators  
using namespace std;

int main() {
   // initialization phase
   int total{0}; // initialize sum of grades
   int gradeCounter{0}; // initialize # of grades entered so far
   
   // processing phase
   // prompt for input and read grade from user
   cout << "Enter grade or -1 to quit: "; 
   int grade; 
   cin >> grade; 

   // loop until sentinel value is read from user
   while (grade != -1) {
      total = total + grade; // add grade to total
      gradeCounter = gradeCounter + 1; // increment counter 

      // prompt for input and read next grade from user
      cout << "Enter grade or -1 to quit: "; 
      cin >> grade; 
   }

   // termination phase
   // if user entered at least one grade
   if (gradeCounter != 0) {
      // use number with decimal point to calculate average of grades
      double average{static_cast<double>(total) / gradeCounter};

      // display total and average (with two digits of precision)
      cout << "\nTotal of the " << gradeCounter 
         << " grades entered is " << total;
      cout << setprecision(2) << fixed; 
      cout << "\nClass average is " << average << "\n"; 
   } 
   else { // no grades were entered, so output appropriate message
      cout << "No grades were entered\n"; 
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
