// fig20_13.cpp
// Demonstrate use of weak_ptr.
#include <fmt/format.h>
#include <iostream>
#include <memory>
#include "Author.h"
#include "Book.h"

int main() {
   // create a Book and an Author
   std::shared_ptr<Book> bookPtr(
      std::make_shared<Book>("C++ How to Program"));
   std::shared_ptr<Author> authorPtr(
      std::make_shared<Author>("Deitel & Deitel"));

   // reference the Book and Author to each other
   bookPtr->weakAuthorPtr = authorPtr;
   authorPtr->weakBookPtr = bookPtr;

   // set the shared_ptr data members to create the memory leak
   bookPtr->sharedAuthorPtr = authorPtr;
   authorPtr->sharedBookPtr = bookPtr;

   // reference count for bookPtr and authorPtr is two
   std::cout << fmt::format("Reference count for Book {} is {}\n",
      bookPtr->title, bookPtr.use_count());
   std::cout << fmt::format("Reference count for Author {} is {}\n\n",
      authorPtr->name, authorPtr.use_count());

   // access the cross references to print the data they point to
   std::cout << "Access Author name and Book title via weak_ptrs:\n";
   bookPtr->printAuthorName();
   std::cout << "\n";
   authorPtr->printBookTitle();

   // reference count for each shared_ptr is two
   std::cout << fmt::format("\nReference count for Book {} is {}\n",
      bookPtr->title, bookPtr.use_count());
   std::cout << fmt::format("Reference count for Author {} is {}\n\n",
      authorPtr->name, authorPtr.use_count());

   // the shared_ptrs go out of scope, the Book and Author are destroyed
   std::cout << "End of main. shared_ptrs going out of scope.\n";
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
