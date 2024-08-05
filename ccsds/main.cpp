#include "tchandler.h"
#include <iostream>

int main() {
    TcHandler handler;

    constexpr size_t buffSz = sizeof(HeaderHK) + sizeof(Data_Hk);
    uint8_t buffer[buffSz];  // Use stack allocation for buffer

    // Generate HeaderHK and Data_Hk
    std::pair<HeaderHK, Data_Hk> hkPair = handler.generateHk();

    // Bufferize the generated structures
    handler.bufferizeHk(buffer, buffSz, &hkPair.first, &hkPair.second);

    // Variables to hold debufferized data
    HeaderHK debufferizedHeader;
    Data_Hk debufferizedData;

    // Debufferize the content back into structures
    handler.debufferizeHk(buffer, buffSz, &debufferizedHeader, &debufferizedData);

    // Verify the content of the debufferized data
    std::cout << "Debufferized Header APID: " << debufferizedHeader.apid << std::endl;
    std::cout << "Debufferized Data Wformcount: " << debufferizedData.wformcount << std::endl;

    HeaderHK::print(debufferizedHeader);

    return 0;
}
