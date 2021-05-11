// fig14_05.cpp
// Algorithms replace, replace_if, replace_copy and replace_copy_if.
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator> // ostream_iterator

int main() {
   std::ostream_iterator<int> output{std::cout, " "};

   std::array a1{10, 2, 15, 4, 10, 6};
   std::cout << "a1: ";
   std::ranges::copy(a1, output);

   // replace all 10s in a1 with 100        
   std::ranges::replace(a1, 10, 100);
   std::cout << "\na1 after replacing 10s with 100s: ";
   std::ranges::copy(a1, output);

   std::array a2{10, 2, 15, 4, 10, 6};
   std::array<int, a2.size()> c1{}; 
   std::cout << "\n\na2: ";
   std::ranges::copy(a2, output);

   // copy from a2 to c1, replacing 10s with 100s              
   std::ranges::replace_copy(a2, c1.begin(), 10, 100);
   std::cout << "\nc1 after replacing a2's 10s with 100s: ";
   std::ranges::copy(c1, output);

   std::array a3{10, 2, 15, 4, 10, 6};
   std::cout << "\n\na3: ";
   std::ranges::copy(a3, output);

   // replace values greater than 9 in a3 with 100   
   constexpr auto greaterThan9 = [](auto x) {return x > 9;};
   std::ranges::replace_if(a3, greaterThan9, 100);
   std::cout << "\na3 after replacing values greater than 9 with 100s: ";
   std::ranges::copy(a3, output);

   std::array a4{10, 2, 15, 4, 10, 6};
   std::array<int, a4.size()> c2{};
   std::cout << "\n\na4: ";
   std::ranges::copy(a4, output);

   // copy a4 to c2, replacing elements greater than 9 with 100         
   std::ranges::replace_copy_if(a4, c2.begin(), greaterThan9, 100);
   std::cout << "\nc2 after replacing a4's values "
      << "greater than 9 with 100s: ";
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
