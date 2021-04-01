// fig12_03.cpp
// Rethrowing an exception.
#include <iostream>
#include <exception>
using namespace std;

// throw, catch and rethrow exception
void throwException() {
   // throw exception and catch it immediately
   try {
      cout << "  Function throwException throws an exception\n";
      throw exception{}; // generate exception
   } 
   catch (const exception&) { // handle exception
      cout << "  Exception handled in function throwException"
         << "\n  Function throwException rethrows exception";
      throw; // rethrow exception for further processing
   } 

   cout << "This should not print\n";
} 

int main() {
   // throw exception
   try {
      cout << "\nmain invokes function throwException\n";
      throwException();
      cout << "This should not print\n";
   } 
   catch (const exception&) { // handle exception
      cout << "\n\nException handled in main\n";
   } 

   cout << "Program control continues after catch in main\n";
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
