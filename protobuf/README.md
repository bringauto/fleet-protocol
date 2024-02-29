# Protobuf

Using Protobuf version 21.12

## Usage

CMakeLists in this directory adds library `protobuf-cpp-interface`.
To use this library, it is necessary to link `libprotobuf` library.

Usage example is in [examples/protobuf_parsing_example](examples/protobuf_parsing_example).

To link the library, use the following CMake commands in your CMakeLists.txt file.

```cmake
FIND_PACKAGE(Protobuf 3.21.12 REQUIRED)
TARGET_LINK_LIBRARIES(<target> PUBLIC protobuf::libprotobuf protobuf-cpp-interface)
```

## Compilation

Compile to all languages:

```
find protobuf/definition -name "*.proto" -exec protoc -I=protobuf/definition --cpp_out=compiled/cpp --csharp_out=compiled/cs --python_out=compiled/python --go_out=compiled/go/ --go_opt=paths=source_relative {} +
```

To compile files to a specific language only, use the specific `*_out` options in command.
Note that protoc doesn't support double asterisks (**), so it should be used with `find`.

**C++**

```
find protobuf/definition -name "*.proto" -exec protoc -I=./definition --cpp_out=./compiled/cpp {} +
```

**C#**

```
find protobuf/definition -name "*.proto" -exec protoc -I=./definition --csharp_out=./compiled/cpp {} +
```

**Python**

```
find protobuf/definition -name "*.proto" -exec protoc -I=./definition --python_out=./compiled/cpp {} +
```

**GO**

protoc-gen-go needs to be installed!

```
find protobuf/definition -name "*.proto" -exec protoc -I=./definition --go_out=./compiled/go --go_opt=paths=source_relative {} +
```

