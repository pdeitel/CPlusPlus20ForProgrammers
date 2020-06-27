// fig08_05.cpp
// Printing string characteristics.
#include <iostream>
#include <string>
#include "fmt/format.h" // In C++20, this will be #include <format>  
using namespace std;

// display string statistics
void printStatistics(const string& s) {
   cout << fmt::format("capacity: {}\nmax size: {}\nsize: {}\nempty: {}",
      s.capacity(), s.max_size(), s.size(), s.empty());
}

int main() {
   string string1; // empty string

   cout << "Statistics before input:\n";
   printStatistics(string1);

   cout << "\n\nEnter a string: ";
   cin >> string1; // delimited by whitespace
   cout << "The string entered was: " << string1;
   cout << "\nStatistics after input:\n";
   printStatistics(string1);

   cout << "\n\nEnter a string: ";
   cin >> string1; // delimited by whitespace
   cout << "The string entered was: " << string1;
   cout << "\nStatistics after input:\n";
   printStatistics(string1);

   // append 46 characters to string1
   string1 += "1234567890abcdefghijklmnopqrstuvwxyz1234567890";
   cout << "\n\nstring1 is now: " << string1;
   cout << "\nStatistics after concatenation:\n";
   printStatistics(string1);

   string1.resize(string1.size() + 10); // add 10 elements to string1
   cout << "\n\nStatistics after resizing to add 10 characters:\n";
   printStatistics(string1);
   cout << endl;
}






/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
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
