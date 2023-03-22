# Protobuf
Using Protobuf version 21.12

## Link
CMakeLists in this directory adds two static libraries: `protobuf_c` and `protobuf_cpp`

To link them, use one of the following statements in CMakeLists.txt:

**C**
```angular2html
TARGET_LINK_LIBRARIES(<target> PUBLIC ${PROJECT_NAME}::protobuf_c)
```
**C++**
```angular2html
TARGET_LINK_LIBRARIES(<target> PUBLIC ${PROJECT_NAME}::protobuf_cpp)
```

## Compilation
Compile to all languages:
```
$ protoc -I=./definition --cpp_out=./compiled/cpp --csharp_out=./compiled/cs --objc_out=./compiled/c --python_out=./compiled/python --go_out=./compiled/go/ --go_opt=paths=source_relative ./definition/**/*.proto
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

