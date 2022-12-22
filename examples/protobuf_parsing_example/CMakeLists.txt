CMAKE_MINIMUM_REQUIRED(VERSION 3.20)
PROJECT(ProtobufParser)

SET(CMAKE_CXX_STANDARD 17)

#------------protobuf----------------#
FIND_PACKAGE(Protobuf 3.17.3 REQUIRED)
SET(PROTO_DIR "${CMAKE_CURRENT_SOURCE_DIR}/proto_compiled/")

ADD_LIBRARY(protobuf_lib STATIC ${PROTO_DIR}/ExternalProtocol.pb.cc ${PROTO_DIR}/InternalProtocol.pb.cc ${PROTO_DIR}/modules/ExampleModule.pb.cc)
TARGET_LINK_LIBRARIES(protobuf_lib PUBLIC protobuf::libprotobuf)
TARGET_INCLUDE_DIRECTORIES(protobuf_lib PUBLIC "${PROTO_DIR}")

FILE(GLOB_RECURSE source_files "source/*")
ADD_LIBRARY(parsing_example_lib STATIC ${source_files})
TARGET_INCLUDE_DIRECTORIES(parsing_example_lib PUBLIC "include/")
TARGET_LINK_LIBRARIES(parsing_example_lib PUBLIC protobuf_lib)


ADD_EXECUTABLE(protobuf_parser main.cpp)
TARGET_LINK_LIBRARIES(protobuf_parser parsing_example_lib)