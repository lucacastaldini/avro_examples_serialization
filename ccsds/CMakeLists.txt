cmake_minimum_required(VERSION 3.10)
project(AvroSerialize CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_SKIP_INSTALL_ALL_DEPENDENCY true)

set(INC_DIR
	"${CMAKE_SOURCE_DIR}/include"
	)

# Add the source files (include all relevant .cpp files here)
set(SOURCE_DIR 
    main.cpp
    include/packet.cpp  # Add all relevant .cpp files
    include/tchandler.cpp
    # Add other .cpp files if necessary
)

# Add the executable
add_executable(CCSDSTest ${SOURCE_DIR})

target_include_directories (CCSDSTest PUBLIC ${INC_DIR})
# Link the Avro library to the executable
