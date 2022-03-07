// Fig. 15.11: MyArray.h
// Class template MyArray with custom iterators implemented 
// by class templates ConstIterator and Iterator
#pragma once
#include <algorithm>
#include <compare>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <utility>

// class template ConstIterator for a MyArray const iterator 
template <typename T>
class ConstIterator {
public:
   // public iterator nested type names
   using iterator_category = std::bidirectional_iterator_tag;
   using difference_type = std::ptrdiff_t; 
   using value_type = T;
   using pointer = const value_type*;
   using reference = const value_type&;

   // default constructor
   ConstIterator() = default;

   // initialize a ConstIterator with a pointer into a MyArray
   ConstIterator(pointer p) : m_ptr{p} {}
   
   // OPERATIONS ALL ITERATORS MUST PROVIDE
   // increment the iterator to the next element and 
   // return a reference to the iterator
   ConstIterator& operator++() noexcept {
      ++m_ptr;
      return *this;
   }

   // increment the iterator to the next element and 
   // return the iterator before the increment
   ConstIterator operator++(int) noexcept {
      ConstIterator temp{*this};
      ++(*this);
      return temp; 
   }

   // OPERATIONS INPUT ITERATORS MUST PROVIDE
   // return a const reference to the element m_ptr points to
   reference operator*() const noexcept {return *m_ptr;}

   // return a const pointer to the element m_ptr points to
   pointer operator->() const noexcept {return m_ptr;}

   // <=> operator automatically supports equality/relational operators.
   // Only == and != are needed for bidirectional iterators.
   // This implementation would support the <, <=, > and >= required 
   // by random-access iterators.
   auto operator<=>(const ConstIterator& other) const = default;

   // OPERATIONS BIDIRECTIONAL ITERATORS MUST PROVIDE
   // decrement the iterator to the previous element and 
   // return a reference to the iterator
   ConstIterator& operator--() noexcept {
      --m_ptr;
      return *this;
   }

   // decrement the iterator to the previous element and 
   // return the iterator before the decrement
   ConstIterator operator--(int) noexcept {
      ConstIterator temp{*this};
      --(*this);
      return temp; 
   }
private:
   pointer m_ptr{nullptr};
};

// class template Iterator for a MyArray non-const iterator;
// redefines several inherited operators to return non-const results
template <typename T>
class Iterator : public ConstIterator<T> {
public:
   // public iterator nested type names
   using iterator_category = std::bidirectional_iterator_tag;
   using difference_type = std::ptrdiff_t; 
   using value_type = T;
   using pointer = value_type*;
   using reference = value_type&;

   // inherit ConstIterator constructors
   using ConstIterator<T>::ConstIterator;

   // OPERATIONS ALL ITERATORS MUST PROVIDE
   // increment the iterator to the next element and 
   // return a reference to the iterator
   Iterator& operator++() noexcept {
      ConstIterator<T>::operator++(); // call base-class version
      return *this;
   }

   // increment the iterator to the next element and 
   // return the iterator before the increment
   Iterator operator++(int) noexcept {
      Iterator temp{*this};
      ConstIterator<T>::operator++(); // call base-class version
      return temp;
   }

   // OPERATIONS INPUT ITERATORS MUST PROVIDE
   // return a reference to the element m_ptr points to; this
   // operator returns a non-const reference for output iterator support
   reference operator*() const noexcept {
      return const_cast<reference>(ConstIterator<T>::operator*());
   }

   // return a pointer to the element m_ptr points to
   pointer operator->() const noexcept {
      return const_cast<pointer>(ConstIterator<T>::operator->());
   }

   // OPERATIONS BIDIRECTIONAL ITERATORS MUST PROVIDE
   // decrement the iterator to the previous element and 
   // return a reference to the iterator
   Iterator& operator--() noexcept {
      ConstIterator<T>::operator--(); // call base-class version
      return *this;
   }

   // decrement the iterator to the previous element and 
   // return the iterator before the decrement
   Iterator operator--(int) noexcept {
      Iterator temp{*this};
      ConstIterator<T>::operator--(); // call base-class version
      return temp;
   }
};

// class template MyArray contains a fixed-size T[SIZE] array;
// MyArray is an aggregate type with public data, like std::array
template <typename T, size_t SIZE>
struct MyArray {
   // type names used in standard library containers
   using value_type = T;
   using size_type = size_t;
   using difference_type = ptrdiff_t;
   using pointer = value_type*;
   using const_pointer = const value_type*;
   using reference = value_type&;
   using const_reference = const value_type&;

   // iterator type names used in standard library containers
   using iterator = Iterator<T>;
   using const_iterator = ConstIterator<T>;
   using reverse_iterator = std::reverse_iterator<iterator>;
   using const_reverse_iterator = std::reverse_iterator<const_iterator>;

   // Rule of Zero: MyArray's special member functions are autogenerated

   constexpr size_type size() const noexcept {return SIZE;} // return size

   // member functions that return iterators
   iterator begin() {return iterator{&m_data[0]};}
   iterator end() {return iterator{&m_data[0] + size()};}
   const_iterator begin() const {return const_iterator{&m_data[0]};}
   const_iterator end() const {
      return const_iterator{&m_data[0] + size()};
   }
   const_iterator cbegin() const {return begin();}
   const_iterator cend() const {return end();}

   // member functions that return reverse iterators
   reverse_iterator rbegin() {return reverse_iterator{end()};}
   reverse_iterator rend() {return reverse_iterator{begin()};}
   const_reverse_iterator rbegin() const {
      return const_reverse_iterator{end()};
   }
   const_reverse_iterator rend() const {
      return const_reverse_iterator{begin()};
   }
   const_reverse_iterator crbegin() const {return rbegin();}
   const_reverse_iterator crend() const {return rend();}

   // autogenerated three-way comparison operator
   auto operator<=>(const MyArray& t) const noexcept = default;

   // overloaded subscript operator for non-const MyArrays;
   // reference return creates a modifiable lvalue
   T& operator[](size_type index) {
      // check for index out-of-range error
      if (index >= size()) {
         throw std::out_of_range{"Index out of range"};
      }

      return m_data[index]; // reference return
   }

   // overloaded subscript operator for const MyArrays;
   // const reference return creates a non-modifiable lvalue
   const T& operator[](size_type index) const {
      // check for subscript out-of-range error
      if (index >= size()) {
         throw std::out_of_range{"Index out of range"};
      }

      return m_data[index]; // returns copy of this element
   }
	
   // like std::array the data is public to make this an aggregate type
   T m_data[SIZE]; // built-in array of type T with SIZE elements
};

// deduction guide to enable MyArrays to be brace initialized
template<typename T, std::same_as<T>... Us>
MyArray(T first, Us... rest) -> MyArray<T, 1 + sizeof...(Us)>;

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
