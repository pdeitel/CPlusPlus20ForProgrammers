// fig12_05.cpp
// Demonstrating a function try block.
#include <iostream>
#include <limits>
#include <stdexcept>
using namespace std;

// class Integer purposesly throws an exception from it's constructor
class Integer {
public:
   explicit Integer(int i) : value{i} {
      cout << "Integer constructor: " << value 
         << "\nPurposely throwing exception from Integer constructor\n";
      throw runtime_error("Integer constructor failed");
   }
private:
   int value{};
};

class ResourceManager {
public:
   ResourceManager(int i) try : myInteger(i) {
      cout << "ResourceManager constructor called\n";
   }
   catch (const runtime_error& ex) {
      cout << "Exception while constructing ResourceManager: " 
         << ex.what() << "\nAutomatically rethrowing the exception\n";
   }
private:
   Integer myInteger;
};

int main() {   
   try {
      const ResourceManager resource{7};
   }
   catch (const runtime_error& ex) {
      cout << "Rethrown exception caught in main: " << ex.what() << "\n";
   }
} 


/**************************************************************************
 * (C) Copyright 1992-2021 by Deitel & Associates, Inc. and               *
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
