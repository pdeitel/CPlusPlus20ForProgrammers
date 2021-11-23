/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Mark Guerra
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
 * to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <sstream>
#include <stack>
#include <iostream>

#include "bignumber.h"


BigNumber::BigNumber(std::string number) :
        _numberString(number)
{
}

BigNumber::BigNumber(long long number) :
    _numberString(std::to_string(number))
{}

BigNumber BigNumber::add(BigNumber other) {
    BigNumber b1 = other > *this ? other : *this;
    BigNumber b2 = other > *this ? *this : other;
    if (b1.isNegative() || b2.isNegative()) {
        if (b1.isNegative() && b2.isNegative()) {
            return b1.negate().add(b2.negate()).negate();
        }
        else if (b1.isNegative() && !b2.isNegative()) {
            return b1.negate().subtract(b2).negate();
        }
        else {
            return b2.negate().subtract(b1).negate();
        }
    }
    std::string results;
    int carry = 0;
    int diff = int(b1._numberString.size() - b2._numberString.size());
    for (int i = 0; i < diff; ++i) {
        b2._numberString.insert(b2._numberString.begin(), '0');
    }
    for (int i = int(b1._numberString.size() - 1); i >= 0; --i) {
        int sum = (b1._numberString[i] - '0') + (b2._numberString[i] - '0') + carry;
        carry = 0;
        if (sum <= 9 || i == 0) {
            results.insert(0, std::to_string(sum));
        }
        else {
            results.insert(0, std::to_string(sum % 10));
            carry = 1;
        }
    }
    return BigNumber(results);
}

BigNumber BigNumber::addll(const long long &other) {
    return this->add(BigNumber(other));
}

BigNumber BigNumber::addstr(const std::string &other) {
    return this->add(BigNumber(other));
}


BigNumber BigNumber::subtract(BigNumber other) {
    BigNumber b1 = *this, b2 = other;
    if (b1.isNegative() || b2.isNegative()) {
        if (b1.isNegative() && b2.isNegative()) {
            return b1.negate().add(b2.negate()).negate();
        }
        else if (b1.isNegative() && !b2.isNegative()) {
            return b1.negate().add(b2).negate();
        }
        else {
            return b2.negate().add(b1);
        }
    }
    std::string results;
    int n = 0, p = 0;
    bool takeOffOne = false;
    bool shouldBeTen = false;

    if (b1 < b2) {
        //Negative answer
        std::string t = b2.subtract(*this).negate().getString();
        for (unsigned int i = 1; i < t.length(); ++i) {
            if (t[i] != '0') break;
            t.erase(1, 1);
        }
        return BigNumber(t);
    }

    //This next if-block fixes the case where the digit difference is greater than 1
    //100 - 5 is an example. This code adds 0's to make it, for example, 100 - 05, which
    //allows the rest of the subtraction code to work.
    if (b1._numberString.size() - b2.getString().size() > 1) {
        for (unsigned long i = 0; i < b1._numberString.size() - b2.getString().size() - 1; ++i) {
            b2._numberString.insert(b2._numberString.begin(), '0');
        }
    }
    int i = int(b1._numberString.size() - 1);
    for (int j = int(b2._numberString.size() - 1); j >= 0; --j) {
        if (((b1._numberString[i] - '0') < (b2._numberString[j] - '0')) && i > 0) {
            n = char((b1._numberString[i] - '0') + 10);
            takeOffOne = true;
            if (j > 0 || b1._numberString[i - 1] != '0') {
                p = char((b1._numberString[i - 1] - '0') - 1);
                if (p == -1) {
                    p = 9;
                    shouldBeTen = true;
                }
                takeOffOne = false;
            }
            if (shouldBeTen) {
                int index = i - 1;
                for (int a = i - 1; (b1._numberString[a] - '0') == 0; --a) {
                    b1._numberString[a] = static_cast<char>(p + '0');
                    --index;
                }
                int t = (b1._numberString[index] - '0') - 1;
                b1._numberString[index] = static_cast<char>(t + '0');
            }
            b1._numberString[i - 1] = static_cast<char>(p + '0');
            shouldBeTen = false;
        }
        std::stringstream ss;
        if (((b1._numberString[i] - '0') == (b2._numberString[j] - '0'))) {
            ss << "0";
        }
        else {
            if (n <= 0) {
                ss << ((b1._numberString[i] - '0') - (b2._numberString[j] - '0'));
            }
            else {
                ss << (n - (b2._numberString[j] - '0'));
            }
        }

        results.insert(0, ss.str());
        --i;
        n = 0;
    }
    if (takeOffOne) {
        std::string number = "";
        for (int j = b1._numberString.length() - b2._numberString.length() - 1; j >= 0; --j) {
            if (b1._numberString[j] == '0') {
                number += "0";
                continue;
            }
            else {
                number.insert(number.begin(), b1._numberString[j]);
                int t = atoi(number.c_str());
                --t;
                b1._numberString.replace(0, number.size(), std::to_string(t));
                break;
            }
        }
    }
    while (i >= 0) {
        std::stringstream ss;
        if (i == 0) {
            if (b1._numberString[i] - '0' != 0) {
                ss << (b1._numberString[i] - '0');
                results.insert(0, ss.str());
            }
        }
        else {
            ss << (b1._numberString[i] - '0');
            results.insert(0, ss.str());
        }

        --i;
    }
    //In the case of all 0's, we only want to return one of them
    if (results.find_first_not_of('0') == std::string::npos) {
        results = "0";
    }
    else if (results[0] == '0') {
        int index = results.find_first_not_of('0');
        results = results.substr(index, results.length() - 1);
    }
    return BigNumber(results);
}

