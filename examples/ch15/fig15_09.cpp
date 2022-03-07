// fig15_09.cpp
// Testing custom concepts with static_assert.
#include <iostream>
#include <string>

template<typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template<typename T>     
auto multiply(T a, T b) {      
   static_assert(Numeric<T>);      
   return a * b;     
} 

int main() {
   using namespace std::string_literals;
   multiply(2, 5); // OK: int is Numeric
   multiply(2.5, 5.5); // OK: double is Numeric
   multiply("2"s, "5"s); // error: string is not Numeric
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
