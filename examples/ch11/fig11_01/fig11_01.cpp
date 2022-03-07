// fig11_01.cpp
// Standard library string class test program.
#include <fmt/format.h>
#include <iostream>
#include <string> 
#include <string_view> 

int main() {
   std::string s1{"happy"}; // initialize string from char*
   std::string s2{" birthday"}; // initialize string from char*
   std::string s3; // creates an empty string
   std::string_view v{"hello"}; // initialize string_view from char*

   // output strings and string_view
   std::cout << "s1: \"" << s1 << "\"; s2: \"" << s2
      << "\"; s3: \"" << s3 << "\"; v: \"" << v << "\"\n\n";

   // test overloaded equality and relational operators
   std::cout << "The results of comparing s2 and s1:\n"
      << fmt::format("s2 == s1: {}\n", s2 == s1)
      << fmt::format("s2 != s1: {}\n", s2 != s1)
      << fmt::format("s2 > s1: {}\n", s2 > s1)
      << fmt::format("s2 < s1: {}\n", s2 < s1)
      << fmt::format("s2 >= s1: {}\n", s2 >= s1)
      << fmt::format("s2 <= s1: {}\n\n", s2 <= s1);

   // test string member function empty 
   std::cout << "Testing s3.empty():\n";

   if (s3.empty()) {
      std::cout << "s3 is empty; assigning s1 to s3;\n";
      s3 = s1; // assign s1 to s3
      std::cout << fmt::format("s3 is \"{}\"\n\n", s3);
   }

   // test overloaded string concatenation assignment operator
   s1 += s2; // test overloaded concatenation
   std::cout << fmt::format("s1 += s2 yields s1 = {}\n\n", s1);

   // test string concatenation with a C string
   s1 += " to you";
   std::cout << fmt::format("s1 += \" to you\" yields s1 = {}\n\n", s1);

   // test string concatenation with a C++14 string-object literal
   using namespace std::string_literals;
   s1 += ", have a great day!"s; // s after " for string-object literal
   std::cout << fmt::format(
      "s1 += \", have a great day!\"s yields\ns1 = {}\n\n", s1);

   // test string member function substr
   std::cout << fmt::format("{} {}\n{}\n\n",
      "The substring of s1 starting at location 0 for",
      "14 characters, s1.substr(0, 14), is:", s1.substr(0, 14));

   // test substr "to-end-of-string" option
   std::cout << fmt::format("{} {}\n{}\n\n",
      "The substring of s1 starting at",
      "location 15, s1.substr(15), is:", s1.substr(15));

   // test copy constructor
   std::string s4{s1};
   std::cout << fmt::format("s4 = {}\n\n", s4);

   // test overloaded copy assignment (=) operator with self-assignment
   std::cout << "assigning s4 to s4\n";
   s4 = s4;
   std::cout << fmt::format("s4 = {}\n\n", s4);

   // test string's string_view constructor
   std::cout << "initializing s5 with string_view v\n";
   std::string s5{v};
   std::cout << fmt::format("s5 is {}\n\n", s5);

   // test using overloaded subscript operator to create lvalue
   s1[0] = 'H';
   s1[6] = 'B';
   std::cout << fmt::format("{}:\n{}\n\n",
      "after s1[0] = 'H' and s1[6] = 'B', s1 is", s1);

   // test index out of range with string member function "at"   
   try {
      std::cout << "Attempt to assign 'd' to s1.at(100) yields:\n";
      s1.at(100) = 'd'; // ERROR: subscript out of range            
   }
   catch (const std::out_of_range& ex) {
      std::cout << fmt::format("An exception occurred: {}\n", ex.what());
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
