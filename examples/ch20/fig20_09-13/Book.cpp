// Fig. 20.12: Book.cpp
// Book member-function definitions.
#include <fmt/format.h>
#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include "Author.h"
#include "Book.h"

Book::Book(std::string_view bookTitle) : title(bookTitle) {}

Book::~Book() {
   std::cout << fmt::format("Destroying Book: {}\n", title);
}

// print the name of this Book's Author
void Book::printAuthorName() {
   // if weakAuthorPtr.lock() returns a non-empty shared_ptr
   if (std::shared_ptr<Author> authorPtr{weakAuthorPtr.lock()}) {
      // show the reference count increase and print the Author's name
      std::cout << fmt::format("Reference count for Author {} is {}\n",
         authorPtr->name, authorPtr.use_count());
      std::cout << fmt::format("The book {} was written by {}\n",
         title, authorPtr->name);
   }
   else { // weakAuthorPtr points to NULL
      std::cout << "This Book has no Author.\n";
   }
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
