#ifndef HK_UTILS_HH
#define HK_UTILS_HH

#include "HKSchema.hh"
using namespace HK;

void print_HK(HeaderHK h);

bool areEqual(const TimeSpec& lhs, const TimeSpec& rhs);

bool areEqual(const HeaderHK& lhs, const HeaderHK& rhs);

#endif // HK_UTILS_HH