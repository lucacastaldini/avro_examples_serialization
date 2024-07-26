#include "HKAvroEntities.hh"
#include "HKUtils.hh"
#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For clock_gettime()

using namespace HK;


// HkSerializer class implementation
HKSerializer::HKSerializer(std::queue<std::vector<uint8_t>>& q)
    : serializedQueue(q), e(avro::binaryEncoder()) {
    e->init(*out);
}

void HKSerializer::encode(const HeaderHK* h) {
    out = avro::memoryOutputStream();
    e->init(*out);
    avro::encode(*e, *h);
    std::shared_ptr<std::vector<uint8_t>> p = avro::snapshot(*out);
    std::cout << "vector values are: " << p << std::endl;

    serializedQueue.push(*p);

    std::cout << "Lenght of queue: " << serializedQueue.size() << std::endl;
        
}

// HkDeserializer class implementation
HKDeserializer::HKDeserializer(std::queue<std::vector<uint8_t>>& q)
    : serializedQueue(q), idx_r(0), idx_w(0), d(avro::binaryDecoder()), stop(false) {}

HeaderHK HKDeserializer::decode() {
    try{
        std::cout << "Lenght of queue: " << serializedQueue.size() << std::endl;
               
            if (!serializedQueue.empty()) {
                std::vector<uint8_t> dequeuedData = serializedQueue.front();
                std::cout << "queue first content is: " << dequeuedData.data() << std::endl;
            
                serializedQueue.pop();
                in = avro::memoryInputStream(dequeuedData.data(), dequeuedData.size());
                d->init(*in);
                avro::decode(*d, c2);
                print_HK(c2);
                return c2;
            } else{

            
            
            std::cout << "Lenght of queue: " << serializedQueue.size() << std::endl;
            throw std::runtime_error("No more data to deserialize");
            }
    } catch (const std::exception& e) {
        std::cerr << "Deserialization error: " << e.what() << std::endl;
        throw;
    }
        
}

