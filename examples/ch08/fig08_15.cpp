// fig08_15.cpp
// Reading the Titanic dataset from a CSV file, then analyzing it.
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>
#include "fmt/format.h" // In C++20, this will be #include <format>  
#include "rapidcsv.h"
using namespace std;

int main() {
   // load Titanic dataset; treat missing age values as NaN
   rapidcsv::Document titanic("titanic.csv",
      rapidcsv::LabelParams{}, rapidcsv::SeparatorParams{},
      rapidcsv::ConverterParams{true});

   // get data by column name
   auto survived{titanic.GetColumn<int>(R"("survived")")};
   auto sex{titanic.GetColumn<string>(R"("sex")")};
   auto age{titanic.GetColumn<double>(R"("age")")};
   auto pclass{titanic.GetColumn<int>(R"("pclass")")};

   // remove quotes from strings "female" and "male"
   for (string& item : sex) {
      item.erase(0, 1).pop_back();
   }

   // display first 5 rows
   cout << fmt::format("First five rows:\n{:<10}{:<8}{:<6}{}\n",
      "survived", "sex", "age", "class");
   for (size_t i{0}; i < 5; ++i) {
      cout << fmt::format("{:<10}{:<8}{:<6.1f}{}\n",
         survived.at(i), sex.at(i), age.at(i), pclass.at(i));
   }

   // display last 5 rows
   cout << fmt::format("\nLast five rows:\n{:<10}{:<8}{:<6}{}\n",
      "survived", "sex", "age", "class");
   auto count{titanic.GetRowCount()};
   for (size_t i{count - 5}; i < count; ++i) {
      cout << fmt::format("{:<10}{:<8}{:<6.1f}{}\n",
         survived.at(i), sex.at(i), age.at(i), pclass.at(i));
   }

   // use C++20 ranges to eliminate missing values from age column
   auto removeNaN =
      age | views::filter([](const auto& x) {return !isnan(x); });
   vector<double> cleanAge{begin(removeNaN), end(removeNaN)};

   // descriptive statistics for cleaned ages column
   sort(begin(cleanAge), end(cleanAge));
   size_t size{cleanAge.size()};
   double median{};

   if (size % 2 == 0) { // find median value for even number of items
      median = (cleanAge.at(size / 2 - 1) + cleanAge.at(size / 2)) / 2;
   }
   else { // find median value for odd number of items
      median = cleanAge.at(size / 2);
   }

   cout << "\nDescriptive statistics for the age column:\n"
      << fmt::format("Passengers with age data: {}\n", size)
      << fmt::format("Average age: {:.2f}\n",
         accumulate(begin(cleanAge), end(cleanAge), 0.0) / size)
      << fmt::format("Minimum age: {:.2f}\n", cleanAge.front())
      << fmt::format("Maximum age: {:.2f}\n", cleanAge.back())
      << fmt::format("Median age: {:.2f}\n", median);

   // passenger counts by class
   auto countClass = [](const auto& column, const int classNumber) {
      auto filterByClass{column
         | views::filter([classNumber](auto x) {return classNumber == x;})
         | views::transform([](auto x) {return 1;})};
      return accumulate(begin(filterByClass), end(filterByClass), 0);
   };

   constexpr int firstClass{1};
   constexpr int secondClass{2};
   constexpr int thirdClass{3};
   const int firstCount{countClass(pclass, firstClass)};
   const int secondCount{countClass(pclass, secondClass)};
   const int thirdCount{countClass(pclass, thirdClass)};

   cout << "\nPassenger counts by class:\n"
      << fmt::format("1st: {}\n2nd: {}\n3rd: {}\n\n",
            firstCount, secondCount, thirdCount);

   // percentage of people who survived
   auto survivors = survived | views::filter([](auto x) {return x;});
   int survivorCount{accumulate(begin(survivors), end(survivors), 0)};

   cout << fmt::format("Survived count: {}\nDied count: {}\n", 
              survivorCount, survived.size() - survivorCount);
   cout << fmt::format("Percent who survived: {:.2f}%\n\n",
              100.0 * survivorCount / survived.size());
   
   // count who survived by male/female, 1st/2nd/3rd class
   int survivingMen{0};
   int survivingWomen{0};
   int surviving1st{0};
   int surviving2nd{0};
   int surviving3rd{0};

   for (size_t i{0}; i < survived.size(); ++i) {
      if (survived.at(i)) {
         sex.at(i) == "female"s ? ++survivingWomen : ++survivingMen;

         if (firstClass == pclass.at(i)) {
            ++surviving1st;
         }
         else if (secondClass == pclass.at(i)) {
            ++surviving2nd;
         }
         else { // third class
            ++surviving3rd;
         }
      }
   }
  
   // percentages who survived by male/female, 1st/2nd/3rd class
   cout << fmt::format("Female survivor percentage: {:.2f}%\n",
              100.0 * survivingWomen / survivorCount)
        << fmt::format("Male survivor percentage: {:.2f}%\n\n",
              100.0 * survivingMen / survivorCount)
        << fmt::format("1st class survivor percentage: {:.2f}%\n",
              100.0 * surviving1st / survivorCount)
        << fmt::format("2nd class survivor percentage: {:.2f}%\n",
              100.0 * surviving2nd / survivorCount)
        << fmt::format("3rd class survivor percentage: {:.2f}%\n",
              100.0 * surviving3rd / survivorCount);
}



/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
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
