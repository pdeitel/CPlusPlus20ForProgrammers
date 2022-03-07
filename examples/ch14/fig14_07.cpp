// fig14_07.cpp
// Standard library search and sort algorithms.
#include <algorithm> // algorithm definitions
#include <array> // array class-template definition
#include <iostream>
#include <iterator> 

int main() {
   std::array values{10, 2, 17, 5, 16, 8, 13, 11, 20, 7};
   std::ostream_iterator<int> output{std::cout, " "};

   std::cout << "values contains: ";
   std::ranges::copy(values, output); // display output vector

   // locate first occurrence of 16 in values          
   if (auto loc1{std::ranges::find(values, 16)}; loc1 != values.cend()) {
      std::cout << "\n\nFound 16 at index: " << (loc1 - values.cbegin());
   }
   else { // 16 not found
      std::cout << "\n\n16 not found";
   }

   // locate first occurrence of 100 in values  
   if (auto loc2{std::ranges::find(values, 100)}; loc2 != values.cend()) {
      std::cout << "\nFound 100 at index: " << (loc2 - values.cbegin());
   }
   else { // 100 not found 
      std::cout << "\n100 not found";
   }

   // create variable to store lambda for reuse later
   auto isGreaterThan10{[](auto x) {return x > 10; }};

   // locate first occurrence of value greater than 10 in values
   auto loc3{std::ranges::find_if(values, isGreaterThan10)};

   if (loc3 != values.cend()) { // found value greater than 10
      std::cout << "\n\nFirst value greater than 10: " << *loc3
         << "\nfound at index: " << (loc3 - values.cbegin());
   }
   else { // value greater than 10 not found
      std::cout << "\n\nNo values greater than 10 were found";
   }

   // sort elements of values      
   std::ranges::sort(values);
   std::cout << "\n\nvalues after sort: ";
   std::ranges::copy(values, output);

   // use binary_search to check whether 13 exists in values
   if (std::ranges::binary_search(values, 13)) {
      std::cout << "\n\n13 was found in values";
   }
   else {
      std::cout << "\n\n13 was not found in values";
   }

   // use binary_search to check whether 100 exists in values
   if (std::ranges::binary_search(values, 100)) {
      std::cout << "\n100 was found in values";
   }
   else {
      std::cout << "\n100 was not found in values";
   }

   // determine whether all of values' elements are greater than 10
   if (std::ranges::all_of(values, isGreaterThan10)) {
      std::cout << "\n\nAll values elements are greater than 10";
   }
   else {
      std::cout << "\n\nSome values elements are not greater than 10";
   }

   // determine whether any of values' elements are greater than 10
   if (std::ranges::any_of(values, isGreaterThan10)) {
      std::cout << "\n\nSome values elements are greater than 10";
   }
   else {
      std::cout << "\n\nNo values elements are greater than 10";
   }

   // determine whether none of values' elements are greater than 10
   if (std::ranges::none_of(values, isGreaterThan10)) {
      std::cout << "\n\nNo values elements are greater than 10";
   }
   else {
      std::cout << "\n\nSome values elements are greater than 10";
   }

   // locate first occurrence of value that is not greater than 10
   auto loc4{std::ranges::find_if_not(values, isGreaterThan10)};

   if (loc4 != values.cend()) { // found a value less than or equal to 10
      std::cout << "\n\nFirst value not greater than 10: " << *loc4
         << "\nfound at index: " << (loc4 - values.cbegin());
   }
   else { // no values less than or equal to 10 were found
      std::cout << "\n\nOnly values greater than 10 were found";
   }

   std::cout << "\n";
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
