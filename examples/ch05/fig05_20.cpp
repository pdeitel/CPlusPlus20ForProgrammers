// fig15_20.cpp
// Encrypting and decrypting text with a Vigenère cipher. 
#include "cipher.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
   string plainText;
   cout << "Enter the text to encrypt:\n";
   getline(cin, plainText);

   string secretKey;
   cout << "\nEnter the secret key:\n";
   getline(cin, secretKey);

   Cipher cipher; 

   // encrypt plainText using secretKey
   string cipherText{cipher.encrypt(plainText, secretKey)};
   cout << "\nEncrypted:\n   " << cipherText << endl;

   // decrypt cipherText
   cout << "\nDecrypted:\n   "  
      << cipher.decrypt(cipherText, secretKey) << endl;
   
   // decrypt ciphertext entered by the user
   cout << "\nEnter the ciphertext to decipher:\n";
   getline(cin, cipherText);
   cout << "\nDecrypted:\n   " 
      << cipher.decrypt(cipherText, secretKey) << endl;
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
