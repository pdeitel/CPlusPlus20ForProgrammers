// fig06_10.cpp
// Initializing multidimensional arrays.
#include <iostream>
#include <array>
using namespace std;

constexpr size_t rows{2};
constexpr size_t columns{3};
void printArray(const array<array<int, columns>, rows>& a);

int main() {
   const array<array<int, columns>, rows> array1{1, 2, 3, 4, 5, 6};
   const array<array<int, columns>, rows> array2{1, 2, 3, 4, 5};

   cout << "Values in array1 by row are:" << endl;
   printArray(array1);

   cout << "\nValues in array2 by row are:" << endl;
   printArray(array2);
}

// output array with two rows and three columns                 
void printArray(const array<array<int, columns>, rows>& a) {
   // loop through array's rows                             
   for (auto const& row : a) {
      // loop through columns of current row                
      for (auto const& element : row) {
         cout << element << ' ';
      }

      cout << endl; // start new line of output             
   }
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
