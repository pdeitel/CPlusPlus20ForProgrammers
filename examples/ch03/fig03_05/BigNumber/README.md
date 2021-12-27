# BigNumber

![BigNumber build](https://travis-ci.org/Limeoats/BigNumber.svg?branch=master)
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://github.com/Limeoats/BigNumber/blob/master/LICENSE.md)

BigNumber is a C++ class that allows for the creation and computation of arbitrary-length
integers.

The maximum possible length of a BigNumber is `std::string::max_size`.

## Installation
To add BigNumber to your C++ project, you can download the `bin` folder from this repository, which 
contains the library and include files.

Then, simply include the header file in whichever file you need a BigNumber and link to the library file.

`#include "bignumber.h"`

## Usage
### `BigNumber(string)`


You can also use the `=` operator to set a BigNumber equal to an existing BigNumber, a number, or 
a string of numbers.

Examples:

    BigNumber b("5");       //BigNumber b is created with value 5.
    BigNumber c("-20");     //BigNumber c is created with value -20.
    BigNumber d("0");       //BigNumber d is created with value 0.
    BigNumber e = b;        //BigNumber e is created with value 5.
    BigNumber f = 30;       //BigNumber f is created with value 30.
    BigNumber g = "2060";   //BigNumber g is created with value 2060.
    BigNumber h(22);        //BigNumber h is created with value 22.


## Methods
### `add(BigNumber other)`
Adds another BigNumber to the current instance

`BigNumber("4").add(BigNumber("20")) => BigNumber("24")`

### `subtract(BigNumber other)`
Subtracts another BigNumber from the current instance

`BigNumber("30").subtract(BigNumber("45")) => BigNumber("-15")`

### `multiply(BigNumber other)`
Multiplies the BigNumber by another BigNumber

`BigNumber("12").multiply(BigNumber("4")) => BigNumber("48")`

### `divide(BigNumber other)`
Divides the BigNumber by another BigNumber

`BigNumber("30").divide(BigNumber("5")) => BigNumber("6")`

### `pow(int exponent)`
Raises the BigNumber to the power of the exponent

`BigNumber("2").pow(3) => BigNumber("8")`

### `getString()`
Returns the BigNumber as an std::string

`BigNumber("3824").getString() => "3824"`

### `setString(std::string newStr)`
Sets the BigNumber's internal number string to a new string

`BigNumber("2847").setString("38") => BigNumber("38")`

### `negate()`
Changes the sign of the BigNumber

    BigNumber("3").negate() => BigNumber("-3")
    BigNumber("-27").negate() => BigNumber("27")

### `equals(BigNumber other)`
Checks if the other BigNumber is equal to this one

`BigNumber("24").equals(BigNumber("28")) => false`

### `digits()`
Returns the number of digits in the BigNumber

`BigNumber("28374").digits() => 5`

### `isNegative()`
Determines whether a BigNumber is negative

`BigNumber("-278").isNegative() => true`

### `isPositive()`
Determines whether a BigNumber is positive

`BigNumber("-3").isPositive() => false`

### `isEven()`
Determines whether a BigNumber is even

`BigNumber("28472310").isEven() => true`

### `isOdd()`
Determines whether a BigNumber is odd

`BigNumber("283427").isOdd() => true`

### `abs()`
Gets the absolute value of the BigNumber

`BigNumber("-26").abs() => BigNumber("26")`


## Operator overloads
The following operators have been overloaded to work with BigNumbers:

### `<<`
Output stream operator

`std::cout << BigNumber("26") << std::endl => 26`

### `+`
Addition operator

`BigNumber("2") + BigNumber("4") => BigNumber("6")`

### `-`
Subtraction operator

`BigNumber("0") - BigNumber("2000") => BigNumber("-2000")`

### `*`
Multiplication operator

`BigNumber("-20") * BigNumber("-5") => BigNumber("100")`

### `/`
Division operator

`BigNumber("10") / BigNumber("-2") => BigNumber("-5")`

### `==`
Equal to operator

`BigNumber("24") == BigNumber("24") => true`

### `>`
Greater than operator

`BigNumber("2") > BigNumber("6") => false`

### `<`
Less than operator

`BigNumber("2") < BigNumber("6") => true`

### `>=`
Greater than or equal to operator

`BigNumber("34") >= BigNumber("22") => true`

### `<=`
Less than or equal to operator

`BigNumber("383") <= BigNumber("383") => true`

### `=`
Assignment operator

`BigNumber c("3") = BigNumber("8") => BigNumber("8")`

### `+=`
Adds and assigns to the BigNumber

`BigNumber c("4") += BigNumber("3") => BigNumber("7")`

### `-=`
Subtracts and assigns to the BigNumber

`BigNumber c("28") -= BigNumber("3") => BigNumber("25")`

### `*=`
Multiplies and assigns to the BigNumber

`BigNumber c("3") *= BigNumber("4") => BigNumber("12")`

### `/=`
Divides and assigns to the BigNumber

`BigNumber c("30") /= BigNumber("30") => BigNumer("1")`

### `++ (Prefix)`
Increments the BigNumber and returns the newly incremented number

`++BigNumber("10") => BigNumber("11")`

### `-- (Prefix)`
Decrements the BigNumber and returns the newly decremented number

`--BigNumber("34") => BigNumber("33")`

### `++ (Postfix)`
Increments the BigNumber but returns the original value

`BigNumber("20")++ => BigNumber("20")`

### `-- (Postfix)`
Decrements the BigNumber but returns the original value

`BigNumber("14")-- => BigNumber("14")`

### `[]`
Indexing operator

`BigNumber d("26")[1] => 6`

## License
This project is under the [Apache License](https://github.com/Limeoats/BigNumber/blob/master/LICENSE.md).

## Credit
The BigNumber class was created by [Mark Guerra](http://www.twitter.com/Limeoats). Visit
[Limeoats.com](http://www.limeoats.com) for more information.
