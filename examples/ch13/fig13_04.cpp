// fig13_04.cpp
// Standard library list class template.
#include <algorithm> // copy algorithm
#include <iostream>
#include <iterator> // ostream_iterator
#include <list> // list class-template definition
#include <vector>

// printList function template definition; uses 
// ostream_iterator and copy algorithm to output list elements
template <typename T>
void printList(const std::list<T>& items) {
   if (items.empty()) { // list is empty
      std::cout << "List is empty";
   }
   else {
      std::ostream_iterator<T> output{std::cout, " "};
      std::ranges::copy(items, output);
   }
}

int main() {
   std::list<int> values{}; // create list of ints     

   // insert items in values
   values.push_front(1);
   values.push_front(2);
   values.push_back(4);
   values.push_back(3);

   std::cout << "values contains: ";
   printList(values);

   values.sort(); // sort values
   std::cout << "\nvalues after sorting contains: ";
   printList(values);

   // insert elements of ints into otherValues                            
   std::vector ints{2, 6, 4, 8};
   std::list<int> otherValues{}; // create list of ints
   otherValues.insert(otherValues.cbegin(), ints.cbegin(), ints.cend());
   std::cout << "\nAfter insert, otherValues contains: ";
   printList(otherValues);

   // remove otherValues elements and insert at end of values
   values.splice(values.cend(), otherValues);
   std::cout << "\nAfter splice, values contains: ";
   printList(values);

   values.sort(); // sort values
   std::cout << "\nAfter sort, values contains: ";
   printList(values);

   // insert elements of ints into otherValues                            
   otherValues.insert(otherValues.cbegin(), ints.cbegin(), ints.cend());
   otherValues.sort(); // sort the list                                 
   std::cout << "\nAfter insert and sort, otherValues contains: ";
   printList(otherValues);

   // remove otherValues elements and insert into values in sorted order
   values.merge(otherValues);
   std::cout << "\nAfter merge:\n   values contains: ";
   printList(values);
   std::cout << "\n   otherValues contains: ";
   printList(otherValues);

   values.pop_front(); // remove element from front
   values.pop_back(); // remove element from back  
   std::cout << "\nAfter pop_front and pop_back:\n   values contains: ";
   printList(values);

   values.unique(); // remove duplicate elements
   std::cout << "\nAfter unique, values contains: ";
   printList(values);

   values.swap(otherValues); // swap elements of values and otherValues
   std::cout << "\nAfter swap:\n   values contains: ";
   printList(values);
   std::cout << "\n   otherValues contains: ";
   printList(otherValues);

   // replace contents of values with elements of otherValues
   values.assign(otherValues.cbegin(), otherValues.cend());
   std::cout << "\nAfter assign, values contains: ";
   printList(values);

   // remove otherValues elements and insert into values in sorted order
   values.merge(otherValues);
   std::cout << "\nAfter merge, values contains: ";
   printList(values);

   values.remove(4); // remove all 4s
   std::cout << "\nAfter remove(4), values contains: ";
   printList(values);
   std::cout << "\n";
}


/**************************************************************************
 * (C) Copyright 1992-2021 by Deitel & Associates, Inc. and               *
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

