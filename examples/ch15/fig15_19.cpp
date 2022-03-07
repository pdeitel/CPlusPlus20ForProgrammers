// fig15_19.cpp
// Calculating factorials at compile time.
#include <iostream>

// Factorial value metafunction calculates factorials recursively
template <int N>
struct Factorial {
   static constexpr long long value{N * Factorial<N - 1>::value};
};

// Factorial specialization for the base case
template <>
struct Factorial<0> {
   static constexpr long long value{1}; // 0! is 1
};

// constexpr compile-time recursive factorial
constexpr long long recursiveFactorial(int number) {
   if (number <= 1) {
      return 1; // base cases: 0! = 1 and 1! = 1 
   }
   else { // recursion step                      
      return number * recursiveFactorial(number - 1);
   }
}

// constexpr compile-time iterative factorial
constexpr long long iterativeFactorial(int number) {
   long long factorial{1}; // result for 0! and 1!

   for (long long i{2}; i <= number; ++i) {
      factorial *= i;
   }

   return factorial;
}

int main() {
   // "calling" a value metafunction requires instantiating 
   // the template and accessing its static value member
   std::cout << "CALCULATING FACTORIALS AT COMPILE TIME "
      << "WITH A RECURSIVE METAFUNCTION"
      << "\nFactorial(0): " << Factorial<0>::value
      << "\nFactorial(1): " << Factorial<1>::value
      << "\nFactorial(2): " << Factorial<2>::value
      << "\nFactorial(3): " << Factorial<3>::value
      << "\nFactorial(4): " << Factorial<4>::value
      << "\nFactorial(5): " << Factorial<5>::value;

   // calling the recursive constexpr function recursiveFactorial
   std::cout << "\n\nCALCULATING FACTORIALS AT COMPILE TIME "
      << "WITH A RECURSIVE CONSTEXPR FUNCTION"
      << "\nrecursiveFactorial(0): " << recursiveFactorial(0)
      << "\nrecursiveFactorial(1): " << recursiveFactorial(1)
      << "\nrecursiveFactorial(2): " << recursiveFactorial(2)
      << "\nrecursiveFactorial(3): " << recursiveFactorial(3)
      << "\nrecursiveFactorial(4): " << recursiveFactorial(4)
      << "\nrecursiveFactorial(5): " << recursiveFactorial(5);

   // calling the iterative constexpr function iterativeFactorial
   std::cout << "\n\nCALCULATING FACTORIALS AT COMPILE TIME "
      << "WITH AN ITERATIVE CONSTEXPR FUNCTION"
      << "\niterativeFactorial(0): " << iterativeFactorial(0)
      << "\niterativeFactorial(1): " << iterativeFactorial(1)
      << "\niterativeFactorial(2): " << iterativeFactorial(2)
      << "\niterativeFactorial(3): " << iterativeFactorial(3)
      << "\niterativeFactorial(4): " << iterativeFactorial(4)
      << "\niterativeFactorial(5): " << iterativeFactorial(5) << "\n";
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
