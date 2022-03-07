// fig15_17.cpp
// Repeating a task using the comma operator and fold expressions.
#include <iostream>

template <typename... Items>
void printItems(Items... items) {
   ((std::cout << items << "\n"), ...); // unary right fold
}

int main() {
   std::cout << "printItems(1, 2.2, \"hello\"):\n";
   printItems(1, 2.2, "hello");
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
