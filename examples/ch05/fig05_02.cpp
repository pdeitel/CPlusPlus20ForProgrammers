// fig05_02.cpp
// Producing random integers in the range 1 through 6.
#include <iostream>
#include <random> // contains C++11 random-number generation features 
using namespace std;

int main() {
   // engine that produces random numbers
   default_random_engine engine{};

   // distribution that produces the int values 1-6 with equal likelihood
   uniform_int_distribution randomDie{1, 6};

   // display 10 random die rolls
   for (int counter{1}; counter <= 10; ++counter) {
      cout << randomDie(engine) << " "; 
   }

   cout << '\n';
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
