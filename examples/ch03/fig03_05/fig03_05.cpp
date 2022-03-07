// fig03_05.cpp
// Integer ranges and arbitrary-precision integers.
#include <iostream>
#include "bignumber.h" 
using namespace std;

int main() {
   // use the maximum long long fundamental type value in calculations
   const long long value1{9'223'372'036'854'775'807LL}; // long long max
   cout << "long long value1: " << value1
      << "\nvalue1 - 1: " << value1 - 1 // OK
      << "\nvalue1 + 1: " << value1 + 1; // result is undefined

   // use an arbitrary-precision integer
   const BigNumber value2{value1};
   cout << "\n\nBigNumber value2: " << value2
      << "\nvalue2 - 1: " << value2 - 1 // OK
      << "\nvalue2 + 1: " << value2 + 1; // OK

   // powers of 100,000,000 with long long
   long long value3{100'000'000};
   cout << "\n\nvalue3: " << value3;

   int counter{2};

   while (counter <= 5) {
      value3 *= 100'000'000; // quickly exceeds maximum long long value
      cout << "\nvalue3 to the power " << counter << ": " << value3;
      ++counter;
   }
   
   // powers of 100,000,000 with BigNumber
   BigNumber value4{100'000'000};
   cout << "\n\nvalue4: " << value4 << "\n";

   counter = 2;

   while (counter <= 5) {
      cout << "value4.pow(" << counter << "): " 
         << value4.pow(counter) << "\n";
      ++counter;
   }

   cout << "\n";
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

