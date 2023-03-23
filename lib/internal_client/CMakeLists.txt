CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(fleet-protocol C CXX)

ADD_LIBRARY(internal_client INTERFACE include/internal_client.h)
TARGET_INCLUDE_DIRECTORIES(internal_client INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/")
TARGET_LINK_LIBRARIES(internal_client INTERFACE ${PROJECT_NAME}::common_headers)

ADD_LIBRARY(${PROJECT_NAME}::internal_client ALIAS internal_client)
