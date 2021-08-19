// Fig. 16.2: welcome.ixx
// Primary module interface for a module named welcome.
export module welcome; // introduces the module name

import <string>; // class string is used in this module

// exporting a function
export std::string welcomeStandalone() {
   return "welcomeStandalone function called";
}

// export block exports all items in the block's braces
export {
   std::string welcomeFromExportBlock() {
      return "welcomeFromExportBlock function called";
   }
}

// exporting a namespace exports all items in the namespace
export namespace TestNamespace1 {
   std::string welcomeFromTestNamespace1() {
      return "welcomeFromTestNamespace1 function called";
   }
}

// exporting an item in a namespace exports the namespace name too
namespace TestNamespace2 {
   export std::string welcomeFromTestNamespace2() {
      return "welcomeFromTestNamespace2 function called";
   }
}




/*************************************************************************
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
