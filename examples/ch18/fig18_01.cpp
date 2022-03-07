// fig18_01.cpp
// Creating a generator coroutine with co_yield.
#include <fmt/format.h>
#include <iostream>
#include <sstream>
#include <thread> 
#include <tl/generator.hpp>

// get current thread's ID as a string
std::string id() {
   std::ostringstream out;
   out << std::this_thread::get_id();
   return out.str();
}

// coroutine that repeatedly yields the next Fibonacci value in sequence
tl::generator<int> fibonacciGenerator(int limit) {
   std::cout << fmt::format(
      "Thread {}: fibonacciGenerator started executing\n", id());

   int value1{0}; // Fibonacci(0)
   int value2{1}; // Fibonacci(1)

   for (int i{0}; i < limit; ++i) {
      co_yield value1; // yield current value of value1

      // update value1 and value2 for next iteration
      int temp{value1 + value2};
      value1 = value2;
      value2 = temp;
   }

   std::cout << fmt::format(
      "Thread {}: fibonacciGenerator finished executing\n", id());
}

int main() {
   std::cout << fmt::format("Thread {}: main begins\n", id());

   // display first 10 Fibonacci values 
   for (int i{0}; auto value : fibonacciGenerator(10)) {
      std::cout << fmt::format("Fibonacci({}) is {}\n", i++, value);
   }  

   std::cout << fmt::format("Thread {}: main ends\n", id());
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
