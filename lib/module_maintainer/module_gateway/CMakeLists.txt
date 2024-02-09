CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(fleet-protocol C CXX)

ADD_LIBRARY(module_gateway_maintainer INTERFACE)
TARGET_INCLUDE_DIRECTORIES(module_gateway_maintainer INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/>"
                                                               "$<INSTALL_INTERFACE:include/>")
TARGET_LINK_LIBRARIES(module_gateway_maintainer INTERFACE ${PROJECT_NAME}::common_headers)

# TODO: check with Josef why this is necessary
#FILE(GLOB_RECURSE include_files include/*)
#TARGET_SOURCES(module_gateway_maintainer INTERFACE
#        FILE_SET module_gateway_maintainer TYPE HEADERS FILES ${include_files} BASE_DIRS include)

ADD_LIBRARY(${PROJECT_NAME}::module_maintainer::module_gateway ALIAS module_gateway_maintainer)

INSTALL(
    TARGETS module_gateway_maintainer
    EXPORT ${PROJECT_NAME}
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

INSTALL(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION include/bringauto/fleet-protocol/module-maintainer/module-gateway
)