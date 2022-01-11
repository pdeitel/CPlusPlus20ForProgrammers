// fig09_28.cpp  
// Friends can access private members of a class.
#include <fmt/format.h>
#include <iostream>
#include "fmt/format.h" // In C++20, this will be #include <format> 

// Count class definition 
class Count {
   friend void setX(Count& c, int value); // friend declaration
public:
   int getX() const { return m_x; }
private:
   int m_x{0};
};

// function modifyX can modify private data of Count         
// because modifyX is declared as a friend of Count (line 8)
void modifyX(Count& c, int value) {
   c.m_x = value; // allowed because modifyX is a friend of Count 
}

int main() {
   Count counter{}; // create Count object

   std::cout << fmt::format("Initial counter.m_x: {}\n", counter.getX());
   modifyX(counter, 8); // change x's value using a friend function
   std::cout << fmt::format("counter.m_x after modifyX: {}\n",
      counter.getX());
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