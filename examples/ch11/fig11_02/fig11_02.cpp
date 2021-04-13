// fig11_02.cpp
// Demonstrating unique_ptr.
#include <iostream>
#include <memory>
using namespace std;

class Integer {
public:
   // constructor
   Integer(int i) : value{i} {
      cout << "Constructor for Integer " << value << "\n";
   }

   // destructor
   ~Integer() {
      cout << "Destructor for Integer " << value << "\n";
   }

   int getValue() const {return value;}; // return Integer value
private:
   int value{0};
};

// use unique_ptr to manipulate Integer object
int main() {
   cout << "Creating a unique_ptr object that points to an Integer\n";

   // "aim" unique_ptr at a new Integer object                  
   auto ptr{make_unique<Integer>(7)};

   // use unique_ptr to call an Integer member function
   cout << "Integer value: " << ptr->getValue()
      << "\n\nMain ends\n";
}



/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
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
