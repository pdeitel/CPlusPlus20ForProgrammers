// Fig. 9.20: Date.cpp
// Date class member-function definitions.
#include <string>
#include <fmt/format.h> // In C++20, this will be #include <format> 
#include "Date.h" // include definition of class Date from Date.h
using namespace std;

// Date constructor (should do range checking)
Date::Date(int year, int month, int day)
   : m_year{year}, m_month{month}, m_day{day} {}

// return string representation of a Date in the format yyyy-mm-dd
string Date::toString() const {
   return fmt::format("{}-{:02d}-{:02d}", m_year, m_month, m_day);
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
