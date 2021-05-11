// fig14_06.cpp
// Mathematical algorithms of the standard library.
#include <algorithm> 
#include <array>
#include <iostream>
#include <iterator> 
#include <numeric>
#include <random> 

int main() {
   std::array a1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   std::ostream_iterator<int> output{std::cout, " "};

   std::cout << "a1: ";
   std::ranges::copy(a1, output);

   // create random-number engine and use it to help shuffle a1
   std::default_random_engine randomEngine{std::random_device{}()};
   std::ranges::shuffle(a1, randomEngine); // randomly order elements
   std::cout << "\na1 shuffled: ";
   std::ranges::copy(a1, output);

   std::array a2{100, 2, 8, 1, 50, 3, 8, 8, 9, 10};
   std::cout << "\n\na2: ";
   std::ranges::copy(a2, output);
 
   // count number of elements in a2 with value 8  
   auto result1{std::ranges::count(a2, 8)};
   std::cout << "\nCount of 8s in a2: " << result1;
 
   // count number of elements in a2 that are greater than 9
   auto result2{std::ranges::count_if(a2, [](auto x){return x > 9;})};
   std::cout << "\nCount of a2 elements greater than 9: " << result2;

   // locate minimum element in a2
   std::cout << "\n\na2 minimum element: "
      << *(std::ranges::min_element(a2));

   // locate maximum element in a2
   std::cout << "\na2 maximum element: "
      << *(std::ranges::max_element(a2));

   // locate minimum and maximum elements in a2
   const auto& [min, max]{std::ranges::minmax_element(a2)};
   std::cout << "\na2 minimum and maximum elements: "
      << *min << " and " << *max;

   // calculate cube of each element in a1; place results in cubes
   std::array<int, a1.size()> cubes{};
   std::ranges::transform(a1, cubes.begin(),
      [](auto x){return x * x * x;});              
   std::cout << "\n\na1 values cubed: ";
   std::ranges::copy(cubes, output);
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
