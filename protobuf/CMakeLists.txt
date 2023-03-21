CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(fleet-protocol C CXX)

FIND_PACKAGE(CMLIB REQUIRED COMPONENTS CMDEF STORAGE)
IF (NOT BRINGAUTO_SYSTEM_DEP)
    INCLUDE(cmake/Dependencies.cmake)
ENDIF ()

SET(Protobuf_USE_STATIC_LIBS ON)
FIND_PACKAGE(Protobuf 4.21.12)

IF ("C" IN_LIST languages) ## TODO add protobuf_c and protobuf_cpp lib, because this is not working
    FILE(GLOB_RECURSE protobuf_files "compiled/c/*")
    ADD_LIBRARY(protobuf STATIC ${protobuf_files})
    TARGET_LINK_LIBRARIES(protobuf PUBLIC protobuf::libprotobuf)
ELSEIF ("CXX" IN_LIST languages)
    FILE(GLOB_RECURSE protobuf_files "compiled/cpp/*")
    ADD_LIBRARY(protobuf STATIC ${protobuf_files})
    TARGET_LINK_LIBRARIES(protobuf PUBLIC protobuf::libprotobuf)
ENDIF()



