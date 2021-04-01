// fig12_06.cpp
// Demonstrating standard new throwing bad_alloc when memory
// cannot be allocated.
#include <array>
#include <iostream>
#include <memory>
#include <new> // bad_alloc class is defined here
using namespace std;

int main() {
   array<unique_ptr<double[]>, 1000> items{};
   
   // aim each unique_ptr at a big block of memory
   try {
      for (int i{0}; auto& item : items) {
         item = make_unique<double[]>(500'000'000); 
         cout << "items[" << i++ << "] points to 500,000,000 doubles\n";
      } 
   } 
   catch (bad_alloc& memoryAllocationException) {
      cerr << "Exception occurred: " 
         << memoryAllocationException.what() << '\n';
   } 
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
