CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(fleet-protocol C CXX)

ADD_LIBRARY(common_headers INTERFACE)
TARGET_INCLUDE_DIRECTORIES(common_headers INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/>"
                                                    "$<INSTALL_INTERFACE:include/>")

# TODO: check with Josef why this is necessary
#FILE(GLOB_RECURSE include_files include/*)
#TARGET_SOURCES(common_headers INTERFACE
#        FILE_SET common_headers TYPE HEADERS FILES ${include_files} BASE_DIRS include)

ADD_LIBRARY(${PROJECT_NAME}::common_headers ALIAS common_headers)

INSTALL(
    TARGETS common_headers
    EXPORT ${PROJECT_NAME}
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

INSTALL(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION include/bringauto/fleet-protocol/common-headers
)