// fig06_03.cpp
// Using range-based for.
#include <iostream>
#include <array>
using namespace std;

int main() {
   array<int, 5> items{1, 2, 3, 4, 5};

   // display items before modification
   cout << "items before modification: ";
   for (const int item : items) {
      cout << item << " ";
   }

   // multiply the elements of items by 2
   for (int& itemRef : items) { // itemRef is a reference to an int
      itemRef *= 2;
   }

   // display items after modification
   cout << "\nitems after modification: ";
   for (const int item : items) {
      cout << item << " ";
   }

   // total elements of items using range-based for with initialization
   cout << "\n\ncalculating a running total of items' values: ";
   for (int runningTotal{0}; const int item : items) {
      runningTotal += item;
      cout << "\nitem: " << item << "; running total: " << runningTotal;
   }

   cout << endl;
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
