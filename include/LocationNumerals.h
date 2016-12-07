// -*- encoding: utf8 -*-

#ifndef COREAPPS_LOCATIONNUMERALS_H_
#define COREAPPS_LOCATIONNUMERALS_H_

#include <stdexcept>
#include <string>

#include <stdint.h>


using namespace std;


// Convert between integers and location numerals, including
// abbreviating extended forms. This class cannot be instantiated.
class LocationNumerals
{
public:
    static uint32_t ToInteger(const string) throw(out_of_range);
    static string ToLocationNumeral(const uint32_t) throw(out_of_range);
    static string Abbreviate(const string) throw(out_of_range);

private:
    LocationNumerals();
    static uint8_t const char_range = 26;
    static uint64_t const max_value = (1 << LocationNumerals::char_range) - 1;
};

#endif  // COREAPPS_LOCATIONNUMERALS_H_
