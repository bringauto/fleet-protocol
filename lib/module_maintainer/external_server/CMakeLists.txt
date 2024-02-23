CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(fleet-protocol C CXX)

CMDEF_ADD_LIBRARY(
        LIBRARY_GROUP module-maintainer-external-server
        TYPE INTERFACE
        VERSION 1.0.0
        INCLUDE_DIRECTORIES include/
        INSTALL_INCLUDE_DIRECTORIES include/
)
TARGET_LINK_LIBRARIES(module-maintainer-external-server-interface INTERFACE common-headers-interface)
CMDEF_INSTALL(TARGET module-maintainer-external-server-interface
              NAMESPACE fleet-protocol-interface::
)
