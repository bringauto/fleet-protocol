CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(fleet-protocol C CXX)

ADD_LIBRARY(common_headers INTERFACE)
TARGET_INCLUDE_DIRECTORIES(common_headers INTERFACE ) # TODO Build_INTERFACE

# TODO: check with Josef why this is necessary
FILE(GLOB_RECURSE include_files include/*)
TARGET_SOURCES(common_headers INTERFACE
        FILE_SET HEADERS
        #TYPE HEADERS
        FILES ${include_files}
        BASE_DIRS include)
# TODO revisit

ADD_LIBRARY(${PROJECT_NAME}::common_headers ALIAS common_headers)

INSTALL(
    TARGETS common_headers
    EXPORT ${PROJECT_NAME}
    FILE_SET HEADERS
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

INSTALL(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION include/bringauto/fleet-protocol/common-headers
)
