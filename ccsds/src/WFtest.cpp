#include "tchandler.h"
#include "generators.hh"
#include <iostream>

int main() {
    TcHandler handler;

    constexpr size_t buffSz = sizeof(Header) + sizeof(Data_Wf);
    uint8_t buffer[buffSz];  // Use stack allocation for buffer

    // Generate HeaderHK and Data_Hk
    std::pair<Header, Data_Wf> wfPair = generateWf();

    // Bufferize the generated structures
    handler.bufferize(buffer, buffSz, &wfPair.first, &wfPair.second);

    // Variables to hold debufferized data
    Header debufferizedHeader;
    Data_Wf debufferizedData;

    // Debufferize the content back into structures
    handler.debufferize(buffer, buffSz, &debufferizedHeader, &debufferizedData);

    // Verify the content of the debufferized data
    std::cout << "Debufferized Header APID: " << debufferizedHeader.apid << std::endl;
    std::cout << "Debufferized Data size: " << debufferizedData.size << std::endl;

    Header::print(debufferizedHeader);

    return 0;
}
