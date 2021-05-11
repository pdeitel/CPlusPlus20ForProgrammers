// fig14_15.cpp
// Algorithms push_heap, pop_heap, make_heap and sort_heap.
#include <array>
#include <algorithm>
#include <iostream>
#include <iterator> 
#include <vector>

int main() {
   std::ostream_iterator<int> output(std::cout, " ");

   std::array heapArray{3, 100, 52, 77, 22, 31, 1, 98, 13, 40};
   std::cout << "heapArray before make_heap:\n";
   std::ranges::copy(heapArray, output);

   std::ranges::make_heap(heapArray); // create heap from heapArray
   std::cout << "\nheapArray after make_heap:\n";
   std::ranges::copy(heapArray, output);

   std::ranges::sort_heap(heapArray); // sort elements with sort_heap
   std::cout << "\nheapArray after sort_heap:\n";
   std::ranges::copy(heapArray, output);

   // lambda to add an int to a heap
   auto push{
      [&](std::vector<int>& heap, int value) {
         std::cout << "\n\npushing " << value << " onto heap";
         heap.push_back(value); // add value to the heap
         std::ranges::push_heap(heap); // insert last element into heap
         std::cout << "\nheap: ";
         std::ranges::copy(heap, output);
      }
   };

   // lambda to remove an item from the heap
   auto pop{
      [&](std::vector<int>& heap) {
         std::ranges::pop_heap(heap); // remove max item from heap
         std::cout << "\n\npopping highest priority item: " << heap.back();
         heap.pop_back(); // remove vector's last element
         std::cout << "\nheap: ";
         std::ranges::copy(heap, output);
      }
   };

   std::vector<int> heapVector{};

   // place five integers into heapVector, maintaining it as a heap
   for (auto value : {3, 52, 100}) {
      push(heapVector, value);
   }

   pop(heapVector); // remove max item 
   push(heapVector, 22); // add new item to heap

   pop(heapVector); // remove max item 
   push(heapVector, 77); // add new item to heap

   pop(heapVector); // remove max item 
   pop(heapVector); // remove max item 
   pop(heapVector); // remove max item 
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
