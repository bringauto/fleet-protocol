# Compile protobuf
From project root folder call
```
mkdir -p protobuff_parsing_example/proto_compiled && protoc --cpp_out=protobuff_parsing_example/proto_compiled/ --proto_path=protobuff protobuff/FleetProtocol.proto protobuff/ModuleProtocol.proto protobuff/modules/ActionModule.proto protobuff/modules/AutonomyModule.proto
```