// fig10_47.cpp
// Using virtual base classes.
#include <iostream>

// class Base definition
class Base {
public:   
   virtual void print() const = 0; // pure virtual
}; 

// class DerivedOne definition
class DerivedOne : virtual public Base {
public:
   // override print function
   void print() const override {std::cout << "DerivedOne\n";}
}; 

// class DerivedTwo definition
class DerivedTwo : virtual public Base {
public:
   // override print function
   void print() const override {std::cout << "DerivedTwo\n";}
}; 

// class Multiple definition
class Multiple : public DerivedOne, public DerivedTwo {
public:
   // qualify which version of function print
   void print() const override {DerivedTwo::print();}
}; 

int main() {
   Multiple both; // instantiate Multiple object
   DerivedOne one; // instantiate DerivedOne object
   DerivedTwo two; // instantiate DerivedTwo object
   Base* array[3];

   array[0] = &both; // allowed now
   array[1] = &one;
   array[2] = &two;

   // polymorphically invoke function print
   for (int i = 0; i < 3; ++i) {
      array[i]->print();
   } 
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

