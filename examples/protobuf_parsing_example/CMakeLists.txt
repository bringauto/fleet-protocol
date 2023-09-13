CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(fleet-protocol CXX)

SET(CMAKE_CXX_STANDARD 20)

SET(CMAKE_BUILD_RPATH_USE_ORIGIN ON)

FILE(GLOB_RECURSE source_files "source/*")
ADD_LIBRARY(parsing_example_lib STATIC ${source_files})
TARGET_INCLUDE_DIRECTORIES(parsing_example_lib PUBLIC "include/")
TARGET_LINK_LIBRARIES(parsing_example_lib PUBLIC ${PROJECT_NAME}::protobuf_cpp)


ADD_EXECUTABLE(protobuf_parser main.cpp)
TARGET_LINK_LIBRARIES(protobuf_parser parsing_example_lib)