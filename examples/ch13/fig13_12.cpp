// fig13_12.cpp
// Standard library priority_queue adaptor class.
#include <iostream>
#include <queue> // priority_queue adaptor definition

int main() {
   std::priority_queue<double> priorities; // create priority_queue

   // push elements onto priorities
   priorities.push(3.2);
   priorities.push(9.8);
   priorities.push(5.4);

   std::cout << "Popping from priorities: ";

   // pop element from priority_queue
   while (!priorities.empty()) {
      std::cout << priorities.top() << ' '; // view top element
      priorities.pop(); // remove top element             
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
