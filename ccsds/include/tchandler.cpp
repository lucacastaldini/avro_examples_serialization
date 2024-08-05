#include "tchandler.h"
#include <cstring>
#include <iostream>
#include <random>

std::pair<HeaderHK, Data_Hk> TcHandler::generateHk() {

    auto now = std::chrono::system_clock::now();
    std::time_t epoch_time = std::chrono::system_clock::to_time_t(now);
    int32_t epoch_time_32 = static_cast<int32_t>(epoch_time);


    HeaderHK header;
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

void TcHandler::bufferizeHk(uint8_t* buff, size_t buffSz, HeaderHK* header, Data_Hk* data) {
    if (buffSz < sizeof(HeaderHK) + sizeof(Data_Hk)) {
        // Handle error: buffer size is too small
        std::cerr << "Buffer size is too small!" << std::endl;
        return;
    }

    // Copy HeaderHK to buffer
    memcpy(buff, header, sizeof(HeaderHK));

    // Copy Data_Hk to buffer
    memcpy(buff + sizeof(HeaderHK), data, sizeof(Data_Hk));
}

void TcHandler::debufferizeHk(uint8_t* buff, size_t buffSz, HeaderHK* header, Data_Hk* data) {
    if (buffSz < sizeof(HeaderHK) + sizeof(Data_Hk)) {
        // Handle error: buffer size is too small
        std::cerr << "Buffer size is too small!" << std::endl;
        return;
    }

    // Copy from buffer to HeaderHK
    memcpy(header, buff, sizeof(HeaderHK));

    // Copy from buffer to Data_Hk
    memcpy(data, buff + sizeof(HeaderHK), sizeof(Data_Hk));
}

void TcHandler::sendEnd() {
    // Implementation of sendEnd (for example purposes, it does nothing)
    std::cout << "Bufferization complete." << std::endl;
}
