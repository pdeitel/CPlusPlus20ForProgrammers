// Fig. 11.5: MyArray.cpp
// MyArray class member- and friend-function definitions.
#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <span>
#include <sstream> 
#include <stdexcept>
#include <utility>
#include "fmt/format.h" // In C++20, this will be #include <format> 
#include "MyArray.h" // MyArray class definition
using namespace std;

// MyArray constructor to create a MyArray of size elements containing 0
MyArray::MyArray(size_t size) 
   : m_size{size}, m_ptr{make_unique<int[]>(size)} {
   cout << "MyArray(size_t) constructor\n";
}

// MyArray constructor that accepts an initializer list
MyArray::MyArray(initializer_list<int> list)
   : m_size{list.size()}, m_ptr{make_unique<int[]>(list.size())} {
   cout << "MyArray(initializer_list) constructor\n";

   // copy list argument's elements into m_ptr's underlying int array;
   // m_ptr.get() returns the int array's starting memory location
   copy(begin(list), end(list), m_ptr.get());
}

// copy constructor: must receive a reference to a MyArray
MyArray::MyArray(const MyArray& original)
   : m_size{original.size()}, m_ptr{make_unique<int[]>(original.size())} {
   cout << "MyArray copy constructor\n";

   // copy original's elements into m_ptr's underlying int array 
   const span<const int> source{original.m_ptr.get(), original.size()};
   copy(begin(source), end(source), m_ptr.get());
}

// copy assignment operator: implemented with copy-and-swap idiom
MyArray& MyArray::operator=(const MyArray& right) {
   cout << "MyArray copy assignment operator\n";
   MyArray temp{right}; // invoke copy constructor
   swap(*this, temp); // exchange contents of this object and temp
   return *this;
}

// move constructor: must receive an rvalue reference to a MyArray                      
MyArray::MyArray(MyArray&& original) noexcept
   : m_size{exchange(original.m_size, 0)}, 
     m_ptr{std::move(original.m_ptr)} {  // move original.m_ptr into m_ptr
   cout << "MyArray move constructor\n";
}

// move assignment operator
MyArray& MyArray::operator=(MyArray&& right) noexcept {
   cout << "MyArray move assignment operator\n";

   if (this != &right) { // avoid self-assignment  
      // move right's data into this MyArray
      m_size = std::exchange(right.m_size, 0); // indicate right is empty
      m_ptr = std::move(right.m_ptr);
   }

   return *this; // enables x = y = z, for example                    
}

// destructor: This could be compiler-generated. We included it here so
// we could output when each MyArray is destroyed.
MyArray::~MyArray() {
   cout << "MyArray destructor\n";
}

// return a string representation of a MyArray
string MyArray::toString() const {
   const span<const int> items{m_ptr.get(), m_size};
   ostringstream output;
   output << "{";
   
   // insert each item in the dynamic array into the ostringstream
   for (size_t count{0}; const auto& item : items) {
      ++count;
      output << item << (count < m_size ? ", " : "");
   }

   output << "}";
   return output.str();
}

// determine if two MyArrays are equal and
// return true, otherwise return false
bool MyArray::operator==(const MyArray& right) const noexcept {
   // compare corresponding elements of both MyArrays
   const span<const int> lhs{m_ptr.get(), size()};
   const span<const int> rhs{right.m_ptr.get(), right.size()};
   return equal(begin(lhs), end(lhs), begin(rhs), end(rhs));
} 

// overloaded subscript operator for non-const MyArrays;
// reference return creates a modifiable lvalue
int& MyArray::operator[](size_t index) {
   // check for index out-of-range error
   if (index >= m_size) {
      throw out_of_range{"Index out of range"};
   }

   return m_ptr[index]; // reference return
} 

// overloaded subscript operator for const MyArrays;
// const reference return creates a non-modifiable lvalue
const int& MyArray::operator[](size_t index) const {
   // check for subscript out-of-range error
   if (index >= m_size) {
      throw out_of_range{"Index out of range"};
   }

   return m_ptr[index]; // returns copy of this element
} 

// preincrement every element, then return updated MyArray  
MyArray& MyArray::operator++() {
   // use a span and for_each to increment every element 
   const span<int> items{m_ptr.get(), m_size};
   for_each(begin(items), end(items), [](auto& item){++item;});
   return *this; 
}

// postincrement every element, and return copy of original MyArray  
MyArray MyArray::operator++(int) {
   MyArray temp(*this);
   ++(*this); // call preincrement operator++ to do the incrementing
   return temp; // return the temporary copy made before incrementing
}

// add value to every element, then return updated MyArray
MyArray& MyArray::operator+=(int value) {
   // use a span and for_each to increment every element 
   const span<int> items{m_ptr.get(), m_size};
   for_each(begin(items), end(items), 
      [value](auto& item) {item += value;});
   return *this;
}

// overloaded input operator for class MyArray;
// inputs values for entire MyArray
istream& operator>>(istream& in, MyArray& a) {
   span<int> items{a.m_ptr.get(), a.m_size};

   for (auto& item : items) {
      in >> item;
   }

   return in; // enables cin >> x >> y;
} 

// overloaded output operator for class MyArray 
ostream& operator<<(ostream& out, const MyArray& a) {
   out << a.toString();
   return out; // enables cout << x << y;
} 

// swap function used to implement copy-and-swap copy assignment operator
void swap(MyArray& a, MyArray& b) noexcept {
   std::swap(a.m_size, b.m_size); // swap using std::swap
   a.m_ptr.swap(b.m_ptr); // swap using unique_ptr swap member function
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
