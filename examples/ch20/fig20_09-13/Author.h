// Fig. 20.9: Author.h
// Author class definition.
#pragma once
#include <memory>
#include <string>
#include <string_view>

class Book; // forward declaration of class Book

// Author class definition
class Author {
public:
   explicit Author(std::string_view authorName);
   ~Author();

   // print the title of the Book this Author wrote
   void printBookTitle();

   std::string name; // name of the Author
   std::weak_ptr<Book> weakBookPtr; // Book the Author wrote    
   std::shared_ptr<Book> sharedBookPtr; // Book the Author wrote
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
