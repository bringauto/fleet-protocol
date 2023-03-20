// Generated by the protocol buffer compiler.  DO NOT EDIT!
// clang-format off
// source: InternalProtocol.proto

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#if !defined(GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS)
 #define GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 0
#endif

#if GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS
 #import <Protobuf/GPBProtocolBuffers_RuntimeSupport.h>
#else
 #import "GPBProtocolBuffers_RuntimeSupport.h"
#endif

#if GOOGLE_PROTOBUF_OBJC_VERSION < 30007
#error This file was generated by a newer version of protoc which is incompatible with your Protocol Buffer library sources.
#endif
#if 30007 < GOOGLE_PROTOBUF_OBJC_MIN_SUPPORTED_VERSION
#error This file was generated by an older version of protoc which is incompatible with your Protocol Buffer library sources.
#endif

#import <stdatomic.h>

#import "InternalProtocol.pbobjc.h"
// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"

#pragma mark - Objective-C Class declarations
// Forward declarations of Objective-C classes that we can use as
// static values in struct initializers.
// We don't use [Foo class] because it is not a static value.
GPBObjCClassDeclaration(Device);
GPBObjCClassDeclaration(DeviceCommand);
GPBObjCClassDeclaration(DeviceConnect);
GPBObjCClassDeclaration(DeviceConnectResponse);
GPBObjCClassDeclaration(DeviceStatus);

#pragma mark - InternalProtocolRoot

@implementation InternalProtocolRoot

// No extensions in the file and no imports, so no need to generate
// +extensionRegistry.

@end

static GPBFileDescription InternalProtocolRoot_FileDescription = {
  .package = "InternalProtocol",
  .prefix = NULL,
  .syntax = GPBFileSyntaxProto3
};

#pragma mark - Enum DeviceConnectResponse_ResponseType

