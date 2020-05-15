// Randomly generate numbers between 1 and 1000 for user to guess.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void guessGame(); // function prototype
bool isCorrect(int, int); // function prototype

int main() {
   // srand(time(0)); // seed random number generator
   guessGame();

   return 0; // indicate successful termination

} // end main

// guessGame generates numbers between 1 and 1000
// and checks user's guess
void guessGame() {
   char response; // determines whether to continue playing

   // loop until user types 'n' to quit game
   do {
      // generate random number between 1 and 1000
      // 1 is shift, 1000 is scaling factor
      int answer{1 + rand() % 1000};

      // prompt for guess
      cout << "I have a number between 1 and 1000.\n" 
           << "Can you guess my number?\n" 
           << "Please type your first guess." << endl << "? ";
      int guess;
      cin >> guess;

      // loop until correct number
      while (!isCorrect(guess, answer)) { 
         cin >> guess;   
      }

      // prompt for another game
      cout << "\nExcellent! You guessed the number!\n"
           << "Would you like to play again (y or n)? ";
      cin >> response;

      cout << endl;
   } while (response == 'y');
} // end function guessGame

// isCorrect returns true if g equals a
// if g does not equal a, displays hint
bool isCorrect(int g, int a) {
   // guess is correct
   if (g == a) {
      return true;
   }

   // guess is incorrect; display hint
   if (g < a) {
      cout << "Too low. Try again.\n? ";
   }
   else {
      cout << "Too high. Try again.\n? ";
   }

   return false;
} // end function isCorrect



/**************************************************************************
 * (C) Copyright 1992-2012 by Deitel & Associates, Inc. and               *
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
