// fig17_01.cpp
// Profiling sequential and parallel sorting with the std::sort algorithm.
#include <algorithm>
#include <chrono> // for timing operations
#include <execution> // for execution policies
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

int main() {
   // set up random-number generation 
   std::random_device rd;
   std::default_random_engine engine{rd()}; 
   std::uniform_int_distribution ints{};

   std::cout << "Creating a vector v1 to hold 100,000,000 ints\n";
   std::vector<int> v1(100'000'000); // 100,000,000 element vector

   std::cout << "Filling vector v1 with random ints\n";
   std::generate(v1.begin(), v1.end(), [&](){return ints(engine);});

   // copy v1 to create identical data sets for each sort demonstration
   std::cout << "Copying v1 to vector v2 to create identical data sets\n";
   std::vector v2{v1};

   // <chrono> library features we'll use for timing
   using std::chrono::steady_clock;
   using std::chrono::duration_cast;
   using std::chrono::milliseconds;

   // sequentially sort v1
   std::cout << "\nSorting 100,000,000 ints sequentially\n";
   auto start1{steady_clock::now()}; // get current time
   std::sort(v1.begin(), v1.end()); // sequential sort
   auto end1{steady_clock::now()}; // get current time

   // calculate and display time in milliseconds
   auto time1{duration_cast<milliseconds>(end1 - start1)};
   std::cout << "Time: " << (time1.count() / 1000.0) << " seconds\n";

   // parallel sort v2
   std::cout << "\nSorting the same 100,000,000 ints in parallel\n";
   auto start2{steady_clock::now()}; // get current time
   std::sort(std::execution::par, v2.begin(), v2.end()); // parallel sort
   auto end2{steady_clock::now()}; // get current time

   // calculate and display time in milliseconds
   auto time2{duration_cast<milliseconds>(end2 - start2)};
   std::cout << "Time: " << (time2.count() / 1000.0) << " seconds\n";
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
