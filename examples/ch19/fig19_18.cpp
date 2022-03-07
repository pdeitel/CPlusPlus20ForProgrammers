// fig19_18.cpp 
// flags member function.
#include <format>
#include <iostream>

int main() {
   int integerValue{1000};
   double doubleValue{0.0947628};

   // display flags value, int and double values (original format)
   std::cout << std::format("flags value: {}\n", std::cout.flags())
      << "int and double in original format:\n"
      << integerValue << '\t' << doubleValue << "\n\n";

   // save original format, then change the format
   auto originalFormat{std::cout.flags()};
   std::cout << std::showbase << std::oct << std::scientific;

   // display flags value, int and double values (new format)
   std::cout << std::format("flags value: {}\n", std::cout.flags())
      << "int and double in new format:\n"
      << integerValue << '\t' << doubleValue << "\n\n";

   std::cout.flags(originalFormat); // restore format

   // display flags value, int and double values (original format)
   std::cout << std::format("flags value: {}\n", std::cout.flags())
      << "int and double in original format:\n"
      << integerValue << '\t' << doubleValue << "\n";
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
