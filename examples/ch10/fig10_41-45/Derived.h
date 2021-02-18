// Fig. 10.43: Derived.h
// Definition of class Derived which inherits
// multiple base classes (Base1 and Base2).
#pragma once

#include <iostream>
#include <string>
#include "Base1.h"
#include "Base2.h"
using namespace std;

// class Derived definition
class Derived : public Base1, public Base2 {
public:
   Derived(int value, char letter, double real);
   double getReal() const;
   std::string toString() const;
private:
   double m_real; // derived class's private data
}; 



/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
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
