// fig12_07.cpp
// Demonstrating set_new_handler.
#include <array>
#include <fmt/format.h>
#include <iostream>
#include <memory>
#include <new> // set_new_handler is defined here

// handle memory allocation failure      
void customNewHandler() {
   std::cerr << "customNewHandler was called\n";
   std::exit(EXIT_FAILURE);
}

int main() {
   std::array<std::unique_ptr<double[]>, 1000> items{};

   // specify that customNewHandler should be called on 
   // memory allocation failure                         
   std::set_new_handler(customNewHandler);

   // aim each unique_ptr at a big block of memory
   for (int i{0}; auto & item : items) {
      item = std::make_unique<double[]>(500'000'000);
      std::cout << fmt::format(
         "items[{}] points to 500,000,000 doubles\n", i++);
   }
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
