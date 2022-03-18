// Fig. 20.10: Book.h
// Book class definition.
#pragma once
#include <memory>
#include <string>
#include <string_view>

class Author; // forward declaration of class Author

// Book class definition
class Book {
public:
   explicit Book(std::string_view bookTitle);
   ~Book();

   // print the name of this Book's Author
   void printAuthorName();

   std::string title; // title of the Book
   std::weak_ptr<Author> weakAuthorPtr; // Author of the Book    
   std::shared_ptr<Author> sharedAuthorPtr; // Author of the Book
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
