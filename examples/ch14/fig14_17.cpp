// fig14_17.cpp
// Demonstrating projections with C++20 range algorithms.
#include <array> 
#include <algorithm>
#include <fmt/format.h>
#include <functional> // std::greater
#include <iostream>
#include <iterator>
#include <string> 
#include <string_view> 

class Employee {
public:
   Employee(std::string_view first, std::string_view last, int salary)
      : m_first(first), m_last(last), m_salary(salary) {}
   std::string getFirst() const {return m_first;}
   std::string getLast() const {return m_last;}
   int getSalary() const {return m_salary;}
private:
   std::string m_first;
   std::string m_last;
   int m_salary;
};

// operator<< for an Employee
std::ostream& operator<<(std::ostream& out, const Employee& e) {
   out << fmt::format("{:10}{:10}{}", 
             e.getLast(), e.getFirst(), e.getSalary());
   return out;
}

int main() {
   std::array employees{
      Employee{"Jason", "Red", 5000},
      Employee{"Ashley", "Green", 7600},
      Employee{"Matthew", "Indigo", 3587}
   };

   std::ostream_iterator<Employee> output{std::cout, "\n"};

   std::cout << "Employees:\n";
   std::ranges::copy(employees, output);

   // sort Employees by salary; {} indicates that the algorithm should
   // use its default comparison function
   std::ranges::sort(employees, {}, 
      [](const auto& e) {return e.getSalary();});
   std::cout << "\nEmployees sorted in ascending order by salary:\n";
   std::ranges::copy(employees, output);

   // sort Employees by salary in descending order
   std::ranges::sort(employees, std::ranges::greater{}, 
      &Employee::getSalary);
   std::cout << "\nEmployees sorted in descending order by salary:\n";
   std::ranges::copy(employees, output);
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
