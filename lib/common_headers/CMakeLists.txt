CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(fleet-protocol-common-headers C CXX)

ADD_LIBRARY(common_headers INTERFACE)
TARGET_INCLUDE_DIRECTORIES(common_headers INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/>"
                                                    "$<INSTALL_INTERFACE:include/>")

FILE(GLOB_RECURSE include_files include/*)
TARGET_SOURCES(common_headers INTERFACE
        FILE_SET common_headers TYPE HEADERS FILES ${include_files} BASE_DIRS include)

ADD_LIBRARY(fleet-protocol::common_headers ALIAS common_headers)
