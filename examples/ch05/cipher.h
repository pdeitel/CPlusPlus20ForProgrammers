// cipher.h
// Deitel implementation of the Vigenère cipher. 
#pragma once
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <gsl/gsl>

class Cipher {
public:
   Cipher() noexcept {
      std::array<char, size> alphabet{};

      for (int i{0}; i < size; ++i) {
         alphabet.at(i) = 'a' + i;
      }

      square.at(0) = alphabet;

      for (int row{1}; row < size; ++row) {
         std::rotate(alphabet.begin(), alphabet.begin() + 1, alphabet.end());
         square.at(row) = alphabet;
      }
   }

   std::string encrypt(const std::string& plainText, 
      const std::string& secret) {
      checkKey(secret); // ensure only letters in secret

      std::string cipherText{};
      size_t keyCounter{0};

      for (size_t i{0}; i < plainText.length(); ++i) {
         const bool upper = std::isupper(plainText.at(i));
         const char current = std::tolower(plainText.at(i));
         if ('a' <= current && current <= 'z') {
            const int row{tolower(secret.at(keyCounter)) - 'a'};
            keyCounter = (keyCounter + 1) % secret.length();
            const int col{current - 'a'};
            const char substitute{square.at(row).at(col)};
            cipherText += (upper ? std::toupper(substitute) : substitute);
         }
         else {
            cipherText += plainText.at(i); // pass through numbers and punctuation
         }
      }
      return cipherText;
   }

   std::string decrypt(const std::string& text,
      const std::string& secret) {
      checkKey(secret); // ensure only letters in secret

      std::string plainText;
      size_t keyCounter{0};

      for (size_t i{0}; i < text.length(); ++i) {
         const bool upper = std::isupper(text.at(i));
         const char current = std::tolower(text.at(i));

         if ('a' <= current && current <= 'z') {
            const int row{std::tolower(secret.at(keyCounter)) - 'a'};
            keyCounter = (keyCounter + 1) % secret.length();
            int column{-1};
            for (size_t col{0}; col < square.at(row).size(); ++col) {
               if (square.at(row).at(col) == current) {
                  column = gsl::narrow_cast<int>(col);
                  break;
               }
            }
            const char original{gsl::narrow_cast<char>('a' + column)};
            plainText += (upper ? std::toupper(original) : original);
         }
         else {
            plainText += current; // pass through numbers and punctuation
         }
      }
      return plainText;
   }
private:
   constexpr static int size{26};
   std::array<std::array<char, 26>, 26> square;

   // checks that secret key contains only letters
   void checkKey(std::string secret) {
      for (int i{0}; i < secret.size(); ++i) {
         if (tolower(secret.at(i)) < 'a' || tolower(secret.at(i)) > 'z') {
            throw std::invalid_argument(
               "key must contain only letters A-Z or a-z");
         }
      }
   }
};

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
