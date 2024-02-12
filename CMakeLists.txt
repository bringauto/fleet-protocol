CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(fleet-protocol C CXX)
INCLUDE(GNUInstallDirs)

SET(FLEET_PROTOCOL_VERSION 1.0.0)
SET(CMAKE_INSTALL_RPATH "$ORIGIN/../${CMAKE_INSTALL_LIBDIR}")

OPTION(BRINGAUTO_PACKAGE "Package creation" OFF)
OPTION(BRINGAUTO_INSTALL "Enable install" OFF)
OPTION(BRINGAUTO_SAMPLES "Enable build of sample app, not used in project" OFF)

IF(BRINGAUTO_PACKAGE)
    IF(NOT BRINGAUTO_INSTALL)
        SET(BRINGAUTO_INSTALL ON CACHE BOOL "Forced install due to BRINGAUTO_PACKAGE=ON" FORCE)
        MESSAGE(WARNING "BRINGAUTO_INSTALL is switched to on because of BRINGAUTO_PACKAGE=ON")
    ENDIF()
ENDIF()

FIND_PACKAGE(CMLIB
        COMPONENTS CMDEF CMUTIL
        REQUIRED
        )

IF(BRINGAUTO_SAMPLES)
    ADD_SUBDIRECTORY("${CMAKE_CURRENT_SOURCE_DIR}/examples")
ENDIF()
ADD_SUBDIRECTORY("${CMAKE_CURRENT_SOURCE_DIR}/lib")
ADD_SUBDIRECTORY("${CMAKE_CURRENT_SOURCE_DIR}/protobuf")

ADD_LIBRARY(fleet_protocol INTERFACE)
TARGET_LINK_LIBRARIES(fleet_protocol INTERFACE
                            fleet-protocol::common_headers
                            fleet-protocol::internal_client_interface
                            fleet-protocol::module_gateway
                            fleet-protocol::module_maintainer::external_server
                            fleet-protocol::module_maintainer::module_gateway
                            fleet-protocol::protobuf_cpp)

IF (BRINGAUTO_INSTALL)
    #INSTALL(TARGETS fleet_protocol
    #        EXPORT ${PROJECT_NAME})
    INSTALL(EXPORT ${PROJECT_NAME}
        FILE ${PROJECT_NAME}Targets.cmake
        DESTINATION "cmake/"
        NAMESPACE ${PROJECT_NAME}::)
ENDIF ()

IF (BRINGAUTO_PACKAGE)
    CMDEF_PACKAGE(
            MAIN_TARGET fleet_protocol
            VERSION ${FLEET_PROTOCOL_VERSION}
    )
    SET(CPACK_GENERATOR ZIP)
    SET(CPACK_PACKAGE_CONTACT "BringAuto s.r.o. <maintainers@bringauto.com>")
    SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "BringAuto s.r.o <maintainers@bringauto.com>")
    SET(CPACK_DEBIAN_PACKAGE_GENERATE_SHLIBS ON)
    SET(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
    INCLUDE(CPack)
ENDIF()