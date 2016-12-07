// -*- encoding: utf8 -*-
// What are Location Numerals?
// See https://en.wikipedia.org/wiki/Location_arithmetic

#include <algorithm>
#include <iostream>
#include <regex>
#include "LocationNumerals.h"


using namespace std;


// Convert a location numeral in a string to its integer value.
// This function accepts numeral strings in either upper or lower
// case form.
// Example: `ac` -> 9
//
// An empty input string returns 0.  Strings with non-alphabetic
// characters throw an `out_of_range` exception.
uint32_t LocationNumerals::ToInteger(const string locStr) throw (out_of_range)
{
    uint32_t sum = 0;
    size_t length = locStr.length();
    string str = locStr;

    if (length == 0) {
        return 0; 
    } else if (!regex_match(str, regex("^[A-Za-z]+$"))) {
        // If there are any non-alphabetic characters, throw an exception
        throw out_of_range("The location numeral string cannot contain non-alphabetic characters.");
    }

    // Make sure all characters are lower case
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    for (size_t idx = 0; idx < length; idx++) {
        // The character distance from 'a' is the exponent to which we raise
        // 2 and add to sum.
        sum += 0x0001 << ((int)str[idx] - 'a');
    }

    return sum;
}


// Convert an integer value into a location numeral string.
// Example: 9 -> `ac`
//
// The integer value 0 returns an empty string. Integers greater
// than 67108863 (2^25 - 1) throw an `out_of_range` exception.
string LocationNumerals::ToLocationNumeral(const uint32_t num) throw (out_of_range)
{ 
    uint8_t exp = 0;
    uint8_t idx = 0;
    char locStr[LocationNumerals::char_range + 1];  // Make room for a \0

    if (num == 0) {
        return "";  // Return an empty string for input value 0
    } else if (num > LocationNumerals::max_value) {
        // If the input value is larger than 2^char_range, throw an exception
        throw out_of_range("The input value is too large.");
    }

    while (exp < LocationNumerals::char_range) {
        // Check if the power of 2 corresponds to a set bit in the
        // integer. If so, then the location character is simply the
        // character distance 'exp' from 'a'.
        //
        // This code assumes our architecture is little endian.
        if (num & (0x0001 << exp)) {
            locStr[idx] = (char) ('a' + exp);
            idx++;
        }
        exp++;
    }
    locStr[idx] = '\0';

    return string(locStr);
}


// Abbreviate a extended form location numeral string.
// Example: `abbc` -> `ad`
string LocationNumerals::Abbreviate(const string locStr) throw (out_of_range)
{
    return LocationNumerals::ToLocationNumeral(LocationNumerals::ToInteger(locStr));
}

