// Fig. 16.7: deitel.math-impl.cpp
// Module implementation unit for the module deitel.math.
module deitel.math; // this file's contents belong to module deitel.math

import <numeric>;
import <vector>;

namespace deitel::math {
   // average function's implementation
   double average(const std::vector<int>& values) {
      double total{std::accumulate(values.begin(), values.end(), 0.0)};
      return total / values.size();
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
