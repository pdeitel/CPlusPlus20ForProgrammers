// Fig. 16.8: deitel.math.ixx
// Primary module interface for a module named deitel.math.
export module deitel.math; // introduces the module name

import <vector>;

export namespace deitel::math {
   // calculate the average of a vector<int>'s elements
   double average(const std::vector<int>& values);
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
