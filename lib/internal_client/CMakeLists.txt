CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(fleet-protocol C CXX)

ADD_LIBRARY(internal_client_interface INTERFACE)
TARGET_INCLUDE_DIRECTORIES(internal_client_interface INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/>"
                                                               "$<INSTALL_INTERFACE:include/>")
TARGET_LINK_LIBRARIES(internal_client_interface INTERFACE fleet-protocol::common_headers)

# TODO: check with Josef why this is necessary
#FILE(GLOB_RECURSE include_files include/*)
#TARGET_SOURCES(internal_client_interface INTERFACE
#        FILE_SET internal_client_interface TYPE HEADERS FILES ${include_files} BASE_DIRS include)

ADD_LIBRARY(${PROJECT_NAME}::internal_client_interface ALIAS internal_client_interface)

INSTALL(
    TARGETS internal_client_interface
    EXPORT ${PROJECT_NAME}
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

INSTALL(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION include/bringauto/fleet-protocol/internal-client
)