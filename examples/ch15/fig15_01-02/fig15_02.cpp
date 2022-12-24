// fig15_02.cpp
// Stack class template test program.
#include <iostream>
#include "Stack.h" // Stack class template definition

int main() {
   Stack<double> doubleStack{}; // create a Stack of double
   constexpr size_t doubleStackSize{5}; // stack size
   double doubleValue{1.1}; // first value to push

   std::cout << "Pushing elements onto doubleStack\n";

   // push 5 doubles onto doubleStack
   for (size_t i{0}; i < doubleStackSize; ++i) {
      doubleStack.push(doubleValue);
      std::cout << doubleValue << ' ';
      doubleValue += 1.1;
   } 

   std::cout << "\n\nPopping elements from doubleStack\n";

   // pop elements from doubleStack
   while (!doubleStack.isEmpty()) { // loop while Stack is not empty
      std::cout << doubleStack.top() << ' '; // display top element
      doubleStack.pop(); // remove top element
   } 

   std::cout << "\nStack is empty, cannot pop.\n";

   Stack<int> intStack{}; // create a Stack of int
   constexpr size_t intStackSize{10}; // stack size
   int intValue{1}; // first value to push

   std::cout << "\nPushing elements onto intStack\n";

   // push 10 integers onto intStack
   for (size_t i{0}; i < intStackSize; ++i) {
      intStack.push(intValue);
      std::cout << intValue++ << ' ';
   } 

   std::cout << "\n\nPopping elements from intStack\n";

   // pop elements from intStack
   while (!intStack.isEmpty()) { // loop while Stack is not empty
      std::cout << intStack.top() << ' '; // display top element
      intStack.pop(); // remove top element
   } 

   std::cout << "\nStack is empty, cannot pop.\n";
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
