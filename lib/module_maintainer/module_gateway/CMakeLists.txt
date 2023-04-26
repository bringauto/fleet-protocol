CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(fleet-protocol C CXX)

ADD_LIBRARY(module_gateway_maintainer INTERFACE)
ADD_LIBRARY(${PROJECT_NAME}::module_maintainer::module_gateway ALIAS module_gateway_maintainer )
TARGET_INCLUDE_DIRECTORIES(module_gateway_maintainer INTERFACE include/)
TARGET_LINK_LIBRARIES(module_gateway_maintainer INTERFACE ${PROJECT_NAME}::common_headers)

FILE(GLOB_RECURSE include_files include/*)
TARGET_SOURCES(module_gateway_maintainer INTERFACE
        FILE_SET module_gateway_maintainer TYPE HEADERS FILES ${include_files} BASE_DIRS include)
