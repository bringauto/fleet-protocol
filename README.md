# Fleet Protocol

Fleet Protocol is a communication protocol developed by BringAuto to allow simple and reliable communication between
multiple devices and cloud infrastructure.
**Complete protocol documentation will be released soon**. Protocol consists of three parts:

* internal client - specific part of device that communicates with module gateway
* module gateway:
    - internal server - communicates with internal client
    - aggregator - aggregates status messages
    - external client - communicates with external server
* external server - communicates with server infrastructure that gives user the ability to control devices

## Communication protocol

We use [ProtoBuf] library for message format (version [Protobuf version]) and serialization/deserialization - protocol
specification
can be found in protobuff folder.

Each message must be prefixed with four bytes long (uint32_t data type) header which holds
information about size of the ProtoBuf message.

To read more about the system architecture look at Fleet Protocol v2 documentation:

- [Summary]
- [Fleet Protocol Requirements]
- [Internal Client]
- [Module Gateway]
- [External Server]
- [Modules]
- [Message Structure]
- [Internal Client design]
- [Module Gateway design]
- [External Server design]
- [HTTP API]
- [HTTP API Wait Mechanism]

### Protocol messages

Messages are described by ProtoBuff v3.

If the message filed is not mandatory then it's marked as OPTIONAL by "OPTIONAL"
as the last comment in documentation for the given field.
Optional fields has defaults as described in [ProtoBuf] v3 doc.

## Repo structure

### Examples

Samples of fleet-protocol features usage.

Use CMake option `BRINGAUTO_SAMPLES=ON` to configure them.

### Lib

Header files of interfaces

### Protobuf

Protobuf compiled and non-compiled files

## Usage

### Requirements

- [CMlib](https://github.com/cmakelib/cmakelib)

### Installation

To install the library, first configure the project with CMake option BRINGAUTO_INSTALL=ON and BRINGAUTO_PACKAGE=ON and then install it.

```bash
mkdir _build && cd _build
cmake -DBRINGAUTO_INSTALL=ON -DBRINGAUTO_PACKAGE=ON ..
make install
```

### Package

To create a package, configure the project with CMake option BRINGAUTO_PACKAGE=ON and then create it using `cpack`.

```bash
mkdir _build && cd _build
cmake -DBRINGAUTO_INSTALL=ON -DBRINGAUTO_PACKAGE=ON ..
cpack
```

### Using library in CMake projects

Once the library is installed, it can be used in other projects by adding the following lines to the `CMakeLists.txt`
file:

```cmake
FIND_PACKAGE(fleet-protocol-interface REQUIRED)
TARGET_LINK_LIBRARIES(<target> PUBLIC fleet-protocol-interface::fleet-protocol-interface)
```

This will link all interfaces. If you want to link only specific interface, use the interfaces from the list below:

* fleet-protocol-interface::common-headers-interface
* fleet-protocol-interface::internal-client-interface
* fleet-protocol-interface::module-gateway-interface
* fleet-protocol-interface::module-maintainer-external-server-interface
* fleet-protocol-interface::module-maintainer-module-gateway-interface
* fleet-protocol-interface::protobuf-cpp-interface

> Note that `protobuf-cpp-interface` also needs `protobuf::libprotobuf` to be linked to the target


[BringAutoDaemon.proto]: ./BringAutoDaemon.proto

[ProtoBuf]: https://developers.google.com/protocol-buffers

[Protobuf version]: https://github.com/protocolbuffers/protobuf/releases/tag/v3.21.12

[Summary]: https://ref.bringautofleet.com/r/protocol/v2/2.0.1/summary

[Fleet Protocol Requirements]: https://ref.bringautofleet.com/r/protocol/v2/2.0.1/protocol-requirements

[Internal Client]: https://ref.bringautofleet.com/r/protocol/v2/2.0.1/internal-client

[Module Gateway]: https://ref.bringautofleet.com/r/protocol/v2/2.0.1/module-gateway

[External Server]: https://ref.bringautofleet.com/r/protocol/v2/2.0.1/external-server

[Modules]: https://ref.bringautofleet.com/r/protocol/v2/2.0.1/modules

[Message Structure]: https://ref.bringautofleet.com/r/protocol/v2/2.0.1/message-structure

[Internal Client design]: https://ref.bringautofleet.com/r/protocol/v2/2.0.1/internal-client-design

[Module Gateway design]: https://ref.bringautofleet.com/r/protocol/v2/2.0.1/module-gateway-design

[External Server design]: https://ref.bringautofleet.com/r/protocol/v2/2.0.1/external-server-design

[HTTP API]: https://ref.bringautofleet.com/r/protocol/http-api/1.0.0/http-api

[HTTP API Wait Mechanism]: https://ref.bringautofleet.com/r/protocol/http-api/1.0.0/wait-mechanism
