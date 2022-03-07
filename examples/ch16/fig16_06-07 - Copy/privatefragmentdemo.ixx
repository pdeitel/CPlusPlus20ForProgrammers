// Fig. 16.6: privatefragmentdemo.ixx
// Primary module interface for a module named 
// privatefragmentdemo with a :private module fragment.
export module privatefragmentdemo; // introduces the module name

import <memory>; // std::unique_ptr

class Implementation; // forward class declaration

export class Integer { // interface class
public:
   Integer(int value); // constructor
   int getValue() const; // gets value from hidden Implementation object
   std::unique_ptr<Implementation> getImplementationCopy();
private:
   // pointer to object of the hidden Implementation 
   std::unique_ptr<Implementation> m_ptr;
};

// everything from the following module :private; declaration to the end 
// of the file is hidden from importers of module privatefragmentdemo 
module :private;

// hidden Implementation class used in the 
// Integer interface class's member function implementations
class Implementation {
public:
   explicit Implementation(int value) : m_value{value} {}
   int getValue() const {return m_value;}
private:
   int m_value; // data we're hiding from the client code
};

// Integer interface class's member function implementations
Integer::Integer(int value) 
   : m_ptr{std::make_unique<Implementation>(value)} {}

int Integer::getValue() const {return m_ptr->getValue();}

// Though we return a std::unique_ptr<Implementation>, translation units
// that import module privatefragmentdemo cannot see type Implementation. 
// Attempts to use the Implementation's members fail to compile.
std::unique_ptr<Implementation> Integer::getImplementationCopy() {
   return std::make_unique<Implementation>(m_ptr->getValue());
}

/*************************************************************************
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
