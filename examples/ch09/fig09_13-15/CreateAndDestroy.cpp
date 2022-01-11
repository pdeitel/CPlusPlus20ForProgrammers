// Fig. 9.14: CreateAndDestroy.cpp
// CreateAndDestroy class member-function definitions.
#include <fmt/format.h>
#include <iostream>
#include "CreateAndDestroy.h"// include CreateAndDestroy class definition

// constructor sets object's ID number and descriptive message
CreateAndDestroy::CreateAndDestroy(int ID, std::string_view message)
   : m_ID{ID}, m_message{message} {
   std::cout << fmt::format("Object {}   constructor runs   {}\n",
      m_ID, m_message);
}

// destructor                                               
CreateAndDestroy::~CreateAndDestroy() {
   // output newline for certain objects; helps readability 
   std::cout << fmt::format("{}Object {}   destructor runs    {}\n",
      (m_ID == 1 || m_ID == 6 ? "\n" : ""), m_ID, m_message);
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
