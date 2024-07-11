CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(fleet-protocol C CXX)

SET(FLEET_PROTOCOL_VERSION 2.1.0)
SET(FLEET_PROTOCOL_NAMESPACE "fleet-protocol-interface::")

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

CMDEF_ADD_LIBRARY(
        LIBRARY_GROUP fleet-protocol
        TYPE INTERFACE
        VERSION ${FLEET_PROTOCOL_VERSION}
)
TARGET_LINK_LIBRARIES(fleet-protocol-interface INTERFACE
                    common-headers-interface
                    internal-client-interface
                    module-gateway-interface
                    module-maintainer-external-server-interface
                    module-maintainer-module-gateway-interface
                    protobuf-cpp-interface
)


IF (BRINGAUTO_INSTALL)
    CMDEF_INSTALL(
            TARGET fleet-protocol-interface
            NAMESPACE ${FLEET_PROTOCOL_NAMESPACE}
    )

ENDIF ()

IF (BRINGAUTO_PACKAGE)
    CMDEF_PACKAGE(
            MAIN_TARGET fleet-protocol-interface
            VERSION ${FLEET_PROTOCOL_VERSION}
    )
    SET(CPACK_GENERATOR ZIP)
    SET(CPACK_PACKAGE_CONTACT "BringAuto s.r.o. <maintainers@bringauto.com>")
    INCLUDE(CPack)
ENDIF()