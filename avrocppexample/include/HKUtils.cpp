#include "HKSchema.hh"
using namespace HK;

void print_HK(HeaderHK h) {
    std::cout << "abstime: " << h.abstime << std::endl;
    std::cout << "apid: " << h.apid << std::endl;
    std::cout << "configID: " << h.configID << std::endl;
    std::cout << "counter: " << h.counter << std::endl;
    std::cout << "crc: " << h.crc << std::endl;
    std::cout << "flags: " << h.flags << std::endl;
    std::cout << "runID: " << h.runID << std::endl;
    std::cout << "time s: " << h.time.tv_sec << std::endl;
    std::cout << "time ns: " << h.time.tv_nsec << std::endl;
    std::cout << "type: " << h.type << std::endl;
    std::cout << "wformcount: " << h.wformcount << std::endl;
}

// Function to compare TimeSpec instances
bool areEqual(const TimeSpec& lhs, const TimeSpec& rhs) {
    return (lhs.tv_sec == rhs.tv_sec) && (lhs.tv_nsec == rhs.tv_nsec);
}

// Function to compare HeaderHK instances
bool areEqual(const HeaderHK& lhs, const HeaderHK& rhs) {
    return (lhs.apid == rhs.apid) &&
           (lhs.counter == rhs.counter) &&
           (lhs.type == rhs.type) &&
           areEqual(lhs.time, rhs.time) &&
           (lhs.abstime == rhs.abstime) &&
           (lhs.runID == rhs.runID) &&
           (lhs.configID == rhs.configID) &&
           (lhs.wformcount == rhs.wformcount) &&
           (lhs.flags == rhs.flags) &&
           (lhs.crc == rhs.crc);
}