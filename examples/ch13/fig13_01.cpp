// fig13_01.cpp
// Demonstrating input and output with iterators.
#include <iostream>
#include <iterator> // ostream_iterator and istream_iterator

int main() {
   std::cout << "Enter two integers: ";

   // create istream_iterator for reading int values from cin
   std::istream_iterator<int> inputInt{std::cin};

   const int number1{*inputInt}; // read int from standard input
   ++inputInt; // move iterator to next input value        
   const int number2{*inputInt}; // read int from standard input

   // create ostream_iterator for writing int values to cout
   std::ostream_iterator<int> outputInt{std::cout};

   std::cout << "The sum is: ";
   *outputInt = number1 + number2; // output result to cout
   std::cout << "\n";
}



/**************************************************************************
 * (C) Copyright 1992-2022 by Deitel & Associates, Inc. and               *
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
