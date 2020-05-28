// fig06_13.cpp
// Functional-style programming with C++20 ranges and views.
#include <array>
#include <iostream>
#include <numeric>
#include <ranges>
using namespace std;

int main() {
   // lambda to display results of range operations
   auto showValues = [](auto& values, const string& message) {
      cout << message << ": ";

      for (auto value : values) {
         cout << value << " ";
      }

      cout << endl;
   };

   auto values1 = views::iota(1, 11); // generate integers 1-10
   showValues(values1, "Generate integers 1-10");

   // filter each value in values1, keeping only the even integers
   auto values2 = 
      values1 | views::filter([](const auto& x) {return x % 2 == 0;});
   showValues(values2, "Filtering even integers");

   // map each value in values2 to its square
   auto values3 = 
      values2 | views::transform([](const auto& x) {return x * x;}); 
   showValues(values3, "Mapping even integers to squares");

   // combine filter and transform to get squares of the even integers
   auto values4 = 
      values1 | views::filter([](const auto& x) {return x % 2 == 0;}) 
              | views::transform([](const auto& x) {return x * x;});
   showValues(values4, "Squares of even integers");

   // total the squares of the even integers 
   cout << "Sum the squares of the even integers from 2-10: " <<
      accumulate(begin(values4), end(values4), 0) << endl;

   // process a container's elements
   array<int, 10> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   auto values5 = 
      numbers | views::filter([](const auto& x) {return x % 2 == 0;}) 
              | views::transform([](const auto& x) {return x * x;});
   showValues(values5, "Squares of even integers in array numbers");
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
