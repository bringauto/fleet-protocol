# Protobuf
Using Protobuf version 21.12

## Link
CMakeLists in this directory adds two static library `protobuf_cpp`

To link it, use the following statements in CMakeLists.txt:

```angular2html
TARGET_LINK_LIBRARIES(<target> PUBLIC ${PROJECT_NAME}::protobuf_cpp)
```

## Compilation
Compile to all languages:
```
$ protoc -I=./definition --cpp_out=./compiled/cpp --csharp_out=./compiled/cs --python_out=./compiled/python --go_out=./compiled/go/ --go_opt=paths=source_relative ./definition/**/*.proto
```
To compile files to a specific language only, use the specific `*_out` options in command

**C++**
```
protoc -I=./definition --cpp_out=./compiled/cpp ./definition/*/*.proto
```

**C#**
TODO

**Python**
TODO

**GO** 

protoc-gen-go needed!
```
protoc -I=./definition --go_out=./compiled/go --go_opt=paths=source_relative ./definition/**.proto
```

