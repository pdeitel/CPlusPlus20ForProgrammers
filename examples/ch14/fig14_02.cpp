// fig14_02.cpp
// Algorithms fill, fill_n, generate and generate_n.
#include <algorithm> // algorithm definitions
#include <array> // array class-template definition
#include <iostream>
#include <iterator> // ostream_iterator

// returns the next letter (starts with A)
char nextLetter() {
   static char letter{'A'};
   return letter++;
}

int main() {
   std::array<char, 10> chars{};
   std::ranges::fill(chars, '5'); // fill chars with 5s

   std::cout << "chars after filling with 5s: ";
   std::ostream_iterator<char> output{std::cout, " "};
   std::ranges::copy(chars, output);

   // fill first five elements of chars with 'A's
   std::ranges::fill_n(chars.begin(), 5, 'A');

   std::cout << "\nchars after filling five elements with 'A's: ";
   std::ranges::copy(chars, output);

   // generate values for all elements of chars with nextLetter
   std::ranges::generate(chars, nextLetter);

   std::cout << "\nchars after generating letters A-J: ";
   std::ranges::copy(chars, output);

   // generate values for first five elements of chars with nextLetter
   std::ranges::generate_n(chars.begin(), 5, nextLetter);

   std::cout << "\nchars after generating K-O into elements 0-4: ";
   std::ranges::copy(chars, output);

   // generate values for first three elements of chars with a lambda
   std::ranges::generate_n(chars.begin(), 3,
      []() { // lambda that takes no arguments
         static char letter{'A'};
         return letter++;
      }
   );

   std::cout << "\nchars after generating A-C into elements 0-2: ";
   std::ranges::copy(chars, output);
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
