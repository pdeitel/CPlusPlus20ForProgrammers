// fig07_06.cpp
// C++20: Creating std::arrays with to_array.
#include <iostream>
#include <array>
using namespace std;

int main() {
   // lambda to display a collection of items
   const auto display = [](const auto& items) {
      for (const auto& item : items) {
         cout << item << " ";
      }
   };

   const int values1[3]{10, 20, 30};

   // creating a std::array from a built-in array
   const auto array1 = to_array(values1);

   cout << "array1.size() = " << array1.size() << "\narray1: ";
   display(array1); // use lambda to display contents

   // creating a std::array from an initializer list
   const auto array2 = to_array({1, 2, 3, 4});
   cout << "\n\narray2.size() = " << array2.size() << "\narray2: ";
   display(array2); // use lambda to display contents

   cout << endl;
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
