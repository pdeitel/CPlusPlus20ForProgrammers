// fig16_30.cpp 
// Importing the deitel.time module and using the modularized Time class.
import <iostream>;
import deitel.time;

int main() {
   // initalize t with the object returned by getTime; cannot declare t 
   // as type Time because the type is not exported, and thus not visible
   auto t{ deitel::time::getTime() };

   // Time's toString function is reachable, even though
   // class Time was not exported by module deitel.time
   std::cout << "Time t:\n" << t.toString() << "\n\n";
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
