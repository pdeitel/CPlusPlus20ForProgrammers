// fig11_06.cpp
// C++20 three-way comparison (spaceship) operator.
#include <compare>
#include <fmt/format.h>
#include <iostream>
#include <string>

class Time {
public:
   Time(int hr, int min, int sec) noexcept
      : m_hr{hr}, m_min{min}, m_sec{sec} {}

   std::string toString() const {
      return fmt::format("hr={}, min={}, sec={}", m_hr, m_min, m_sec);
   }

   // <=> operator automatically supports equality/relational operators
   auto operator<=>(const Time& t) const noexcept = default;
private:
   int m_hr{0};
   int m_min{0};
   int m_sec{0};
};

int main() {
   const Time t1(12, 15, 30);
   const Time t2(12, 15, 30);
   const Time t3(6, 30, 0);

   std::cout << fmt::format("t1: {}\nt2: {}\nt3: {}\n\n",
      t1.toString(), t2.toString(), t3.toString());

   // using the equality and relational operators 
   std::cout << fmt::format("t1 == t2: {}\n", t1 == t2);
   std::cout << fmt::format("t1 != t2: {}\n", t1 != t2);
   std::cout << fmt::format("t1 < t2: {}\n", t1 < t2);
   std::cout << fmt::format("t1 <= t2: {}\n", t1 <= t2);
   std::cout << fmt::format("t1 > t2: {}\n", t1 > t2);
   std::cout << fmt::format("t1 >= t2: {}\n\n", t1 >= t2);

   std::cout << fmt::format("t1 == t3: {}\n", t1 == t3);
   std::cout << fmt::format("t1 != t3: {}\n", t1 != t3);
   std::cout << fmt::format("t1 < t3: {}\n", t1 < t3);
   std::cout << fmt::format("t1 <= t3: {}\n", t1 <= t3);
   std::cout << fmt::format("t1 > t3: {}\n", t1 > t3);
   std::cout << fmt::format("t1 >= t3: {}\n\n", t1 >= t3);

   // using <=> to perform comparisons
   if ((t1 <=> t2) == 0) {
      std::cout << "t1 is equal to t2\n";
   }

   if ((t1 <=> t3) > 0) {
      std::cout << "t1 is greater than t3\n";
   }

   if ((t3 <=> t1) < 0) {
      std::cout << "t3 is less than t1\n";
   }
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
