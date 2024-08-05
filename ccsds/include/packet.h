//
//  packet.h
//  Packet
//
//  Created by Alessio Aboudan on 20/05/21.
//

#ifndef __PACKET_H__
#define __PACKET_H__

#include <cstdint>
#include <time.h>


#define TC_RX_OK 			0x00
#define TC_RX_ERR_WRONGSTT 	0xFF

#define TC_EX_OK 			0x00
#define TC_EX_ERR_RUPDFAIL 	0xFE
#define TC_EX_ERR_INITFAIL  0xFD


// Define the HeaderHK struct
class HeaderHK {
public:
    // Header data
    union {
        uint8_t _p8[28];   // 7 * 4 bytes for 7 integers
        uint16_t _p16[14]; // 7 * 2 2-byte integers
        uint32_t _p32[7];  // 7 integers
        struct __attribute__((packed)) {
            int apid;
            int counter;
            int type;
            struct timespec ts;
            int abstime;
            int runID;
            int configID;
        };
    };

    void print(const HeaderHK& header) const;
};

// Define the Data_Hk struct
class Data_Hk {
public:

    // Header data
    union {
        uint8_t _p8[12];   // 3 * 4 bytes for 3 integers
        uint16_t _p16[6];  // 3 * 2 2-byte integers
        uint32_t _p32[3];  // 3 integers
        struct __attribute__((packed)) {
            int wformcount;
            int flags;
            int crc;
        };
    };

    void print(const Data_Hk& data) const;
};

// Define the Data_Wf struct
class Data_Wf {
public:

    // Header data
    union {
        uint8_t _p8[12];   // 3 * 4 bytes for 3 integers
        uint16_t _p16[6];  // 3 * 2 2-byte integers
        uint32_t _p32[3];  // 3 integers
        struct __attribute__((packed)) {
            int wformcount;
            int flags;
            int crc;
        };
    };

    void print(const Data_Wf& data) const;
};


#endif // __PACKET_H__
