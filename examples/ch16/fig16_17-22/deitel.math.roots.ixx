// Fig. 16.19: deitel.math.roots.ixx
// Primary module interface unit deitel.math.roots. 
export module deitel.math.roots;

import <cmath>;

export namespace deitel::math {
   double squareRoot(double x) { return std::sqrt(x); }
   double cubeRoot(double x) { return std::cbrt(x); }
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