GPBEnumDescriptor *DeviceConnectResponse_ResponseType_EnumDescriptor(void) {
  static _Atomic(GPBEnumDescriptor*) descriptor = nil;
  if (!descriptor) {
    GPB_DEBUG_CHECK_RUNTIME_VERSIONS();
    static const char *valueNames =
        "Ok\000AlreadyConnected\000ModuleNotSupported\000D"
        "eviceNotSupported\000HigherPriorityAlreadyC"
        "onnected\000";
    static const int32_t values[] = {
        DeviceConnectResponse_ResponseType_Ok,
        DeviceConnectResponse_ResponseType_AlreadyConnected,
        DeviceConnectResponse_ResponseType_ModuleNotSupported,
        DeviceConnectResponse_ResponseType_DeviceNotSupported,
        DeviceConnectResponse_ResponseType_HigherPriorityAlreadyConnected,
    };
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(DeviceConnectResponse_ResponseType)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:DeviceConnectResponse_ResponseType_IsValidValue
                                            flags:GPBEnumDescriptorInitializationFlag_None];
    GPBEnumDescriptor *expected = nil;
    if (!atomic_compare_exchange_strong(&descriptor, &expected, worker)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL DeviceConnectResponse_ResponseType_IsValidValue(int32_t value__) {
  switch (value__) {
    case DeviceConnectResponse_ResponseType_Ok:
    case DeviceConnectResponse_ResponseType_AlreadyConnected:
    case DeviceConnectResponse_ResponseType_ModuleNotSupported:
    case DeviceConnectResponse_ResponseType_DeviceNotSupported:
    case DeviceConnectResponse_ResponseType_HigherPriorityAlreadyConnected:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - Enum Device_Module

GPBEnumDescriptor *Device_Module_EnumDescriptor(void) {
  static _Atomic(GPBEnumDescriptor*) descriptor = nil;
  if (!descriptor) {
    GPB_DEBUG_CHECK_RUNTIME_VERSIONS();
    static const char *valueNames =
        "ReservedModule\000MissionModule\000CarAccessor"
        "yModule\000ExampleModule\000";
    static const int32_t values[] = {
        Device_Module_ReservedModule,
        Device_Module_MissionModule,
        Device_Module_CarAccessoryModule,
        Device_Module_ExampleModule,
    };
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(Device_Module)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:Device_Module_IsValidValue
                                            flags:GPBEnumDescriptorInitializationFlag_None];
    GPBEnumDescriptor *expected = nil;
    if (!atomic_compare_exchange_strong(&descriptor, &expected, worker)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL Device_Module_IsValidValue(int32_t value__) {
  switch (value__) {
    case Device_Module_ReservedModule:
    case Device_Module_MissionModule:
    case Device_Module_CarAccessoryModule:
    case Device_Module_ExampleModule:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - DeviceConnect

@implementation DeviceConnect

@dynamic hasDevice, device;
@dynamic priority;

typedef struct DeviceConnect__storage_ {
  uint32_t _has_storage_[1];
  uint32_t priority;
  Device *device;
} DeviceConnect__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    GPB_DEBUG_CHECK_RUNTIME_VERSIONS();
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "device",
        .dataTypeSpecific.clazz = GPBObjCClass(Device),
        .number = DeviceConnect_FieldNumber_Device,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(DeviceConnect__storage_, device),
        .flags = GPBFieldOptional,
        .dataType = GPBDataTypeMessage,
      },
      {
        .name = "priority",
        .dataTypeSpecific.clazz = Nil,
        .number = DeviceConnect_FieldNumber_Priority,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(DeviceConnect__storage_, priority),
        .flags = (GPBFieldFlags)(GPBFieldOptional | GPBFieldClearHasIvarOnZero),
        .dataType = GPBDataTypeUInt32,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:GPBObjCClass(DeviceConnect)
                                   messageName:@"DeviceConnect"
                               fileDescription:&InternalProtocolRoot_FileDescription
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(DeviceConnect__storage_)
                                         flags:(GPBDescriptorInitializationFlags)(GPBDescriptorInitializationFlag_UsesClassRefs | GPBDescriptorInitializationFlag_Proto3OptionalKnown | GPBDescriptorInitializationFlag_ClosedEnumSupportKnown)];
    #if defined(DEBUG) && DEBUG
      NSAssert(descriptor == nil, @"Startup recursed!");
    #endif  // DEBUG
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - DeviceConnectResponse

@implementation DeviceConnectResponse

@dynamic responseType;

typedef struct DeviceConnectResponse__storage_ {
  uint32_t _has_storage_[1];
  DeviceConnectResponse_ResponseType responseType;
} DeviceConnectResponse__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    GPB_DEBUG_CHECK_RUNTIME_VERSIONS();
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "responseType",
        .dataTypeSpecific.enumDescFunc = DeviceConnectResponse_ResponseType_EnumDescriptor,
        .number = DeviceConnectResponse_FieldNumber_ResponseType,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(DeviceConnectResponse__storage_, responseType),
        .flags = (GPBFieldFlags)(GPBFieldOptional | GPBFieldTextFormatNameCustom | GPBFieldHasEnumDescriptor | GPBFieldClearHasIvarOnZero),
        .dataType = GPBDataTypeEnum,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:GPBObjCClass(DeviceConnectResponse)
                                   messageName:@"DeviceConnectResponse"
                               fileDescription:&InternalProtocolRoot_FileDescription
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(DeviceConnectResponse__storage_)
                                         flags:(GPBDescriptorInitializationFlags)(GPBDescriptorInitializationFlag_UsesClassRefs | GPBDescriptorInitializationFlag_Proto3OptionalKnown | GPBDescriptorInitializationFlag_ClosedEnumSupportKnown)];
#if !GPBOBJC_SKIP_MESSAGE_TEXTFORMAT_EXTRAS
    static const char *extraTextFormatInfo =
        "\001\001\014\000";
    [localDescriptor setupExtraTextInfo:extraTextFormatInfo];
#endif  // !GPBOBJC_SKIP_MESSAGE_TEXTFORMAT_EXTRAS
    #if defined(DEBUG) && DEBUG
      NSAssert(descriptor == nil, @"Startup recursed!");
    #endif  // DEBUG
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

int32_t DeviceConnectResponse_ResponseType_RawValue(DeviceConnectResponse *message) {
  GPBDescriptor *descriptor = [DeviceConnectResponse descriptor];
  GPBFieldDescriptor *field = [descriptor fieldWithNumber:DeviceConnectResponse_FieldNumber_ResponseType];
  return GPBGetMessageRawEnumField(message, field);
}

void SetDeviceConnectResponse_ResponseType_RawValue(DeviceConnectResponse *message, int32_t value) {
  GPBDescriptor *descriptor = [DeviceConnectResponse descriptor];
  GPBFieldDescriptor *field = [descriptor fieldWithNumber:DeviceConnectResponse_FieldNumber_ResponseType];
  GPBSetMessageRawEnumField(message, field, value);
}

#pragma mark - DeviceStatus

@implementation DeviceStatus

@dynamic hasDevice, device;
@dynamic statusData;

typedef struct DeviceStatus__storage_ {
  uint32_t _has_storage_[1];
  Device *device;
  NSData *statusData;
} DeviceStatus__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    GPB_DEBUG_CHECK_RUNTIME_VERSIONS();
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "device",
        .dataTypeSpecific.clazz = GPBObjCClass(Device),
        .number = DeviceStatus_FieldNumber_Device,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(DeviceStatus__storage_, device),
        .flags = GPBFieldOptional,
        .dataType = GPBDataTypeMessage,
      },
      {
        .name = "statusData",
        .dataTypeSpecific.clazz = Nil,
        .number = DeviceStatus_FieldNumber_StatusData,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(DeviceStatus__storage_, statusData),
        .flags = (GPBFieldFlags)(GPBFieldOptional | GPBFieldTextFormatNameCustom | GPBFieldClearHasIvarOnZero),
        .dataType = GPBDataTypeBytes,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:GPBObjCClass(DeviceStatus)
                                   messageName:@"DeviceStatus"
                               fileDescription:&InternalProtocolRoot_FileDescription
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(DeviceStatus__storage_)
                                         flags:(GPBDescriptorInitializationFlags)(GPBDescriptorInitializationFlag_UsesClassRefs | GPBDescriptorInitializationFlag_Proto3OptionalKnown | GPBDescriptorInitializationFlag_ClosedEnumSupportKnown)];
#if !GPBOBJC_SKIP_MESSAGE_TEXTFORMAT_EXTRAS
    static const char *extraTextFormatInfo =
        "\001\002\n\000";
    [localDescriptor setupExtraTextInfo:extraTextFormatInfo];
#endif  // !GPBOBJC_SKIP_MESSAGE_TEXTFORMAT_EXTRAS
    #if defined(DEBUG) && DEBUG
      NSAssert(descriptor == nil, @"Startup recursed!");
    #endif  // DEBUG
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - DeviceCommand

@implementation DeviceCommand

@dynamic commandData;

typedef struct DeviceCommand__storage_ {
  uint32_t _has_storage_[1];
  NSData *commandData;
} DeviceCommand__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    GPB_DEBUG_CHECK_RUNTIME_VERSIONS();
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "commandData",
        .dataTypeSpecific.clazz = Nil,
        .number = DeviceCommand_FieldNumber_CommandData,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(DeviceCommand__storage_, commandData),
        .flags = (GPBFieldFlags)(GPBFieldOptional | GPBFieldTextFormatNameCustom | GPBFieldClearHasIvarOnZero),
        .dataType = GPBDataTypeBytes,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:GPBObjCClass(DeviceCommand)
                                   messageName:@"DeviceCommand"
                               fileDescription:&InternalProtocolRoot_FileDescription
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(DeviceCommand__storage_)
                                         flags:(GPBDescriptorInitializationFlags)(GPBDescriptorInitializationFlag_UsesClassRefs | GPBDescriptorInitializationFlag_Proto3OptionalKnown | GPBDescriptorInitializationFlag_ClosedEnumSupportKnown)];
#if !GPBOBJC_SKIP_MESSAGE_TEXTFORMAT_EXTRAS
    static const char *extraTextFormatInfo =
        "\001\001\013\000";
    [localDescriptor setupExtraTextInfo:extraTextFormatInfo];
#endif  // !GPBOBJC_SKIP_MESSAGE_TEXTFORMAT_EXTRAS
    #if defined(DEBUG) && DEBUG
      NSAssert(descriptor == nil, @"Startup recursed!");
    #endif  // DEBUG
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - Device

@implementation Device

@dynamic module;
@dynamic deviceType;
@dynamic deviceRole;
@dynamic deviceName;

typedef struct Device__storage_ {
  uint32_t _has_storage_[1];
  Device_Module module;
  uint32_t deviceType;
  NSString *deviceRole;
  NSString *deviceName;
} Device__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    GPB_DEBUG_CHECK_RUNTIME_VERSIONS();
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "module",
        .dataTypeSpecific.enumDescFunc = Device_Module_EnumDescriptor,
        .number = Device_FieldNumber_Module,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(Device__storage_, module),
        .flags = (GPBFieldFlags)(GPBFieldOptional | GPBFieldHasEnumDescriptor | GPBFieldClearHasIvarOnZero),
        .dataType = GPBDataTypeEnum,
      },
      {
        .name = "deviceType",
        .dataTypeSpecific.clazz = Nil,
        .number = Device_FieldNumber_DeviceType,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(Device__storage_, deviceType),
        .flags = (GPBFieldFlags)(GPBFieldOptional | GPBFieldTextFormatNameCustom | GPBFieldClearHasIvarOnZero),
        .dataType = GPBDataTypeUInt32,
      },
      {
        .name = "deviceRole",
        .dataTypeSpecific.clazz = Nil,
        .number = Device_FieldNumber_DeviceRole,
        .hasIndex = 2,
        .offset = (uint32_t)offsetof(Device__storage_, deviceRole),
        .flags = (GPBFieldFlags)(GPBFieldOptional | GPBFieldTextFormatNameCustom | GPBFieldClearHasIvarOnZero),
        .dataType = GPBDataTypeString,
      },
      {
        .name = "deviceName",
        .dataTypeSpecific.clazz = Nil,
        .number = Device_FieldNumber_DeviceName,
        .hasIndex = 3,
        .offset = (uint32_t)offsetof(Device__storage_, deviceName),
        .flags = (GPBFieldFlags)(GPBFieldOptional | GPBFieldTextFormatNameCustom | GPBFieldClearHasIvarOnZero),
        .dataType = GPBDataTypeString,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:GPBObjCClass(Device)
                                   messageName:@"Device"
                               fileDescription:&InternalProtocolRoot_FileDescription
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(Device__storage_)
                                         flags:(GPBDescriptorInitializationFlags)(GPBDescriptorInitializationFlag_UsesClassRefs | GPBDescriptorInitializationFlag_Proto3OptionalKnown | GPBDescriptorInitializationFlag_ClosedEnumSupportKnown)];
#if !GPBOBJC_SKIP_MESSAGE_TEXTFORMAT_EXTRAS
    static const char *extraTextFormatInfo =
        "\003\002\n\000\003\n\000\004\n\000";
    [localDescriptor setupExtraTextInfo:extraTextFormatInfo];
#endif  // !GPBOBJC_SKIP_MESSAGE_TEXTFORMAT_EXTRAS
    #if defined(DEBUG) && DEBUG
      NSAssert(descriptor == nil, @"Startup recursed!");
    #endif  // DEBUG
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

int32_t Device_Module_RawValue(Device *message) {
  GPBDescriptor *descriptor = [Device descriptor];
  GPBFieldDescriptor *field = [descriptor fieldWithNumber:Device_FieldNumber_Module];
  return GPBGetMessageRawEnumField(message, field);
}

void SetDevice_Module_RawValue(Device *message, int32_t value) {
  GPBDescriptor *descriptor = [Device descriptor];
  GPBFieldDescriptor *field = [descriptor fieldWithNumber:Device_FieldNumber_Module];
  GPBSetMessageRawEnumField(message, field, value);
}


#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)

// clang-format on
