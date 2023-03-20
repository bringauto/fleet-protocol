// Generated by the protocol buffer compiler.  DO NOT EDIT!
// clang-format off
// source: modules/CarAccessoryModule.proto

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#if !defined(GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS)
 #define GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 0
#endif

#if GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS
 #import <Protobuf/GPBProtocolBuffers.h>
#else
 #import "GPBProtocolBuffers.h"
#endif

#if GOOGLE_PROTOBUF_OBJC_VERSION < 30007
#error This file was generated by a newer version of protoc which is incompatible with your Protocol Buffer library sources.
#endif
#if 30007 < GOOGLE_PROTOBUF_OBJC_MIN_SUPPORTED_VERSION
#error This file was generated by an older version of protoc which is incompatible with your Protocol Buffer library sources.
#endif

// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

CF_EXTERN_C_BEGIN

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Enum ButtonCommand_Command

typedef GPB_ENUM(ButtonCommand_Command) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  ButtonCommand_Command_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  ButtonCommand_Command_Press = 0,
};

GPBEnumDescriptor *ButtonCommand_Command_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL ButtonCommand_Command_IsValidValue(int32_t value);

#pragma mark - CarAccessoryModuleRoot

/**
 * Exposes the extension registry for this file.
 *
 * The base class provides:
 * @code
 *   + (GPBExtensionRegistry *)extensionRegistry;
 * @endcode
 * which is a @c GPBExtensionRegistry that includes all the extensions defined by
 * this file and all files that it depends on.
 **/
GPB_FINAL @interface CarAccessoryModuleRoot : GPBRootObject
@end

#pragma mark - ButtonStatus

typedef GPB_ENUM(ButtonStatus_FieldNumber) {
  ButtonStatus_FieldNumber_IsPressed = 1,
};

GPB_FINAL @interface ButtonStatus : GPBMessage

@property(nonatomic, readwrite) BOOL isPressed;

@end

#pragma mark - ButtonCommand

typedef GPB_ENUM(ButtonCommand_FieldNumber) {
  ButtonCommand_FieldNumber_Command = 1,
};

GPB_FINAL @interface ButtonCommand : GPBMessage

@property(nonatomic, readwrite) ButtonCommand_Command command;

@end

/**
 * Fetches the raw value of a @c ButtonCommand's @c command property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t ButtonCommand_Command_RawValue(ButtonCommand *message);
/**
 * Sets the raw value of an @c ButtonCommand's @c command property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetButtonCommand_Command_RawValue(ButtonCommand *message, int32_t value);

#pragma mark - ButtonError

typedef GPB_ENUM(ButtonError_FieldNumber) {
  ButtonError_FieldNumber_PressCount = 1,
};

GPB_FINAL @interface ButtonError : GPBMessage

@property(nonatomic, readwrite) uint32_t pressCount;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)

// clang-format on