BigNumber BigNumber::subtractll(const long long &other) {
    return this->subtract(BigNumber(other));
}

BigNumber BigNumber::subtractstr(const std::string &other) {
    return this->subtract(BigNumber(other));
}

BigNumber BigNumber::multiply(BigNumber other) {
    BigNumber b1 = other > *this ? other : *this;
    BigNumber b2 = other > *this ? *this : other;
    if (b1.isNegative() || b2.isNegative()) {
        if (b1.isNegative() && b2.isNegative()) {
            return b1.negate().multiply(b2.negate());
        }
        else if (b1.isNegative() && !b2.isNegative()) {
            return b1.negate().multiply(b2).negate();
        }
        else {
            return b2.negate().multiply(b1).negate();
        }
    }
    if (b1 == 0 || b2 == 0) return 0;
    int carry = 0;
    int zeroCounter = 0;
    BigNumber b = 0;
    
    for (unsigned int i = 0; i < b1._numberString.size() - b2._numberString.size(); ++i) {
        b2._numberString.insert(b2._numberString.begin(), '0');
    }
    for (long long int i = (b2._numberString.size() - 1); i >= 0; --i) {
        std::string rr;
        for (long long int j = int(b1._numberString.size() - 1); j >= 0; --j) {
            int val = ((b2._numberString[i] - '0') * (b1._numberString[j] - '0')) + carry;
            carry = 0;
            if (val > 9 && j != 0) {
                carry = val / 10;
                rr.insert(0, std::to_string(val % 10));
            }
            else {
                rr.insert(0, std::to_string(val));
            }
        }
        if (zeroCounter > 0) {
            for (int x = 0; x < zeroCounter; ++x) {
                rr.append("0");
            }
        }
        ++zeroCounter;
        b += BigNumber(rr);
    }
    if (b._numberString.find_first_not_of('0') != std::string::npos) {
        b.setString(b._numberString.erase(0, b._numberString.find_first_not_of('0')));
    }
    else {
        //In the case of all 0's, we only want to return one of them
        b.setString("0");
    }
    return b;
}

BigNumber BigNumber::multiplyll(const long long &other) {
    if (other == 0)
        return 0;
    if (other == 1)
        return *this;
    auto original = *this;
    for (auto i = 0; i < other - 1; ++i) {
        *this += original;
    }
    return *this;
}

BigNumber BigNumber::multiplystr(const std::string &other) {
    return this->multiply(BigNumber(other));
}

