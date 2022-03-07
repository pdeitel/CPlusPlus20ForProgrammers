// fig14_18.cpp
// Working with C++20 std::views.
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map> 
#include <ranges> 
#include <string> 
#include <vector> 

int main() {
   std::ostream_iterator<int> output{std::cout, " "};
   auto isEven{[](int x) {return x % 2 == 0;}}; // true if x is even

   // infinite view of even integers starting at 0
   auto evens{std::views::iota(0) | std::views::filter(isEven)};

   std::cout << "First five even ints: ";
   std::ranges::copy(evens | std::views::take(5), output);

   std::cout << "\nEven ints less than 12: ";
   auto lessThan12{
      evens | std::views::take_while([](int x) {return x < 12;})};
   std::ranges::copy(lessThan12, output);

   std::cout << "\nEven ints less than 12 reversed: ";
   std::ranges::copy(lessThan12 | std::views::reverse, output);

   std::cout << "\nSquares of even ints less than 12 reversed: ";
   std::ranges::copy(
      lessThan12
         | std::views::reverse
         | std::views::transform([](int x) {return x * x;}), 
      output);

   std::cout << "\nSkip 1000 even ints, then take five: ";
   std::ranges::copy(
      evens | std::views::drop(1000) | std::views::take(5),
      output);

   std::cout << "\nFirst five even ints greater than 1000: ";
   std::ranges::copy(
      evens
         | std::views::drop_while([](int x) {return x <= 1000;})
         | std::views::take(5),
      output);

   // allow std::string object literals
   using namespace std::string_literals;

   std::map<std::string, int> romanNumerals{
      {"I"s, 1}, {"II"s, 2}, {"III"s, 3}, {"IV"s, 4}, {"V"s, 5}};
   auto displayPair{[](const auto& p) {
         std::cout << p.first << " = " << p.second << "\n"; }};
   std::cout << "\n\nromanNumerals:\n";
   std::ranges::for_each(romanNumerals, displayPair);

   std::ostream_iterator<std::string> stringOutput{std::cout, " "};
   std::cout << "\nKeys in romanNumerals: ";
   std::ranges::copy(romanNumerals | std::views::keys, stringOutput);

   std::cout << "\nValues in romanNumerals: ";
   std::ranges::copy(romanNumerals | std::views::values, output);

   std::cout << "\nKeys in romanNumerals via std::views::elements: ";
   std::ranges::copy(
      romanNumerals | std::views::elements<0>, stringOutput);

   std::cout << "\nvalues in romanNumerals via std::views::elements: ";
   std::ranges::copy(romanNumerals | std::views::elements<1>, output);
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
