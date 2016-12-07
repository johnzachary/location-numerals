// -*- encoding: utf8 -*-

#include <cstdint>
#include <iostream>
#include <stdexcept>

#include <assert.h>
#include <stdio.h>

#include "LocationNumerals.h"

using namespace std;

int main(int argc, char **argv)
{
    string test1 = "";  // 0
    string test2 = "ad";  // 9
    string test3 = "abdf";  // 43
    string test4 = "acef";  // 53
    string test5 = "g";  // 64
    string test6 = "abcdefghijklmnopqrstuvwxyz";  // 67108863
    string bad_str = "ab2@ ";

    cout << "----- TESTING LOCATION NUMERALS CLASS -----" << endl;

    cout << "Testing ::ToLocationNumeral() method ... ";
    assert(LocationNumerals::ToLocationNumeral(0) == test1);
    assert(LocationNumerals::ToLocationNumeral(9) == test2);
    assert(LocationNumerals::ToLocationNumeral(43) == test3);
    assert(LocationNumerals::ToLocationNumeral(53) == test4);
    assert(LocationNumerals::ToLocationNumeral(64) == test5); 
    assert(LocationNumerals::ToLocationNumeral(67108863) == test6);
    try {
        // This should throw an out of range exception
        cout << LocationNumerals::ToLocationNumeral(67108864) << endl;
        return -1;
    }
    catch (const out_of_range& e) {}
    cout << "Passed!" << endl;

    cout << "Testing ::ToInteger() method ... "; 
    assert(LocationNumerals::ToInteger("") == 0);
    assert(LocationNumerals::ToInteger("ad") == 9);
    assert(LocationNumerals::ToInteger("AD") == 9);
    assert(LocationNumerals::ToInteger("abdf") == 43);
    assert(LocationNumerals::ToInteger("acef") == 53); 
    assert(LocationNumerals::ToInteger("g") == 64);
    assert(LocationNumerals::ToInteger("abcdefghijklmnopqrstuvwxyz") == 67108863);
    try {
        // This should throw an out of range exception
        cout << "ab2@ -> " << LocationNumerals::ToInteger("ab2@") << endl;
        return -1;
    }
    catch (const out_of_range& e) {}
    cout << "Passed!" << endl;

    cout << "Testing ::Abbreviate() method ... ";
    assert(LocationNumerals::Abbreviate("abbc") == test2); 
    assert(LocationNumerals::Abbreviate("ABBC") == test2);
    assert(LocationNumerals::Abbreviate("aaaccee") == test3);
    assert(LocationNumerals::Abbreviate("aaaaaaaaaa") == "bd");
    assert(LocationNumerals::Abbreviate("ccaaaee") == test3);
    try {
        // This should throw an out of range exception
        cout << "abbc2@ -> " << LocationNumerals::Abbreviate("abbc2@") << endl;
        return -1;
    }
    catch (const out_of_range& e) {}
    cout << "Passed!" << endl;

    return 0;
}
