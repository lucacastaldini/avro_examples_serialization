#include <iostream>

#include "HKSchema.hh"
#include "HKAvroEntities.hh"
#include "HKGenerator.hh"
#include "HKUtils.hh"

using namespace HK;

std::queue<std::vector<uint8_t>> serializedQueue;

int main() {

    HKGenerator generator = HKGenerator(1);
    
    HKSerializer ser = HKSerializer(serializedQueue);
    HKDeserializer dser = HKDeserializer(serializedQueue);

    HeaderHK genval = generator.get();
    // print_HK(genval);
    ser.encode(&genval);
    std::cout << "MAIN:Lenght of queue: " << serializedQueue.size() << std::endl;

    HeaderHK retval= dser.decode();

    if ( areEqual(retval, genval) ){
        std::cout << "Serialization successful" << std::endl;
    }
    else{
        std::cout << "Serialization failed" << std::endl;
    }

}