CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(fleet-protocol C CXX)

CMDEF_ADD_LIBRARY(
        LIBRARY_GROUP common-headers
        TYPE INTERFACE
        VERSION 1.0.0
        INCLUDE_DIRECTORIES include/
        INSTALL_INCLUDE_DIRECTORIES include/
)

CMDEF_INSTALL(
        TARGET common-headers-interface
        NAMESPACE fleet-protocol-interface::
)
