// fig15_21.cpp
// Adding and removing type attributes with type metafunctions.
#include <fmt/format.h>
#include <iostream>
#include <type_traits>

// add const to a type T
template <typename T>
struct my_add_const {
   using type = const T;
};

// general case: no pointer in type, so set nested type variable to T
template <typename T>
struct my_remove_ptr {
   using type = T;
};

// partial template specialization: T is a pointer type, so remove *
template <typename T>
struct my_remove_ptr<T*> {
   using type = T;
};

int main() {
   std::cout << fmt::format("{}\n{}{}\n{}{}\n\n",
      "ADD CONST TO A TYPE VIA A CUSTOM TYPE METAFUNCTION",
      "std::is_same<const int, my_add_const<int>::type>::value: ",
      std::is_same<const int, my_add_const<int>::type>::value,
      "std::is_same<int* const, my_add_const<int*>::type>::value: ",
      std::is_same<int* const, my_add_const<int*>::type>::value);

   std::cout << fmt::format("{}\n{}{}\n{}{}\n\n",
      "REMOVE POINTER FROM TYPES VIA A CUSTOM TYPE METAFUNCTION",
      "std::is_same<int, my_remove_ptr<int>::type>::value: ",
      std::is_same<int, my_remove_ptr<int>::type>::value,
      "std::is_same<int, my_remove_ptr<int*>::type>::value: ",
      std::is_same<int, my_remove_ptr<int*>::type>::value);

   std::cout << fmt::format("{}\n{}{}\n{}{}\n\n",
      "ADD REFERENCES TO TYPES USING STANDARD TYPE TRAITS",
      "std::is_same<int&, std::add_lvalue_reference<int>::type>::value: ",
      std::is_same<int&, std::add_lvalue_reference<int>::type>::value,
      "std::is_same<int&&, std::add_rvalue_reference<int>::type>::value: ",
      std::is_same<int&&, std::add_rvalue_reference<int>::type>::value);

   std::cout << fmt::format("{}\n{}{}\n{}{}\n{}{}\n",
      "REMOVE REFERENCES FROM TYPES USING STANDARD TYPE TRAITS",
      "std::is_same<int, std::remove_reference<int>::type>::value: ",
      std::is_same<int, std::remove_reference<int>::type>::value,
      "std::is_same<int, std::remove_reference<int&>::type>::value: ",
      std::is_same<int, std::remove_reference<int&>::type>::value,
      "std::is_same<int, std::remove_reference<int&&>::type>::value: ",
      std::is_same<int, std::remove_reference<int&&>::type>::value);
}


/**************************************************************************
 * (C) Copyright 1992-2020 by Deitel & Associates, Inc. and               *
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
