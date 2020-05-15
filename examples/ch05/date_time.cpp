// date_time.cpp
// C++20 <chrono> library date and time capabilities.
#include <iostream>
#include <chrono>
using namespace std;

int main() {
   time_of_day t{136442}; // 1:54:02 PM in seconds since midnight
   
   t.make12(); // set output format to 12-hour clock format
   cout << "t in 12-hour format is: " << t;
   t.make24(); // set output format to 24-hour clock format
   cout << "\nt in 24-hour format is: " << t;

   cout << "\n\nt.hours() is: " << t.hours();
   cout << "\nt.minutes() is: " << t.minutes();
   cout << "\nt.seconds() is: " << t.seconds() << endl;

   year_month_day date{2020y, 4m, 1d};
   cout << "\n\ndate is: " << date;
   cout << "\ndate.year() is:" << date.year();
   cout << "\ndate.month() is:" << date.month();
   cout << "\ndate.day() is:" << date.day() << endl;
}


/**************************************************************************
 * (C) Copyright 1992-2020 by Deitel & Associates, Inc. and               *
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
