# Compile protobuf
From project root folder call
```
mkdir -p examples/protobuf_parsing_example/proto_compiled && protoc --cpp_out=examples/protobuf_parsing_example/proto_compiled/ --proto_path=protobuf protobuf/ExternalProtocol.proto protobuf/InternalProtocol.proto protobuf/modules/CarAccessoryModule.proto protobuf/modules/MissionModule.proto
```