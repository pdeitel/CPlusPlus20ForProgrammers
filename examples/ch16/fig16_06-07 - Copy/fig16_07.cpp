// fig16_07.cpp
// Using the privatefragmentdemo module's Integer class.
import <iostream>;
import privatefragmentdemo;

int main() {
   Integer i{100}; 

   // get the int value from i's underlying Implementation object
   std::cout << "Integer i contains: " << i.getValue() << "\n";

   // getImplementationCopy returns a unique_ptr<Implementation>;
   // compiles because we do not explicitly mention class Implementation
   auto impl{i.getImplementationCopy()};
}




 /*************************************************************************
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