BigNumber BigNumber::divide(BigNumber other) {
    if (other == 0) {
        std::cerr << "You cannot divide by 0!" << std::endl;
    }
    BigNumber b1 = *this, b2 = other;
    bool sign = false;
    if (b1.isNegative() && b2.isNegative()) {
        b1.negate();
        b2.negate();
    }
    else if (b1.isNegative() && !b2.isNegative()) {
        b1.negate();
        sign = true;
    }
    else if (!b1.isNegative() && b2.isNegative()) {
        b2.negate();
        sign = true;
    }
    BigNumber quotient = 0;
    while (b1 >= b2) {
        b1 -= b2;
        ++quotient;
    }
    if (sign) quotient.negate();
    return quotient;
}

BigNumber BigNumber::dividell(const long long &other) {
    return this->divide(BigNumber(other));
}

BigNumber BigNumber::dividestr(const std::string &other) {
    return this->divide(BigNumber(other));
}

BigNumber BigNumber::pow(int exponent) {
    if (exponent < 0) std::cerr << "Powers less than 0 are not supported" << std::endl;
    if (exponent == 0) return BigNumber("1");
    if (exponent == 1) return *this;
    BigNumber result = 1, base = *this;
    while (exponent) {
        if (exponent & 1) {
            result *= base;
        }
        exponent >>= 1;
        base *= base;
    }
    return result;
}

std::string BigNumber::getString() {
    return this->_numberString;
}

BigNumber BigNumber::setString(const std::string &newStr) {
    this->_numberString = newStr;
    return *this;
}

BigNumber BigNumber::negate() {
    if (this->_numberString[0] == '-') {
        this->_numberString.erase(0, 1);
    }
    else {
        this->_numberString.insert(this->_numberString.begin(), '-');
    }
    return *this;
}

BigNumber BigNumber::trimLeadingZeros() {
    BigNumber b = *this;
    if (b._numberString.find_first_not_of('0') != std::string::npos) {
        b.setString(b._numberString.erase(0, b._numberString.find_first_not_of('0')));
    }
    return b;
}

bool BigNumber::equals(const BigNumber &other) {
    return this->_numberString == other._numberString;
}

bool BigNumber::equals(const long long &other) {
    return this->getString() == std::to_string(other);
}

bool BigNumber::equals(const std::string &other) {
    return this->getString() == other;
}

unsigned int BigNumber::digits() {
    return this->_numberString.length() - static_cast<int>(this->isNegative());
}

bool BigNumber::isNegative() const {
    return this->_numberString[0] == '-';
}

bool BigNumber::isPositive() {
    return !this->isNegative();
}

bool BigNumber::isEven() {
    return this->_numberString[this->_numberString.length() - 1] % 2 == 0;
}

bool BigNumber::isOdd() {
    return !this->isEven();
}

BigNumber BigNumber::abs() const {
    return BigNumber(this->_numberString.substr(static_cast<unsigned int>(this->isNegative())));
}

std::ostream &operator<<(std::ostream &os, const BigNumber &num) {
    os << num._numberString;
    return os;
}

BigNumber operator+(BigNumber b1, const BigNumber &b2) {
    return b1.add(b2);
}

BigNumber operator+(BigNumber b1, const long long &b2) {
    return b1.addll(b2);
}

BigNumber operator+(BigNumber b1, const std::string &b2) {
    return b1.addstr(b2);
}

BigNumber operator-(BigNumber b1, const BigNumber &b2) {
    return b1.subtract(b2);
}

BigNumber operator-(BigNumber b1, const long long &b2) {
    return b1.subtractll(b2);
}

BigNumber operator-(BigNumber b1, const std::string &b2) {
    return b1.subtractstr(b2);
}

BigNumber operator*(BigNumber b1, const BigNumber &b2) {
    return b1.multiply(b2);
}

BigNumber operator*(BigNumber b1, const long long &b2) {
    return b1.multiplyll(b2);
}

BigNumber operator*(BigNumber b1, const std::string &b2) {
    return b1.multiplystr(b2);
}

BigNumber operator/(BigNumber b1, const BigNumber &b2) {
    return b1.divide(b2);
}

BigNumber operator/(BigNumber b1, const long long &b2) {
    return b1.dividell(b2);
}

BigNumber operator/(BigNumber b1, const std::string &b2) {
    return b1.dividestr(b2);
}

