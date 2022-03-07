// Fig. 17.3: printtask.h
// Function printTask defines a task to perform in a separate thread.
#include <chrono>
#include <fmt/format.h> 
#include <iostream>
#include <sstream>
#include <string>
#include <thread>

// get current thread's ID as a string
std::string id() {
    std::ostringstream out;
    out << std::this_thread::get_id();
    return out.str();
}

// task to perform in a separate thread 
void printTask(const std::string& name, 
   std::chrono::milliseconds sleepTime) {

   // <chrono> library features we'll use for timing
   using std::chrono::steady_clock;
   using std::chrono::duration_cast;
   using std::chrono::milliseconds;

   std::cout << fmt::format("{} (ID {}) going to sleep for {} ms\n",
      name, id(), sleepTime.count());

   auto startTime{steady_clock::now()}; // get current time

   // put thread to sleep for sleepTime milliseconds 
   std::this_thread::sleep_for(sleepTime); 

   auto endTime{steady_clock::now()}; // get current time
   auto time{duration_cast<milliseconds>(endTime - startTime)};
   auto difference{duration_cast<milliseconds>(time - sleepTime)};
   std::cout << fmt::format("{} (ID {}) awakens after {} ms ({} + {})\n",
      name, id(), time.count(), sleepTime.count(), difference.count());
}


/**************************************************************************
 * (C) Copyright 1992-2021 by Deitel & Associates, Inc. and               *
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
