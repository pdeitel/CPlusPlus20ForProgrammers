// fig07_11.cpp
// sizeof operator used to determine standard data type sizes.
#include <fmt/format.h>
#include <iostream>

int main() {
   constexpr char c{}; // variable of type char
   constexpr short s{}; // variable of type short
   constexpr int i{}; // variable of type int
   constexpr long l{}; // variable of type long
   constexpr long long ll{}; // variable of type long long
   constexpr float f{}; // variable of type float
   constexpr double d{}; // variable of type double
   constexpr long double ld{}; // variable of type long double
   constexpr int array[20]{}; // built-in array of int
   const int* const ptr{array}; // variable of type int*

   std::cout << fmt::format("sizeof c = {}\tsizeof(char) = {}\n",
      sizeof c, sizeof(char));
   std::cout << fmt::format("sizeof s = {}\tsizeof(short) = {}\n",
      sizeof s, sizeof(short));
   std::cout << fmt::format("sizeof i = {}\tsizeof(int) = {}\n",
      sizeof i, sizeof(int));
   std::cout << fmt::format("sizeof l = {}\tsizeof(long) = {}\n",
      sizeof l, sizeof(long));
   std::cout << fmt::format("sizeof ll = {}\tsizeof(long long) = {}\n",
      sizeof ll, sizeof(long long));
   std::cout << fmt::format("sizeof f = {}\tsizeof(float) = {}\n",
      sizeof f, sizeof(float));
   std::cout << fmt::format("sizeof d = {}\tsizeof(double) = {}\n",
      sizeof d, sizeof(double));
   std::cout << fmt::format("sizeof ld = {}\tsizeof(long double) = {}\n",
      sizeof ld, sizeof(long double));
   std::cout << fmt::format("sizeof array = {}\n", sizeof array);
   std::cout << fmt::format("sizeof ptr = {}\n", sizeof ptr);
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
