#ifndef __GENERATORS_HH__
#define __GENERATORS_HH__

#include <cstring>
#include <iostream>
#include <random>
#include <chrono>
#include "packet.h"

#define WF_SIZE 16384

const int min_value = 0;
const int max_value = 16384;

static std::pair<Header, Data_Hk> generateHk();
static std::pair<Header, Data_Wf> generateWf();


#endif