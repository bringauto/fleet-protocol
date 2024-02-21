CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(fleet-protocol CXX)

SET(CMAKE_CXX_STANDARD 20)

SET(CMAKE_BUILD_RPATH_USE_ORIGIN ON)

FIND_PACKAGE(Protobuf 3.21.12 REQUIRED) # TODO add dependency

FILE(GLOB_RECURSE source_files "source/*")
FILE(GLOB_RECURSE protobuf_files "lib/protobuf/*")
CMDEF_ADD_EXECUTABLE(TARGET protobuf-parser
                     SOURCES main.cpp ${source_files} ${protobuf_files}
                     INCLUDE_DIRECTORIES "include/" "lib/protobuf/"
                     VERSION 1.0.0)
TARGET_LINK_LIBRARIES(protobuf-parser PUBLIC protobuf::libprotobuf parsing-example-lib-static protobuf-cpp-interface)