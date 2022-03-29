// fig20_08.cpp
// Demonstrate shared_ptrs.
#include <algorithm>
#include <fmt/format.h>
#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

// class Book
class Book {
public:
   explicit Book(std::string_view bookTitle) : title{bookTitle} {}
   ~Book() { std::cout << fmt::format("Destroying Book: {}\n", title); }
   std::string title; // title of the Book
};

// a custom delete function for a pointer to a Book
void deleteBook(Book* book) {
   std::cout << "Custom deleter for a Book, ";
   delete book; // delete the Book pointer
}

// compare the titles of two Books for sorting
bool compareTitles(
   std::shared_ptr<Book> ptr1, std::shared_ptr<Book> ptr2) {
   return (ptr1->title < ptr2->title);
}

int main() {
   // create a shared_ptr to a Book and display the reference count
   std::shared_ptr<Book> bookPtr{
      std::make_shared<Book>("C++ How to Program")};
   std::cout << fmt::format("Reference count for Book {} is: {}\n",
      bookPtr->title, bookPtr.use_count());

   // create another shared_ptr to the Book and display reference count
   std::shared_ptr<Book> bookPtr2{bookPtr};
   std::cout << fmt::format("Reference count for Book {} is: {}\n",
      bookPtr->title, bookPtr.use_count());

   // change the Book’s title and access it from both pointers
   bookPtr2->title = "Java How to Program";
   std::cout << fmt::format(
      "Updated Book title:\nbookPtr: {}\nbookPtr2: {}\n",
      bookPtr->title, bookPtr2->title);

   // create a std::vector of shared_ptrs to Books (BookPtrs)
   std::vector<std::shared_ptr<Book>> books{
      std::make_shared<Book>("C How to Program"),
      std::make_shared<Book>("Intro to Python"),
      std::make_shared<Book>("C# How to Program"),
      std::make_shared<Book>("C++ How to Program")};

   // print the Books in the vector
   std::cout << "\nBooks before sorting:\n";
   for (auto book : books) {
      std::cout << book->title << "\n";
   }

   // sort the vector by Book title and print the sorted vector
   std::sort(books.begin(), books.end(), compareTitles);
   std::cout << "\nBooks after sorting:\n";
   for (auto book : books) {
      std::cout << book->title << "\n";
   }

   // create a shared_ptr with a custom deleter
   std::cout << "\nshared_ptr with a custom deleter.\n";
   std::shared_ptr<Book> bookPtr3{
      new Book("Android How to Program"), deleteBook};
   bookPtr3.reset(); // release the Book this shared_ptr manages

   // shared_ptrs are going out of scope
   std::cout << "\nEnd of main: shared_ptr objects going out of scope.\n";
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
