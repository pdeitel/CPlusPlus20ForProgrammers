// Fig. 9.14: CreateAndDestroy.cpp
// CreateAndDestroy class member-function definitions.
#include <iostream>
#include "fmt/format.h" // In C++20, this will be #include <format> 
#include "CreateAndDestroy.h"// include CreateAndDestroy class definition
using namespace std;

// constructor sets object's ID number and descriptive message
CreateAndDestroy::CreateAndDestroy(int ID, string messageString)
   : objectID{ID}, message{messageString} {
   cout << fmt::format("Object {}   constructor runs   {}\n",
              objectID, message);
}

// destructor                                               
CreateAndDestroy::~CreateAndDestroy() {
   // output newline for certain objects; helps readability 
   cout << fmt::format("{}Object {}   destructor runs    \n",
              (objectID == 1 || objectID == 6 ? "\n" : ""),
              objectID, message);
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
