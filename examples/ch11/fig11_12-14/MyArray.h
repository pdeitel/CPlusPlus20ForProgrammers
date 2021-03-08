// Fig. 11.12: MyArray.h
// MyArray class header.
#pragma once
#include <iostream>

class MyArray {
   friend std::ostream &operator<<(std::ostream&, const MyArray&);
   friend std::istream &operator>>(std::istream&, MyArray&);

public:
   explicit MyArray(size_t size); // default constructor
   MyArray(const MyArray&); // copy constructor    
   MyArray(MyArray&&) noexcept; // move constructor
   ~MyArray(); // destructor
   size_t size() const; // return size

   MyArray &operator=(const MyArray& right); // copy assignment operator
   MyArray &operator=(MyArray&& right) noexcept; // move assignment operator
   bool operator==(const MyArray& right) const; // equality operator

   // inequality operator; returns opposite of == operator
   bool operator!=(const MyArray& right) const {
      return ! (*this == right); // invokes MyArray::operator==
   } 
   
   // subscript operator for non-const objects returns modifiable lvalue
   int& operator[](size_t index);              

   // subscript operator for const objects returns rvalue
   int operator[](size_t index) const;  
private:
   size_t m_size; // pointer-based array size
   int* m_ptr; // pointer to first element of pointer-based array
}; 



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
