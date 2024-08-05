#ifndef __TCHANDLER_H__
#define __TCHANDLER_H__

#include "packet.h"
#include <utility>
#include <cstdint> // For uint8_t

class TcHandler {
public:
    // Templated bufferize function
    template <typename DataType>
    void bufferize(uint8_t* buff, size_t buffSz, const Header* header, const DataType* data);

    // Templated debufferize function
    template <typename DataType>
    void debufferize(uint8_t* buff, size_t buffSz, Header* header, DataType* data);

private:
    // Add any private members or methods here if needed
};

// Include the implementation of template methods
#include "tchandler_impl.hpp"

#endif // __TCHANDLER_H__
