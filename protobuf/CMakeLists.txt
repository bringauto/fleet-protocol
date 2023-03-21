CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(fleet-protocol C CXX)

FIND_PACKAGE(CMLIB REQUIRED COMPONENTS CMDEF STORAGE)
IF (NOT BRINGAUTO_SYSTEM_DEP)
    INCLUDE(cmake/Dependencies.cmake)
ENDIF ()

SET(Protobuf_USE_STATIC_LIBS ON)
FIND_PACKAGE(Protobuf 3.21.12)

FILE(GLOB_RECURSE protobuf_c_files "compiled/c/*")
ADD_LIBRARY(protobuf_c STATIC ${protobuf_c_files})
TARGET_INCLUDE_DIRECTORIES(protobuf_c PUBLIC "compiled/c/")
TARGET_LINK_LIBRARIES(protobuf_c PUBLIC protobuf::libprotobuf)
ADD_LIBRARY(${PROJECT_NAME}::protobuf_c ALIAS protobuf_c )


FILE(GLOB_RECURSE protobuf_cpp_files "compiled/cpp/*")
ADD_LIBRARY(protobuf_cpp STATIC ${protobuf_cpp_files})
TARGET_INCLUDE_DIRECTORIES(protobuf_cpp PUBLIC "compiled/cpp/")
TARGET_LINK_LIBRARIES(protobuf_cpp PUBLIC protobuf::libprotobuf)
ADD_LIBRARY(${PROJECT_NAME}::protobuf_cpp ALIAS protobuf_cpp )




