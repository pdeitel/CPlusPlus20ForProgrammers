#include <tl/generator.hpp>
#include <catch2/catch.hpp>
#include <ranges>

template <class T>
tl::generator<T> firstn(T t) {
   T num = T{ 0 };
   while (num < t) {
      co_yield num;
      ++num;
   }
}

TEST_CASE("firstn") {
   auto i = 0;
   for (auto n : firstn(20)) {
      REQUIRE(n == i);
      ++i;
   }
}

template <class T>
tl::generator<T> iota(T t = T{ 0 }) {
   while (true) {
      co_yield t;
      t++;
   }
}

TEST_CASE("iota") {
   auto i = 0;
   for (auto n : iota<int>() | std::views::take(10)) {
      REQUIRE(n == i);
      ++i;
   }
   for (auto n : iota(10) | std::views::take(10)) {
      REQUIRE(n == i);
      ++i;
   }
}

#include <vector>
#include <string>
#include <string_view>

tl::generator<std::vector<std::string>> split_by_lines_and_whitespace(std::string_view sv) {
   std::vector<std::string> res;

   auto start = sv.begin();
   auto pos = sv.begin();

   while (pos != sv.end()) {
      if (*pos == ' ') {
         res.push_back(std::string(start, pos));
         start = pos+1;
      }
      if (*pos == '\n') {
         res.push_back(std::string(start, pos));
         co_yield res;
         res.clear();
         start = pos+1;
      }
      ++pos;
   }
}

template <class Range>
tl::generator<std::pair<std::size_t, std::ranges::range_reference_t<Range>>> enumerate(Range&& r) {
   std::size_t i = 0;
   for (auto&& val : std::forward<Range>(r)) {
      std::pair<std::size_t, std::ranges::range_reference_t<Range>> pair {i, std::forward<decltype(val)>(val)};
      co_yield pair;
      ++i;
   }
}

TEST_CASE("split") {
   auto string = R"(one two three
four five six
seven eight nine)";

   std::vector<std::vector<std::string>> result = {
      {"one", "two", "three"},
      {"four", "five", "six"},
      {"seven", "eight", "nine"}
   };
   for (auto&& [i, val] : enumerate(split_by_lines_and_whitespace(string))) {
      REQUIRE(val == result[i]);
   }
}