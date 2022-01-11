// Fig. 9.19: Date.h
// Date class declaration. Member functions are defined in Date.cpp.
#pragma once // prevent multiple inclusions of header
#include <string>

// class Date definition
class Date {
public:
   Date(int year, int month, int day);
   std::string toString() const;
private:
   int m_year;
   int m_month;
   int m_day;
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
