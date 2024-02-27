CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(fleet-protocol CXX)

SET(Protobuf_USE_STATIC_LIBS ON)

FILE(GLOB_RECURSE source_files "compiled/cpp/source/*.cc")

CMDEF_ADD_LIBRARY(
        LIBRARY_GROUP protobuf-cpp
        TYPE INTERFACE
        VERSION 1.0.0
        SOURCES ${source_files}
        SOURCE_BASE_DIRECTORY compiled/cpp/source/
        INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/compiled/cpp/include/"
        INSTALL_INCLUDE_DIRECTORIES "compiled/cpp/include/"
)

CMDEF_INSTALL(
        TARGET protobuf-cpp-interface
        NAMESPACE fleet-protocol-interface::
)
