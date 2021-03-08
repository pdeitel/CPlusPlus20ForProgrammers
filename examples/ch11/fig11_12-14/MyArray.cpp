// Fig. 11.13: MyArray.cpp
// MyArray class implementation.
#include <iostream>
#include <iomanip>
#include <stdexcept> 
#include <utility> // contains std::move
#include "MyArray.h" // MyArray class definition

using namespace std;

// constructor for class MyArray 
MyArray::MyArray(size_t arraySize)
   : size(arraySize),
     ptr(new int[size]{}) {
   cout << "MyArray(int) constructor called" << endl;
} 

// copy constructor for class MyArray;
// must receive a reference to an MyArray
MyArray::MyArray(const MyArray& arrayToCopy) 
   : size(arrayToCopy.size),
     ptr(new int[size]){
   cout << "MyArray copy constructor called" << endl;

   for (size_t i{0}; i < size; ++i) {
      ptr[i] = arrayToCopy.ptr[i]; // copy into object
   } 
} 

// move constructor for class MyArray;                                  
// must receive an rvalue reference to a MyArray                      
MyArray::MyArray(MyArray&& arrayToMove) noexcept                          
   : size(arrayToMove.size), // move arrayToMove's size to new MyArray
     ptr(arrayToMove.ptr) { // move arrayToMove's ptr to new MyArray    
   cout << "MyArray move constructor called" << endl;                   

   // indicate that arrayToMove is now empty                          
   arrayToMove.size = 0;                                              
   arrayToMove.ptr = nullptr;                                         
}                                    

// destructor for class MyArray
MyArray::~MyArray() {
   cout << "MyArray destructor called" << endl;
   delete [] ptr; // release pointer-based array space
} 

// return number of elements of MyArray
size_t MyArray::size() const {return size;}

// copy assignment operator
MyArray &MyArray::operator=(const MyArray& right) {
   cout << "MyArray copy assignment operator called" << endl;

   if (&right != this) { // avoid self-assignment
      // for MyArrays of different sizes, deallocate original
      // left-side MyArray, then allocate new left-side MyArray
      if (size != right.size) {
         delete [] ptr; // release space
         size = right.size; // resize this object
         ptr = new int[size]; // create space for MyArray copy
      } 

      for (size_t i = 0; i < size; ++i) {
         ptr[i] = right.ptr[i]; // copy array into object
      } 
   } 

   return *this; // enables x = y = z, for example
}

// move assignment operator
MyArray& MyArray::operator=(MyArray&& arrayToMove) noexcept {               
   cout << "MyArray move assignment operator called" << endl;           

   if (&arrayToMove != this) { // avoid self-assignment               
      delete [] ptr; // release space                                 
      size = arrayToMove.size; // move arrayToMove's size to new MyArray
      ptr = arrayToMove.ptr; // move arrayToMove's ptr to new MyArray   

      // indicate that arrayToMove is now empty                       
      arrayToMove.size = 0;                                           
      arrayToMove.ptr = nullptr;                                      
   }                                              

   return *this; // enables x = y = z, for example                    
}                                   

// determine if two MyArrays are equal and
// return true, otherwise return false
bool MyArray::operator==(const MyArray &right) const {
   if (size != right.size) {
      return false; // arrays of different number of elements
   }

   for (size_t i = 0; i < size; ++i) {
      if (ptr[i] != right.ptr[i]) {
         return false; // MyArray contents are not equal
      }
   }

   return true; // MyArrays are equal
}

// overloaded subscript operator for non-const MyArrays;
// reference return creates a modifiable lvalue
int &MyArray::operator[](size_t subscript) {
   // check for subscript out-of-range error
   if (subscript >= size)
      throw out_of_range("Subscript out of range");

   return ptr[subscript]; // reference return
} 

// overloaded subscript operator for const MyArrays
// const reference return creates an rvalue
int MyArray::operator[](size_t subscript) const
{
   // check for subscript out-of-range error
   if (subscript >= size)
      throw out_of_range("Subscript out of range");

   return ptr[subscript]; // returns copy of this element
} 

// overloaded input operator for class MyArray;
// inputs values for entire MyArray
istream &operator>>(istream& input, MyArray&  a) {
   for (size_t i{0}; i < a.size; ++i) {
      input >> a.ptr[i];
   }

   return input; // enables cin >> x >> y;
} 

// overloaded output operator for class MyArray 
ostream &operator<<(ostream& output, const MyArray& a) {
   // output private ptr-based array 
   for (size_t i{0}; i < a.size; ++i) {
      output << a.ptr[i] << " ";
   }

   output << endl;
   return output; // enables cout << x << y;
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
