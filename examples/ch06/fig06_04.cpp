// fig06_04.cpp
// Set array s to the even integers from 2 to 10.
#include <iostream>
#include <array>
using namespace std;

int main() {
   // constant can be used to specify array size
   constexpr size_t arraySize{5}; // must initialize in declaration

   array<int, arraySize> values{}; // array values has 5 elements

   for (size_t i{0}; i < values.size(); ++i) { // set the values
      values.at(i) = 2 + 2 * i;
   }

   // output contents of array s in tabular format
   for (const int value : values) {
      cout << value << "  ";
   }
   
   cout << endl;
}
