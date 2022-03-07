// fig11_02.cpp
// Demonstrating unique_ptr.
#include <fmt/format.h>
#include <iostream>
#include <memory>

class Integer {
public:
   // constructor
   Integer(int i) : value{i} {
      std::cout << fmt::format("Constructor for Integer {}\n", value);
   }

   // destructor
   ~Integer() {
      std::cout << fmt::format("Destructor for Integer {}\n", value);
   }

   int getValue() const { return value; } // return Integer value
private:
   int value{0};
};

// use unique_ptr to manipulate Integer object
int main() {
   std::cout << "Creating a unique_ptr that points to an Integer\n";

   // create a unique_ptr object and "aim" it at a new Integer object 
   auto ptr{std::make_unique<Integer>(7)};

   // use unique_ptr to call an Integer member function
   std::cout << fmt::format("Integer value: {}\n\nMain ends\n",
      ptr->getValue());
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
