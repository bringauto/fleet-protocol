CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(fleet-protocol-internal-client C CXX)

ADD_LIBRARY(internal_client_interface INTERFACE)
TARGET_INCLUDE_DIRECTORIES(internal_client_interface INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/>"
        "$<INSTALL_INTERFACE:include/>")
TARGET_LINK_LIBRARIES(internal_client_interface INTERFACE fleet-protocol::common_headers)

TARGET_SOURCES(internal_client_interface INTERFACE
        FILE_SET internal_client_interface TYPE HEADERS FILES include/internal_client.h BASE_DIRS include)

ADD_LIBRARY(fleet-protocol::internal_client_interface ALIAS internal_client_interface)