BigNumber operator^(BigNumber b1, const int &b2) {
    return b1.pow(b2);
}

bool operator==(BigNumber b1, const BigNumber &b2) {
    return b1.equals(b2);
}

bool operator==(BigNumber b1, const long long &b2) {
    return b1.equals(b2);
}

bool operator==(BigNumber b1, const std::string &b2) {
    return b1.equals(b2);
}

bool operator>(BigNumber b1, const BigNumber &b2) {
    if (b1.isNegative() || b2.isNegative()) {
        if (b1.isNegative() && b2.isNegative()) {
            BigNumber bt = b2;
            b1._numberString.erase(0, 1);
            bt._numberString.erase(0, 1);
            return b1 < bt;
        }
        else {
            return !(b1.isNegative() && !b2.isNegative());
        }
    }
    b1 = b1.trimLeadingZeros();
    auto c = BigNumber(b2);
    c = c.trimLeadingZeros();
    if (b1 == c) {
        return false;
    }
    if (b1._numberString.size() > c._numberString.size()) {
        return true;
    }
    else if (c._numberString.size() > b1._numberString.size()) {
        return false;
    }
    else {
        for (unsigned int i = 0; i < b1._numberString.size(); ++i) {
            if (b1[i] == static_cast<unsigned int>(c._numberString[i] - '0')) {
                continue;
            }
            return b1[i] > static_cast<unsigned int>(c._numberString[i] - '0');
        }
    }
    return false;
}

bool operator<(BigNumber b1, const BigNumber &b2) {
    return !(b1 == b2) && !(b1 > b2);
}

bool operator>=(BigNumber b1, const BigNumber &b2) {
    return b1 > b2 || b1 == b2;
}

bool operator<=(BigNumber b1, const BigNumber &b2) {
    return b1 < b2 || b1 == b2;
}

unsigned int BigNumber::operator[](int index) {
    if (this->_numberString[index] == '-') {
        std::cerr << "You cannot get the negative sign from the number" << std::endl;
    }
    return static_cast<unsigned int>(this->_numberString[index] - '0');
}

BigNumber& BigNumber::operator=(const BigNumber &other) {
    this->_numberString = other._numberString;
    return *this;
}

BigNumber& BigNumber::operator=(const long long &other) {
    this->_numberString = std::to_string(other);
    return *this;
}

BigNumber& BigNumber::operator=(const std::string &other) {
    this->_numberString = other;
    return *this;
}

BigNumber& BigNumber::operator+=(const BigNumber &other) {
    *this = *this + other;
    return *this;
}

BigNumber& BigNumber::operator+=(const long long &other) {
    *this = *this + other;
    return *this;
}

BigNumber& BigNumber::operator+=(const std::string &other) {
    *this = *this + other;
    return *this;
}

BigNumber& BigNumber::operator-=(const BigNumber &other) {
    *this = *this - other;
    return *this;
}

BigNumber& BigNumber::operator-=(const long long &other) {
    *this = *this - other;
    return *this;
}

BigNumber& BigNumber::operator-=(const std::string &other) {
    *this = *this - other;
    return *this;
}

BigNumber& BigNumber::operator*=(const BigNumber &other) {
    *this = *this * other;
    return *this;
}

BigNumber& BigNumber::operator*=(const long long &other) {
    *this = *this * other;
    return *this;
}

BigNumber& BigNumber::operator*=(const std::string &other) {
    *this = *this * other;
    return *this;
}

BigNumber& BigNumber::operator/=(const BigNumber &other) {
    *this = *this / other;
    return *this;
}

BigNumber& BigNumber::operator/=(const long long &other) {
    *this = *this / other;
    return *this;
}

BigNumber& BigNumber::operator/=(const std::string &other) {
    *this = *this / other;
    return *this;
}

BigNumber& BigNumber::operator++() {
    *this += BigNumber("1");
    return *this;
}

BigNumber& BigNumber::operator--() {
    *this -= BigNumber("1");
    return *this;
}

BigNumber BigNumber::operator++(int) {
    BigNumber t(this->getString());
    ++(*this);
    return t;
}

BigNumber BigNumber::operator--(int) {
    BigNumber t(this->getString());
    --(*this);
    return t;
}