// Fig. 20.11: Author.cpp
// Author member-function definitions.
#include <fmt/format.h>
#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include "Author.h"
#include "Book.h"

Author::Author(std::string_view authorName) : name(authorName) {}

Author::~Author() {
   std::cout << fmt::format("Destroying Author: {}\n", name);
}

// print the title of the Book this Author wrote
void Author::printBookTitle() {
   // if weakBookPtr.lock() returns a non-empty shared_ptr
   if (std::shared_ptr<Book> bookPtr{weakBookPtr.lock()}) {
      // show the reference count increase and print the Book's title
      std::cout << fmt::format("Reference count for Book {} is {}\n",
         bookPtr->title, bookPtr.use_count());
      std::cout << fmt::format("Author {} wrote the book {}\n", 
         name, bookPtr->title);
   }
   else { // weakBookPtr points to NULL
      std::cout << "This Author has no Books.\n";
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
