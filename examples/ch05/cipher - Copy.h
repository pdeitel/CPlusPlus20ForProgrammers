// cipher.h
// Deitel implementation of the Vigenère cipher. 
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <cctype>
#include <stdexcept>

class Cipher {
public:
   Cipher(const std::string& key = "functions") : keyPhrase{key} {

      for (const char c : keyPhrase) {
         if (tolower(c) < 'a' || tolower(c) > 'z') {
            throw std::invalid_argument(
               "key must contain only letters A-z or a-z");
         }
      }

      std::array<char, size> alphabet{};

      for (int i{0}; i < size; ++i) {
         alphabet.at(i) = 'a' + i;
      }

      square.at(0) = alphabet;

      for (int row{1}; row < size; ++row) {
         std::rotate(alphabet.begin(), alphabet.begin() + 1, alphabet.end());
         square.at(row) = alphabet;
      }

      //for (auto& row : square) {
      //   for (auto& col : row) {
      //      std::cout << col << ' ';
      //   }
      //   std::cout << std::endl;
      //}
   }

   std::string encrypt(const std::string& text) {
      const std::string key{createKey(text.length())};
      std::string s{};

      for (size_t i{0}; i < text.length(); ++i) {
         const bool upper = std::isupper(text.at(i));
         const char current = std::tolower(text.at(i));
         if ('a' <= current && current <= 'z') {
            const int keyCounter{i % key.length()};
            const int row{tolower(key.at(i)) - 'a'};
            const int col{current - 'a'};
            const char substitute{square.at(row).at(col)};
            s += (upper ? std::toupper(substitute) : substitute);
         }
         else {
            s += text.at(i); // pass through numbers and punctuation
         }
      }
      return s;
   }

   std::string decrypt(const std::string& text) {
      const std::string key{createKey(text.length())};
      std::string s;

      for (size_t i{0}; i < text.length(); ++i) {
         const bool upper = std::isupper(text.at(i));
         const char current = std::tolower(text.at(i));

         if ('a' <= current && current <= 'z') {
            const int row = key.at(i) - 'a';
            int column{-1};
            for (size_t col{0}; col < square.at(row).size(); ++col) {
               if (square.at(row).at(col) == current) {
                  column = col;
                  break;
               }
            }
            const char original{static_cast<char>('a' + column)};
            s += (upper ? std::toupper(original) : original);
         }
         else {
            s += current; // pass through numbers and punctuation
         }
      }
      return s;
   }
private:
   constexpr static int size{26};
   const std::string keyPhrase;
   std::array<std::array<char, 26>, 26> square;

   std::string createKey(int length) {
      std::ostringstream os;
      std::fill_n(std::ostream_iterator<std::string>(os), length / keyPhrase.size() + 1, keyPhrase);
      //std::cout << os.str().substr(0, length) << std::endl;
      return os.str();
   }
};

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
