// Fig. 16.4: deitel.math.ixx
// Primary module interface for a module named deitel.math.
export module deitel.math; // introduces the module name

namespace deitel::math {
   // exported function square; namespace deitel::math implicitly exported
   export int square(int x) {
      return x * x;
   }

   // non-exported function cube is not implicitly exported
   int cube(int x) {
      return x * x * x;
   }
};

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
