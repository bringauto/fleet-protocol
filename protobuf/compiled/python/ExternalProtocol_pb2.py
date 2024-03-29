# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: ExternalProtocol.proto
"""Generated protocol buffer code."""
from google.protobuf.internal import builder as _builder
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


import InternalProtocol_pb2 as InternalProtocol__pb2


DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\x16\x45xternalProtocol.proto\x12\x10\x45xternalProtocol\x1a\x16InternalProtocol.proto\"\xc7\x01\n\x0e\x45xternalServer\x12<\n\x0f\x63onnectResponse\x18\x01 \x01(\x0b\x32!.ExternalProtocol.ConnectResponseH\x00\x12:\n\x0estatusResponse\x18\x02 \x01(\x0b\x32 .ExternalProtocol.StatusResponseH\x00\x12,\n\x07\x63ommand\x18\x03 \x01(\x0b\x32\x19.ExternalProtocol.CommandH\x00\x42\r\n\x0bMessageType\"\xb7\x01\n\x0e\x45xternalClient\x12,\n\x07\x63onnect\x18\x01 \x01(\x0b\x32\x19.ExternalProtocol.ConnectH\x00\x12*\n\x06status\x18\x02 \x01(\x0b\x32\x18.ExternalProtocol.StatusH\x00\x12<\n\x0f\x63ommandResponse\x18\x03 \x01(\x0b\x32!.ExternalProtocol.CommandResponseH\x00\x42\r\n\x0bMessageType\"m\n\x07\x43onnect\x12\x11\n\tsessionId\x18\x01 \x01(\t\x12\x0f\n\x07\x63ompany\x18\x02 \x01(\t\x12\x13\n\x0bvehicleName\x18\x03 \x01(\t\x12)\n\x07\x64\x65vices\x18\x04 \x03(\x0b\x32\x18.InternalProtocol.Device\"~\n\x0f\x43onnectResponse\x12\x11\n\tsessionId\x18\x01 \x01(\t\x12\x34\n\x04type\x18\x02 \x01(\x0e\x32&.ExternalProtocol.ConnectResponse.Type\"\"\n\x04Type\x12\x06\n\x02OK\x10\x00\x12\x12\n\x0e\x41LREADY_LOGGED\x10\x01\"\x97\x02\n\x06Status\x12\x11\n\tsessionId\x18\x01 \x01(\t\x12\x39\n\x0b\x64\x65viceState\x18\x02 \x01(\x0e\x32$.ExternalProtocol.Status.DeviceState\x12\x16\n\x0emessageCounter\x18\x03 \x01(\r\x12\x34\n\x0c\x64\x65viceStatus\x18\x04 \x01(\x0b\x32\x1e.InternalProtocol.DeviceStatus\x12\x19\n\x0c\x65rrorMessage\x18\x05 \x01(\x0cH\x00\x88\x01\x01\"E\n\x0b\x44\x65viceState\x12\x0e\n\nCONNECTING\x10\x00\x12\x0b\n\x07RUNNING\x10\x01\x12\t\n\x05\x45RROR\x10\x02\x12\x0e\n\nDISCONNECT\x10\x03\x42\x0f\n\r_errorMessage\"\x80\x01\n\x0eStatusResponse\x12\x11\n\tsessionId\x18\x01 \x01(\t\x12\x33\n\x04type\x18\x02 \x01(\x0e\x32%.ExternalProtocol.StatusResponse.Type\x12\x16\n\x0emessageCounter\x18\x03 \x01(\r\"\x0e\n\x04Type\x12\x06\n\x02OK\x10\x00\"l\n\x07\x43ommand\x12\x11\n\tsessionId\x18\x01 \x01(\t\x12\x16\n\x0emessageCounter\x18\x02 \x01(\r\x12\x36\n\rdeviceCommand\x18\x03 \x01(\x0b\x32\x1f.InternalProtocol.DeviceCommand\"\xcb\x01\n\x0f\x43ommandResponse\x12\x11\n\tsessionId\x18\x01 \x01(\t\x12\x34\n\x04type\x18\x02 \x01(\x0e\x32&.ExternalProtocol.CommandResponse.Type\x12\x16\n\x0emessageCounter\x18\x03 \x01(\r\"W\n\x04Type\x12\x06\n\x02OK\x10\x00\x12\x18\n\x14\x44\x45VICE_NOT_CONNECTED\x10\x01\x12\x18\n\x14\x44\x45VICE_NOT_SUPPORTED\x10\x02\x12\x13\n\x0fINVALID_COMMAND\x10\x03\x42>Z!../internal/pkg/ba_proto;ba_proto\xaa\x02\x18Google.Protobuf.ba_protob\x06proto3')

_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, globals())
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'ExternalProtocol_pb2', globals())
if _descriptor._USE_C_DESCRIPTORS == False:

  DESCRIPTOR._options = None
  DESCRIPTOR._serialized_options = b'Z!../internal/pkg/ba_proto;ba_proto\252\002\030Google.Protobuf.ba_proto'
  _EXTERNALSERVER._serialized_start=69
  _EXTERNALSERVER._serialized_end=268
  _EXTERNALCLIENT._serialized_start=271
  _EXTERNALCLIENT._serialized_end=454
  _CONNECT._serialized_start=456
  _CONNECT._serialized_end=565
  _CONNECTRESPONSE._serialized_start=567
  _CONNECTRESPONSE._serialized_end=693
  _CONNECTRESPONSE_TYPE._serialized_start=659
  _CONNECTRESPONSE_TYPE._serialized_end=693
  _STATUS._serialized_start=696
  _STATUS._serialized_end=975
  _STATUS_DEVICESTATE._serialized_start=889
  _STATUS_DEVICESTATE._serialized_end=958
  _STATUSRESPONSE._serialized_start=978
  _STATUSRESPONSE._serialized_end=1106
  _STATUSRESPONSE_TYPE._serialized_start=659
  _STATUSRESPONSE_TYPE._serialized_end=673
  _COMMAND._serialized_start=1108
  _COMMAND._serialized_end=1216
  _COMMANDRESPONSE._serialized_start=1219
  _COMMANDRESPONSE._serialized_end=1422
  _COMMANDRESPONSE_TYPE._serialized_start=1335
  _COMMANDRESPONSE_TYPE._serialized_end=1422
# @@protoc_insertion_point(module_scope)
