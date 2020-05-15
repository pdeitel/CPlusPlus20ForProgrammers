// fig05_06.cpp
// Using a C++11 random-number generation engine and distribution
// to roll a six-sided die more securely.
#include <iostream>
#include <iomanip>
#include <random> // contains C++11 random number generation features 
#include <ctime>
#include "gsl/gsl"
using namespace std;

int main() {
   // use the default random-number generation engine to                
   // produce uniformly distributed pseudorandom int values from 1 to 6 
   default_random_engine engine{gsl::narrow_cast   <unsigned int>(time(0))};
   const uniform_int_distribution<int> randomInt{1, 6};

   // loop 10 times
   for (int counter{1}; counter <= 10; ++counter) {
      // pick random number from 1 to 6 and output it
      cout << randomInt(engine) << " ";
   }
   
   cout << endl;
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
