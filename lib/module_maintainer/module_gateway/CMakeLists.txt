CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(fleet-protocol C CXX)

CMDEF_ADD_LIBRARY(
        LIBRARY_GROUP module-maintainer-module-gateway
        TYPE INTERFACE
        VERSION ${FLEET_PROTOCOL_VERSION}
        INCLUDE_DIRECTORIES include/
        INSTALL_INCLUDE_DIRECTORIES include/
)
TARGET_LINK_LIBRARIES(module-maintainer-module-gateway-interface INTERFACE common-headers-interface)
CMDEF_INSTALL(
        TARGET module-maintainer-module-gateway-interface
        NAMESPACE ${FLEET_PROTOCOL_NAMESPACE}
)
