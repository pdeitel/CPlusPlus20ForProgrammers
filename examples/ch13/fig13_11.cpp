// fig13_11.cpp
// Standard library queue adaptor class template.
#include <iostream>
#include <queue> // queue adaptor definition

int main() {
   std::queue<double> values{}; // queue with doubles

   // push elements onto queue values
   values.push(3.2);
   values.push(9.8);
   values.push(5.4);

   std::cout << "Popping from values: ";

   // pop elements from queue
   while (!values.empty()) {
      std::cout << values.front() << ' '; // view front element
      values.pop(); // remove element                     
   }

   std::cout << "\n";
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
