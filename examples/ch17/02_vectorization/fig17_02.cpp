// fig17_02.cpp
// Performing transforms with execution policies par and unseq.
#include <algorithm>
#include <chrono> // for timing operations
#include <cmath>
#include <execution> // for execution policies
#include <fmt/format.h>
#include <iostream>
#include <random>
#include <vector>

// time each std::transform call
double timeTransform(auto& policy, std::vector<int>& v) {
   // <chrono> library features we'll use for timing
   using std::chrono::steady_clock;
   using std::chrono::duration_cast;
   using std::chrono::milliseconds;

   std::vector<double> result(v.size());
   auto start{steady_clock::now()}; // get current time
   std::transform(policy, v.begin(), v.end(),
      result.begin(), [](auto& x) {return sqrt(x);});
   auto end{steady_clock::now()}; // get current time

   // calculate and display time in milliseconds
   auto time{duration_cast<milliseconds>(end - start)};
   return time.count() / 1000.0;
}

int main() {
   // set up random number generation 
   std::random_device rd;
   std::mt19937_64 random{rd()}; 
   std::uniform_int_distribution ints{0, 1000};

   std::cout << "Creating vectors\n";
   std::vector<int> v1(100'000'000); 
   std::vector<int> v2(1'000'000'000); 

   std::cout << "Filling vectors with random ints\n";
   std::generate(std::execution::par, v1.begin(), v1.end(),
      [&]() {return ints(random);});
   std::generate(std::execution::par, v2.begin(), v2.end(),
      [&]() {return ints(random);});

   std::cout << "\nCalculating square roots:\n";

   // time the transforms on 100,000,000 elements
   std::cout << fmt::format("{} elements with par\n", v1.size());
   double parTime1{timeTransform(std::execution::par, v1)};
   std::cout << fmt::format("{} elements with unseq\n", v1.size());
   double unseqTime1{timeTransform(std::execution::unseq, v1)};

   // time the transforms on 1,000,000,000 elements
   std::cout << fmt::format("{} elements with par\n", v2.size());
   double parTime2{timeTransform(std::execution::par, v2)};
   std::cout << fmt::format("{} elements with unseq\n", v2.size());
   double unseqTime2{timeTransform(std::execution::unseq, v2)};

   // display table of timing results
   std::cout << "\nExecution times (in seconds):\n\n"
      << fmt::format("{:>13}{:>21}\n", "# of elements", 
            "par (parallel)", "unseq (vectorized)")
      << fmt::format("{:>13}{:>17.3f}{:>21.3f}\n",
            v1.size(), parTime1, unseqTime1)
      << fmt::format("{:>13}{:>17.3f}{:>21.3f}\n",
            v2.size(), parTime2, unseqTime2);
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
