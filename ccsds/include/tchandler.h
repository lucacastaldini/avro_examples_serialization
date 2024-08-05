//
//  tchandler.hpp
//  DAM_xc
//
//  Created by Alessio Aboudan on 26/08/21.
//

#ifndef __TCHANDLER_H__
#define __TCHANDLER_H__

#include "packet.h"
#include <utility>

class TcHandler {
public:
    void bufferizeHk(uint8_t* buff, size_t buffSz, Header* header, Data_Hk* data);
    void debufferizeHk(uint8_t* buff, size_t buffSz, Header* header, Data_Hk* data);
    

private:
    void sendEnd();
    uint32_t pc = 0;
};


#endif // __TCHANDLER_H__
