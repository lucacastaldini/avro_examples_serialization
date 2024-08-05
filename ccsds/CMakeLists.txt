cmake_minimum_required(VERSION 3.10)
project(AvroSerialize CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_SKIP_INSTALL_ALL_DEPENDENCY true)

set(INC_DIR
	"${CMAKE_SOURCE_DIR}/include"
	)


set(COMMON_SOURCES 
    include/packet.cpp  # Add all relevant .cpp files
    include/generators.cpp
    # Add other .cpp files if necessary
)
# Add the source files (include all relevant .cpp files here)
set(HKTEST_SOURCES 
    src/HKtest.cpp
    ${COMMON_SOURCES}
)
# Add the source files for WFtest
set(WFTEST_SOURCES 
    src/WFtest.cpp
    ${COMMON_SOURCES}
)

# Add the executable
add_executable(HKtest ${HKTEST_SOURCES})
add_executable(WFtest ${WFTEST_SOURCES})

target_include_directories (HKtest PUBLIC ${INC_DIR})
target_include_directories (WFtest PUBLIC ${INC_DIR})
# Link the Avro library to the executable
