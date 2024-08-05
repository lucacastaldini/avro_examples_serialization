#ifndef __GENERATORS_HH__
#define __GENERATORS_HH__

#include <cstring>
#include <iostream>
#include <random>
#include <chrono>
#include "packet.h"

const int min_value = 0;
const int max_value = 16384;

std::pair<Header, Data_Hk> generateHk();
std::pair<Header, Data_Wf> generateWf();


#endif