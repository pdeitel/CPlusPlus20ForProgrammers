// fig06_06.cpp
// Printing a student grade distribution as a primitive bar chart.
#include <fmt/format.h>
#include <iostream>
#include <array>

int main() {
   constexpr std::array frequencies{0, 0, 0, 0, 0, 0, 1, 2, 4, 2, 1};

   std::cout << "Grade distribution:\n";

   // for each element of frequencies, output a bar of the chart
   for (int i{0}; const int& frequency : frequencies) {
      // output bar labels ("00-09:", ..., "90-99:", "100:")
      if (i < 10) {
         std::cout << fmt::format("{:02d}-{:02d}: ",
            i * 10, (i * 10) + 9);
      }
      else {
         std::cout << fmt::format("{:>5d}: ", 100);
      }

      ++i;

      // print bar of asterisks
      for (int stars{0}; stars < frequency; ++stars) {
         std::cout << '*';
      }

      std::cout << '\n'; // start a new line of output
   }
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
