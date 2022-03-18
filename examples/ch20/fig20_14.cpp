// fig20_14.cpp
// Summing the elements of a braced initializer
#include <fmt/format.h>
#include <initializer_list>
#include <iostream>
#include <string>

// sum the elements of an initializer_list
template <typename T>
T sum(std::initializer_list<T> list) {
   T total{}; // value initialize total based on type T

   // sum all the elements in list; requires += operator for type T 
   for (auto item : list) {
      total += item;
   }

   return total;
}

int main() {
   // display the sum of four ints contained in a braced initializer
   std::cout << fmt::format("The sum of {} is: {}\n",
      "{1, 2, 3, 4}", sum({1, 2, 3, 4}));

   // display the sum of three doubles contained in a braced initializer
   std::cout << fmt::format("The sum of {} is: {}\n",
      "{1.1, 2.2, 3.3}", sum({1.1, 2.2, 3.3}));
      
   // display the sum of two strings contained in a braced initializer
   std::string s1{"Happy "};
   std::string s2{"birthday!"};
   std::cout << fmt::format("The sum of {} is: {}\n",
      "{\"Happy \", \"birthday!\"}", sum({s1, s2}));
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
