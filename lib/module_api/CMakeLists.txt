CMAKE_MINIMUM_REQUIRED(VERSION 3.21)
PROJECT(module_api C)

SET(CMAKE_C_STANDARD 99)

FILE(GLOB_RECURSE source_files "source/*")
ADD_LIBRARY(module_api_lib STATIC ${source_files})
TARGET_INCLUDE_DIRECTORIES(module_api_lib PUBLIC "${PROTO_DIR}" "include/")

ADD_EXECUTABLE(module_api_example main.c)
TARGET_LINK_LIBRARIES(module_api_example module_api_lib)
