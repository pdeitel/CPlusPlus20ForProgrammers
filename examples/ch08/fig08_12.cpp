// fig08_12.cpp
// Using an ostringstream object.
#include <iostream>
#include <sstream> // header for string stream processing
#include <string>

int main() {
   std::ostringstream output; // create ostringstream object

   const std::string string1{"Output of several data types "};
   const std::string string2{"to an ostringstream object:"};
   const std::string string3{"\ndouble: "};
   const std::string string4{"\n   int: "};

   constexpr double d{123.4567};
   constexpr int i{22};

   // output strings, double and int to ostringstream 
   output << string1 << string2 << string3 << d << string4 << i;

   // call str to obtain string contents of the ostringstream
   std::cout << "output contains:\n" << output.str();

   // add additional characters and call str to output string
   output << "\nmore characters added";
   std::cout << "\n\noutput now contains:\n" << output.str() << '\n';
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
