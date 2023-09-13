CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(fleet-protocol C CXX)

ADD_LIBRARY(external_server INTERFACE)
TARGET_INCLUDE_DIRECTORIES(external_server INTERFACE include/)
TARGET_LINK_LIBRARIES(external_server INTERFACE ${PROJECT_NAME}::common_headers)

FILE(GLOB_RECURSE include_files include/*)
TARGET_SOURCES(external_server INTERFACE
        FILE_SET external_server TYPE HEADERS FILES ${include_files} BASE_DIRS include)

ADD_LIBRARY(${PROJECT_NAME}::module_maintainer::external_server ALIAS external_server )
