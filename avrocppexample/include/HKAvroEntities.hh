#ifndef HK_AVRO_ENTITIES_HH
#define HK_AVRO_ENTITIES_HH

#include <fstream>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <memory>
#include "HKSchema.hh"
#include "WFSchema.hh"
#include "avro/Compiler.hh"
#include "avro/Encoder.hh"
#include "avro/Decoder.hh"
#include "avro/Specific.hh"
#include "avro/Generic.hh"

namespace HK {
    class HKSerializer {
    private:
        std::queue<std::vector<uint8_t>>& serializedQueue;
        std::shared_ptr<avro::OutputStream> out;
        avro::EncoderPtr e;

    public:
        // Constructor
        HKSerializer(std::queue<std::vector<uint8_t>>& q);

        // Method to encode HeaderHK
        void encode(const HeaderHK* h);
    };

    class HKDeserializer {
    private:
        std::queue<std::vector<uint8_t>>& serializedQueue;
        int idx_r;
        int idx_w;
        std::unique_ptr<avro::InputStream> in;
        avro::DecoderPtr d;
        HeaderHK c2;
        bool stop;

    public:
        // Constructor
        HKDeserializer(std::queue<std::vector<uint8_t>>& q);

        // Method to decode HeaderHK
        HeaderHK decode();
    };

    // Function to generate HeaderHK data
    HeaderHK generate_data();
}

#endif // HK_AVRO_ENTITIES_HH
