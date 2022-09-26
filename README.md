# Fleet protocol

Fleet protocol is a communication protocol developed by BringAuto to allow simple and reliable communication between multiple devices and cloud infrastructure. 
For complete protocol documentation see [TODO](). Protocol consists of three parts:
* module - specific part of device that wants to communicate with server infrastructure
* daemon gateway - modules are locally connected to a single gateway that provides connection to fleet
* fleet - server infrastructure that gives user the ability to control modules on devices


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

## protobuf

TODO

### Compilation
TODO

**C++**
```
protoc -I=./ --cpp_out=./ *.proto
```

**C#**
TODO

**Python**
TODO

**GO**
```
protoc -I=./ --go_out=./ *.proto
```

[BringAutoDaemon.proto]: ./BringAutoDaemon.proto
[ProtoBuf]: https://developers.google.com/protocol-buffers
[BringAuto Autonomy Host Protocol]: https://drive.google.com/drive/folders/1-cfU5wgbO1O8DOk4bDOufZ_aqJ0U61nP
