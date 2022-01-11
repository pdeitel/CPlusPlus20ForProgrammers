// Fig. 9.13: CreateAndDestroy.h
// CreateAndDestroy class definition.
// Member functions defined in CreateAndDestroy.cpp.
#pragma once // prevent multiple inclusions of header
#include <string>
#include <string_view>

class CreateAndDestroy {
public:
   CreateAndDestroy(int ID, std::string_view message); // constructor
   ~CreateAndDestroy(); // destructor                
private:
   int m_ID; // ID number for object
   std::string m_message; // message describing object
};




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
