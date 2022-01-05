// fig08_15.cpp
// Reading the Titanic dataset from a CSV file, then analyzing it.
#include <fmt/format.h> 
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <ranges>
#include <rapidcsv.h> 
#include <string>
#include <vector>

int main() {
   // load Titanic dataset; treat missing age values as NaN
   rapidcsv::Document titanic{"titanic.csv",
      rapidcsv::LabelParams{}, rapidcsv::SeparatorParams{},
      rapidcsv::ConverterParams{true}};

   // GetColumn returns column's data as a vector of the appropriate type
   auto survived{titanic.GetColumn<int>("survived")};
   auto sex{titanic.GetColumn<std::string>("sex")};
   auto age{titanic.GetColumn<double>("age")};
   auto pclass{titanic.GetColumn<int>("pclass")};

   // display first 5 rows
   std::cout << fmt::format("First five rows:\n{:<10}{:<8}{:<6}{}\n",
      "survived", "sex", "age", "class");
   for (size_t i{0}; i < 5; ++i) {
      std::cout << fmt::format("{:<10}{:<8}{:<6.1f}{}\n",
         survived.at(i), sex.at(i), age.at(i), pclass.at(i));
   }

   // display last 5 rows
   std::cout << fmt::format("\nLast five rows:\n{:<10}{:<8}{:<6}{}\n",
      "survived", "sex", "age", "class");
   const auto count{titanic.GetRowCount()};
   for (size_t i{count - 5}; i < count; ++i) {
      std::cout << fmt::format("{:<10}{:<8}{:<6.1f}{}\n",
         survived.at(i), sex.at(i), age.at(i), pclass.at(i));
   }

   // use C++20 ranges to eliminate missing values from age column
   auto removeNaN{
      age | std::views::filter([](const auto& x) {return !isnan(x);})};
   std::vector<double> cleanAge{
      std::begin(removeNaN), std::end(removeNaN)};

   // descriptive statistics for cleaned ages column
   std::sort(std::begin(cleanAge), std::end(cleanAge));
   size_t size{cleanAge.size()};
   double median{};

   if (size % 2 == 0) { // find median value for even number of items
      median = (cleanAge.at(size / 2 - 1) + cleanAge.at(size / 2)) / 2;
   }
   else { // find median value for odd number of items
      median = cleanAge.at(size / 2);
   }

   std::cout << "\nDescriptive statistics for the age column:\n"
      << fmt::format("Passengers with age data: {}\n", size)
      << fmt::format("Average age: {:.2f}\n", std::accumulate(
         std::begin(cleanAge), std::end(cleanAge), 0.0) / size)
      << fmt::format("Minimum age: {:.2f}\n", cleanAge.front())
      << fmt::format("Maximum age: {:.2f}\n", cleanAge.back())
      << fmt::format("Median age: {:.2f}\n", median);

   // passenger counts by class
   auto countClass{
      [](const auto& column, const int classNumber) {
         return std::ranges::count_if(column, 
            [classNumber](int x) {return classNumber == x;});
      }
   };

   constexpr int firstClass{1};
   constexpr int secondClass{2};
   constexpr int thirdClass{3};
   const auto firstCount{countClass(pclass, firstClass)};
   const auto secondCount{countClass(pclass, secondClass)};
   const auto thirdCount{countClass(pclass, thirdClass)};

   std::cout << "\nPassenger counts by class:\n"
      << fmt::format("1st: {}\n2nd: {}\n3rd: {}\n\n",
         firstCount, secondCount, thirdCount);

   // percentage of people who survived
   const auto survivorCount{
      std::ranges::count_if(survived, [](auto x) {return x;})
   };

   std::cout << fmt::format("Survived count: {}\nDied count: {}\n",
      survivorCount, survived.size() - survivorCount);
   std::cout << fmt::format("Percent who survived: {:.2f}%\n\n",
      100.0 * survivorCount / survived.size());

   // count who survived by male/female, 1st/2nd/3rd class
   int survivingMen{0};
   int survivingWomen{0};
   int surviving1st{0};
   int surviving2nd{0};
   int surviving3rd{0};

   for (size_t i{0}; i < survived.size(); ++i) {
      if (survived.at(i)) {
         sex.at(i) == "female" ? ++survivingWomen : ++survivingMen;

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
   std::cout << fmt::format("Female survivor percentage: {:.2f}%\n",
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
