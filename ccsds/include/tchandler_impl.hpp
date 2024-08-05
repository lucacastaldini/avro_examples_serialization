#include "tchandler.h"
#include <cstring>
#include <iostream>

// Template for bufferize function
template <typename DataType>
void TcHandler::bufferize(uint8_t* buff, size_t buffSz, const Header* header, const DataType* data) {
    if (buffSz < sizeof(Header) + sizeof(DataType)) {
        // Handle error: buffer size is too small
        std::cerr << "Buffer size is too small!" << std::endl;
        return;
    }

    // Copy Header to buffer
    memcpy(buff, header, sizeof(Header));

    // Copy Data to buffer
    memcpy(buff + sizeof(Header), data, sizeof(DataType));
}

// Template for debufferize function
template <typename DataType>
void TcHandler::debufferize(uint8_t* buff, size_t buffSz, Header* header, DataType* data) {
    if (buffSz < sizeof(Header) + sizeof(DataType)) {
        // Handle error: buffer size is too small
        std::cerr << "Buffer size is too small!" << std::endl;
        return;
    }

    // Copy from buffer to Header
    memcpy(header, buff, sizeof(Header));

    // Copy from buffer to Data
    memcpy(data, buff + sizeof(Header), sizeof(DataType));
}
