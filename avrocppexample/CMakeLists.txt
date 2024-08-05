cmake_minimum_required(VERSION 3.10)
project(AvroSerialize CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_SKIP_INSTALL_ALL_DEPENDENCY true)

# Specify the paths to the Avro include directory and library
set(AVRO_CPP_PATH "/usr/local/include/avro")
set(INC_DIR
    "${CMAKE_SOURCE_DIR}/include"
    "${AVRO_CPP_PATH}"
)

find_library(AVRO_CPP_LIBRARY avrocpp_s REQUIRED PATHS ${AVRO_CPP_PATH}/../lib)

list(APPEND LIBS 
    avrocpp_s
)

link_directories(${AVRO_LIBRARY_DIR})

# Add the common source files (include all relevant .cpp files here)
set(COMMON_SOURCES 
    include/HKGenerator.cpp
    include/WFGenerator.cpp
    include/Utils.cpp
    # Add other .cpp files if necessary
)

# Add the source files for HKtest
set(HKTEST_SOURCES 
    src/HKtest.cpp
    ${COMMON_SOURCES}
)

# Add the source files for WFtest
set(WFTEST_SOURCES 
    src/WFtest.cpp
    ${COMMON_SOURCES}
)

# Add the executable for HKtest
add_executable(HkSerializerTest ${HKTEST_SOURCES})
target_include_directories(HkSerializerTest PUBLIC ${INC_DIR})
target_link_libraries(HkSerializerTest LINK_PUBLIC ${LIBS})

# Add the executable for WFtest
add_executable(WfSerializerTest ${WFTEST_SOURCES})
target_include_directories(WfSerializerTest PUBLIC ${INC_DIR})
target_link_libraries(WfSerializerTest LINK_PUBLIC ${LIBS})
