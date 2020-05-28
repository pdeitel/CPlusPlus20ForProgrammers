// fig06_11.cpp
// Compute the sum of the elements of an array using accumulate.
#include <array>
#include <iostream>
#include <numeric>
using namespace std;

int main() {
   constexpr size_t arraySize{4}; 
   array<int, arraySize> integers{10, 20, 30, 40};
   cout << "Total of array elements: " << 
      accumulate(begin(integers), end(integers), 0) << endl;
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
