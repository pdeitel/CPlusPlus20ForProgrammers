// fig08_12.cpp
// Using an ostringstream object.
#include <iostream>
#include <sstream> // header for string stream processing
#include <string>
using namespace std;

int main() {
   ostringstream output; // create ostringstream object

   const string string1{"Output of several data types "};
   const string string2{"to an ostringstream object:"};
   const string string3{"\ndouble: "};
   const string string4{"\n   int: "};

   constexpr double d{123.4567};
   constexpr int i{22};

   // output strings, double and int to ostringstream 
   output << string1 << string2 << string3 << d << string4 << i;               

   // call str to get string contents of the ostringstream
   cout << "output contains:\n" << output.str(); 

   // add additional characters and call str to get string
   output << "\nmore characters added";                
   cout << "\n\nafter additional stream insertions, output contains:\n"
      << output.str() << endl;
} 


/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
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
