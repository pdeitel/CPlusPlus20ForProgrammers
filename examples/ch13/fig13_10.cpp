// fig13_10.cpp
// Standard library stack adaptor class.
#include <iostream>
#include <list> // list class-template definition
#include <ranges> 
#include <stack> // stack adaptor definition
#include <vector> // vector class-template definition

// pushElements generic lambda to push values onto a stack
auto pushElements = [](auto& stack) {
   for (auto i : std::views::iota(0, 10)) {
      stack.push(i); // push element onto stack                  
      std::cout << stack.top() << ' '; // view (and display) top element
   }
};

// popElements generic lambda to pop elements off a stack
auto popElements = [](auto& stack) {
   while (!stack.empty()) {
      std::cout << stack.top() << ' '; // view (and display) top element
      stack.pop(); // remove top element                           
   }
};

int main() {
   std::stack<int> dequeStack{}; // uses a deque by default
   std::stack<int, std::vector<int>> vectorStack{}; // use a vector 
   std::stack<int, std::list<int>> listStack{}; // use a list

   // push the values 0-9 onto each stack 
   std::cout << "Pushing onto dequeStack: ";
   pushElements(dequeStack);
   std::cout << "\nPushing onto vectorStack: ";
   pushElements(vectorStack);
   std::cout << "\nPushing onto listStack: ";
   pushElements(listStack);

   // display and remove elements from each stack
   std::cout << "\n\nPopping from dequeStack: ";
   popElements(dequeStack);
   std::cout << "\nPopping from vectorStack: ";
   popElements(vectorStack);
   std::cout << "\nPopping from listStack: ";
   popElements(listStack);
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
