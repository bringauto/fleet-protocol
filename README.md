# Fleet protocol

Fleet protocol is a communication protocol developed by BringAuto to allow simple and reliable communication between multiple devices and cloud infrastructure. 
For complete protocol documentation see [TODO](). Protocol consists of three parts:
* internal client - specific part of device that communicates with module gateway
* module gateway:
  - internal server - communicates with internal client
  - aggregator - aggregates status messages
  - external client - communicates with external server
* external server - communicates with server infrastructure that gives user the ability to control devices


# Communication protocol

We use [ProtoBuf] v3 library for message format and serialization/deserialization - protocol specification
can be found in protobuff folder.

Each message must be prefixed with four bytes long (uint32_t data type) header which holds
information about size  of the ProtoBuf message.

## Protocol messages

Messages are described by ProtoBuff v3.

If the message filed is not mandatory then it's marked as OPTIONAL by "OPTIONAL"
as the last comment in documentation for the given field.
Optional fields has defaults as described in [ProtoBuf] v3 doc.

# Repo structure
## Examples
Samples of fleet-protocol features usage.

Use CMake option `BRINGAUTO_SAMPLES=ON` to configure them.

## Lib
Header files of interfaces

## Protobuf
Protobuf compiled and non-compiled files


[BringAutoDaemon.proto]: ./BringAutoDaemon.proto
[ProtoBuf]: https://developers.google.com/protocol-buffers
[BringAuto Autonomy Host Protocol]: https://drive.google.com/drive/folders/1-cfU5wgbO1O8DOk4bDOufZ_aqJ0U61nP
