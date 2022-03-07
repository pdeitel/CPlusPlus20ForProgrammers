// Fig. 10.44: Derived.cpp
// Member-function definitions for class Derived
#include <fmt/format.h> // In C++20, this will be #include <format> 
#include "Derived.h"

// constructor for Derived calls Base1 and Base2 constructors
Derived::Derived(int value, char letter, double real)
   : Base1{value}, Base2{letter}, m_real{real} {} 

// return real
double Derived::getReal() const {return m_real;}

// display all data members of Derived
std::string Derived::toString() const { 
   return fmt::format("int: {}; char: {}; double: {}", 
      Base1::getData(), Base2::getData(), getReal()); 
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
