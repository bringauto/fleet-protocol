# Protobuf
Using Protobuf version 21.12
## Compilation
Compile to all languages: TODO add rest of them
```
$ protoc -I=./definition --cpp_out=./compiled/cpp --csharp_out=./compiled/cs --objc_out=./compiled/c --python_out=./compiled/python ./definition/**/*.proto
```
To compile files to a specific language, use the specific `*_out` options in one command
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
protoc -I=./definition --go_out=./compiled/go ./definition/**.proto
```