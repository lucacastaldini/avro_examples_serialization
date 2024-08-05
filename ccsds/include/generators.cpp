#include <cstring>
#include <iostream>
#include <random>
#include <chrono>

#include "packet.h"
#include "generators.hh"

std::pair<Header, Data_Hk> generateHk() {

    auto now = std::chrono::system_clock::now();
    std::time_t epoch_time = std::chrono::system_clock::to_time_t(now);
    int32_t epoch_time_32 = static_cast<int32_t>(epoch_time);
    static int pc = 0;

    Header header;
    header.apid     = 3000;
    header.counter  = pc++;
    header.type     = 20;
    clock_gettime(CLOCK_REALTIME, &header.ts);
    header.abstime  = epoch_time_32;
    header.runID    = 1;
    header.configID = 130;

    Data_Hk data;
    data.wformcount = rand() % 5000;
    data.flags      = 0xABCD;
    data.crc        = 0xEF01;

    return std::make_pair(header, data);
}


// Private method to generate data
std::pair<Header, Data_Wf> generateWf() {
    auto now = std::chrono::system_clock::now();
    std::time_t epoch_time = std::chrono::system_clock::to_time_t(now);
    int32_t epoch_time_32 = static_cast<int32_t>(epoch_time);
    static int pc = 0;
     
    Header header;
    header.apid = 30303;
    header.counter = pc++;
    header.type = 1;
    clock_gettime(CLOCK_REALTIME, &header.ts);
    header.abstime = epoch_time_32;
    header.runID = 209;
    header.configID = 123;

    Data_Wf wf;

    wf.equalizationLevel = rand() % 10;
    wf.decimation = rand() % 10000;
    wf.curOffset = rand() % 10000;
    wf.trigOff = rand() % 10000;
    wf.size = WF_SIZE;

    // Create a random number generator
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<int32_t> dis(min_value, max_value); // Define the range

    // Create and fill the vector with random values
    for (std::size_t i = 0; i < WF_SIZE; ++i) {
        wf.data[i] = dis(gen);
    }


    wf.crc = rand();

    return std::make_pair(header, wf);
}
