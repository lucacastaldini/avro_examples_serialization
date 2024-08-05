# Minimum CMake required
cmake_minimum_required(VERSION 2.8.12)

# Project
project(protobuf-rp)

# Find required protobuf package
find_package(protobuf CONFIG REQUIRED)

if(protobuf_VERBOSE)
  message(STATUS "Using Protocol Buffers ${protobuf_VERSION}")
endif()

set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

# http://www.cmake.org/Wiki/CMake_FAQ#How_can_I_build_my_MSVC_application_with_a_static_runtime.3F
if(MSVC AND protobuf_MSVC_STATIC_RUNTIME)
  foreach(flag_var
      CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
      CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
    if(${flag_var} MATCHES "/MD")
      string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
    endif(${flag_var} MATCHES "/MD")
  endforeach()
endif()


# set(WF_PROTOS HK.proto)
set(HK_PROTOS HK.proto)

#code generations
if(protobuf_MODULE_COMPATIBLE) #Legacy Support
    protobuf_generate_cpp(WF_PROTO_SRCS WF_PROTO_HDRS ${WF_PROTOS})
    protobuf_generate_cpp(HK_PROTO_SRCS HK_PROTO_HDRS ${HK_PROTOS})
endif()

foreach(example readerwriter)

    set(${example}_SRCS ${example}.cpp)

    list(APPEND ${example}_SRCS ${HK_PROTO_SRCS} ${WF_PROTO_HDRS} ${HK_PROTO_HDRS})

  #Executable setup
  set(executable_name ${example}_cpp)
  add_executable(${executable_name} ${${example}_SRCS} ${WF_PROTOS} ${HK_PROTOS})
  if(protobuf_MODULE_COMPATIBLE) #Legacy mode
    target_include_directories(${executable_name} PUBLIC ${PROTOBUF_INCLUDE_DIRS})
    target_link_libraries(${executable_name} ${PROTOBUF_LIBRARIES})
  else()
    target_link_libraries(${executable_name} protobuf::libprotobuf)
    protobuf_generate(TARGET ${executable_name})
  endif()

endforeach()
