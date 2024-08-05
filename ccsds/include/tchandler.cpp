#include "tchandler.h"
#include <cstring>
#include <iostream>
#include <random>
#include <chrono>


void TcHandler::bufferizeHk(uint8_t* buff, size_t buffSz, Header* header, Data_Hk* data) {
    if (buffSz < sizeof(Header) + sizeof(Data_Hk)) {
        // Handle error: buffer size is too small
        std::cerr << "Buffer size is too small!" << std::endl;
        return;
    }

    // Copy HeaderHK to buffer
    memcpy(buff, header, sizeof(Header));

    // Copy Data_Hk to buffer
    memcpy(buff + sizeof(Header), data, sizeof(Data_Hk));
}

void TcHandler::debufferizeHk(uint8_t* buff, size_t buffSz, Header* header, Data_Hk* data) {
    if (buffSz < sizeof(Header) + sizeof(Data_Hk)) {
        // Handle error: buffer size is too small
        std::cerr << "Buffer size is too small!" << std::endl;
        return;
    }

    // Copy from buffer to HeaderHK
    memcpy(header, buff, sizeof(Header));

    // Copy from buffer to Data_Hk
    memcpy(data, buff + sizeof(Header), sizeof(Data_Hk));
}

void TcHandler::sendEnd() {
    // Implementation of sendEnd (for example purposes, it does nothing)
    std::cout << "Bufferization complete." << std::endl;
}
