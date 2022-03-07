// fig14_04.cpp
// Algorithms remove, remove_if, remove_copy and remove_copy_if.
#include <algorithm> // algorithm definitions
#include <iostream>
#include <iterator> // ostream_iterator
#include <vector> 

int main() {
   std::vector init{10, 2, 15, 4, 10, 6};
   std::ostream_iterator<int> output{std::cout, " "};

   std::vector v1{init}; // initialize with copy of init
   std::cout << "v1: ";
   std::ranges::copy(v1, output);

   // remove all 10s from v1                                
   auto removed{std::ranges::remove(v1, 10)};
   v1.erase(removed.begin(), removed.end());
   std::cout << "\nv1 after removing 10s: ";
   std::ranges::copy(v1, output);

   std::vector v2{init}; // initialize with copy of init
   std::cout << "\n\nv2: ";
   std::ranges::copy(v2, output);

   // copy from v2 to c1, removing 10s in the process    
   std::vector<int> c1{};
   std::ranges::remove_copy(v2, std::back_inserter(c1), 10);
   std::cout << "\nc1 after copying v2 without 10s: ";
   std::ranges::copy(c1, output);

   std::vector v3{init}; // initialize with copy of init
   std::cout << "\n\nv3: ";
   std::ranges::copy(v3, output);

   // remove elements greater than 9 from v3                    
   auto greaterThan9{[](auto x) {return x > 9;}};
   auto removed2{std::ranges::remove_if(v3, greaterThan9)};
   v3.erase(removed2.begin(), removed2.end());
   std::cout << "\nv3 after removing elements greater than 9: ";
   std::ranges::copy(v3, output);

   std::vector v4{init}; // initialize with copy of init
   std::cout << "\n\nv4: ";
   std::ranges::copy(v4, output);

   // copy elements from v4 to c2, removing elements greater than 9
   std::vector<int> c2{}; 
   std::ranges::remove_copy_if(v4, std::back_inserter(c2), greaterThan9);
   std::cout << "\nc2 after copying v4 without elements greater than 9: ";
   std::ranges::copy(c2, output);
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
