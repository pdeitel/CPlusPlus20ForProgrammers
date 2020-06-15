// fig07_12.cpp
// C++20 spans: Creating views into containers.
#include <array>
#include <iostream>
#include <numeric>
#include <span>
#include <vector>
using namespace std;

// items parameter is treated as a const int* so we also need the size to
// know how to iterate over items with counter-controlled iteration
void displayArray(const int items[], size_t size) {
   for (size_t i{0}; i < size; ++i) {
      cout << items[i] << " ";
   }
}

// span parameter contains both the location of the first item
// and the number of elements, so we can iterate using range-based for
void displaySpan(span<const int> items) {
   for (const auto& item : items) { // spans are iterable
      cout << item << " ";
   }
}

// spans can be used to modify elements in the original data structure
void times2(span<int> items) {
   for (int& item : items) {
      item *= 2;
   }
}

int main() {
   int values1[5]{1, 2, 3, 4, 5};
   array<int, 5> values2{6, 7, 8, 9, 10};
   vector<int> values3{11, 12, 13, 14, 15};

   // must specify size because the compiler treats displayArray's items 
   // parameter as a pointer to the first element of the argument
   cout << "values1 via displayArray: ";
   displayArray(values1, 5); 

   // compiler knows values' size and automatically creates a span
   // representing &values1[0] and the array's length
   cout << "\nvalues1 via displaySpan: ";
   displaySpan(values1); 

   // compiler also can create spans from std::arrays and std::vectors
   cout << "\nvalues2 via displaySpan: ";
   displaySpan(values2);
   cout << "\nvalues3 via displaySpan: ";
   displaySpan(values3);

   // changing a span's contents modifies the original data
   times2(values1);
   cout << "\n\nvalues1 after times2 modifies its span argument: ";
   displaySpan(values1);

   // spans have various array-and-vector-like capabilities
   span<int> mySpan{values1}; 
   cout << "\n\nmySpan's first element: " << mySpan.front()
      << "\nmySpan's last element: " << mySpan.back();

   // spans can be used with standard library algorithms
   cout << "\n\nSum of mySpan's elements: "
      << accumulate(begin(mySpan), end(mySpan), 0);

   // spans can be used to create subviews of a container
   cout << "\n\nFirst three elements of mySpan: ";
   displaySpan(mySpan.first(3));
   cout << "\nLast three elements of mySpan: ";
   displaySpan(mySpan.last(3));
   cout << "\nMiddle three elements of mySpan: ";
   displaySpan(mySpan.subspan(1, 3));
   
   // changing a subview's contents modifies the original data   
   times2(mySpan.subspan(1, 3));
   cout << "\n\nvalues1 after modifying middle three elements via span: ";
   displaySpan(values1);

   // access a span element via []
   cout << "\n\nThe element at index 2 is: " << mySpan[2];

   // attempt to access an element outside the bounds
   cout << "\n\nThe element at index 10 is: " << mySpan[10] << endl;
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
