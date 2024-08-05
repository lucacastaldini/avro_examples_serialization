//
//  packet.cpp
//  Packet
//
//  Created by Alessio Aboudan on 20/05/21.
//

#include "packet.h"

#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>

void HeaderHK::print(const HeaderHK& header) const {
    std::cout << "HeaderHK:" << std::endl;
    std::cout << "  APID: " << header.apid << std::endl;
    std::cout << "  Counter: " << header.counter << std::endl;
    std::cout << "  Type: " << header.type << std::endl;
    std::cout << "  Timestamp: " << header.ts.tv_sec << "s " << header.ts.tv_nsec << "ns" << std::endl;
    std::cout << "  Absolute Time: " << header.abstime << std::endl;
    std::cout << "  Run ID: " << header.runID << std::endl;
    std::cout << "  Config ID: " << header.configID << std::endl;
}

void Data_Hk::print(const Data_Hk& data) const {
    std::cout << "Data_Hk:" << std::endl;
    std::cout << "  Waveform Count: " << data.wformcount << std::endl;
    std::cout << "  Flags: 0x" << std::hex << data.flags << std::dec << std::endl;
    std::cout << "  CRC: 0x" << std::hex << data.crc << std::dec << std::endl;
}