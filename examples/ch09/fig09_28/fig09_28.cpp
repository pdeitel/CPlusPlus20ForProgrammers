// fig09_28.cpp  
// Friends can access private members of a class.
#include <iostream>
using namespace std;

// Count class definition 
class Count {
   friend void setX(Count& c, int val); // friend declaration
public:
   int getX() const { return x; }
private:
   int x{0};
};

// function setX can modify private data of Count         
// because setX is declared as a friend of Count (line 8)
void setX(Count& c, int val) {
   c.x = val; // allowed because setX is a friend of Count 
}

int main() {
   Count counter{}; // create Count object

   cout << "counter.x after instantiation: " << counter.getX();
   setX(counter, 8); // set x using a friend function
   cout << "\ncounter.x after call to setX friend function: "
      << counter.getX() << "\n";
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
