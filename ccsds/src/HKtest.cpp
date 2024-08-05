#include "tchandler.h"
#include "generators.hh"
#include <iostream>

int main() {
    TcHandler handler;

    constexpr size_t buffSz = sizeof(Header) + sizeof(Data_Hk);
    uint8_t buffer[buffSz];  // Use stack allocation for buffer

    // Generate HeaderHK and Data_Hk
    std::pair<Header, Data_Hk> hkPair = generateHk();

    // Bufferize the generated structures
    handler.bufferize(buffer, buffSz, &hkPair.first, &hkPair.second);

    // Variables to hold debufferized data
    Header debufferizedHeader;
    Data_Hk debufferizedData;

    // Debufferize the content back into structures
    handler.debufferize(buffer, buffSz, &debufferizedHeader, &debufferizedData);

    // Verify the content of the debufferized data
    std::cout << "Debufferized Header APID: " << debufferizedHeader.apid << std::endl;
    std::cout << "Debufferized Data Wformcount: " << debufferizedData.wformcount << std::endl;

    Header::print(debufferizedHeader);

    return 0;
}
