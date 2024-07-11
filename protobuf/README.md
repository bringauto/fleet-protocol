# Protobuf

Using Protobuf version 5.27.2

## Usage

CMakeLists in this directory adds library `protobuf-cpp-interface`.
To use this library, it is necessary to link `libprotobuf` library.

Usage example is in [examples/protobuf_parsing_example](examples/protobuf_parsing_example).

To link the library, use the following CMake commands in your CMakeLists.txt file.

```cmake
FIND_PACKAGE(Protobuf 5.27.2 REQUIRED)
TARGET_LINK_LIBRARIES(<target> PUBLIC protobuf::libprotobuf protobuf-cpp-interface)
```

## Compilation

#### Requirements

- desired version of `protoc` installed ([prebuilt binaries](https://github.com/protocolbuffers/protobuf/releases))
- `protoc-gen-go` needs to be installed to generate go files (set env value GOBIN to the path where protoc is installed first)
```bash
go install google.golang.org/protobuf/cmd/protoc-gen-go@latest
```

##

Compile to all languages:

```
find protobuf/definition -name "*.proto" -exec protoc -I=./protobuf/definition --cpp_out=./protobuf/compiled/cpp --csharp_out=./protobuf/compiled/cs --python_out=./protobuf/compiled/python --go_out=./protobuf/compiled/go/ --go_opt=paths=source_relative {} +
```

To compile files to a specific language only, use the specific `*_out` options in command.
Note that protoc doesn't support double asterisks (**), so it should be used with `find`.

**C++**

```
find protobuf/definition -name "*.proto" -exec protoc -I=./protobuf/definition --cpp_out=./protobuf/compiled/cpp {} +
```

**C#**

```
find protobuf/definition -name "*.proto" -exec protoc -I=./protobuf/definition --csharp_out=./protobuf/compiled/cs {} +
```

**Python**

```
find protobuf/definition -name "*.proto" -exec protoc -I=./protobuf/definition --python_out=./protobuf/compiled/python {} +
```

**GO**

```
find protobuf/definition -name "*.proto" -exec protoc -I=./protobuf/definition --go_out=./protobuf/compiled/go --go_opt=paths=source_relative {} +
```

