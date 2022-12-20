#include "ProtocolMaintainer.hpp"

InternalProtocol::Device
ProtocolMaintainer::createDevice(std::string device_role, uint32_t device_type, std::string device_name) {
	InternalProtocol::Device deviceMessage;

	deviceMessage.set_module(module_);
	deviceMessage.set_devicerole(device_role);
	deviceMessage.set_devicename(device_name);
	deviceMessage.set_devicetype(device_type);

	//deviceMessage->release_devicename();
	//deviceMessage->release_devicerole();
	return deviceMessage;
}

InternalProtocol::DeviceConnect
ProtocolMaintainer::createDeviceConnectMessage(InternalProtocol::Device device, uint32_t priority) {
	InternalProtocol::DeviceConnect deviceConnectMessage;

	//deviceConnectMessage.mutable_device() = device;

	InternalProtocol::Device* tmpDev = deviceConnectMessage.mutable_device();
	tmpDev->CopyFrom(device);
	deviceConnectMessage.set_priority(priority);

	//deviceConnectMessage.release_device(); /// release_* prevents protobuf from deleting the object, we need to use device more times, therefore we need to call release

	return deviceConnectMessage;
}

void ProtocolMaintainer::parseDeviceConnectMessage(InternalProtocol::DeviceConnect deviceConnectMessage) {
	const InternalProtocol::Device &deviceMessage = deviceConnectMessage.device();

	if(deviceMessage.module())

	std::cout << "Got connect message containing: module " << deviceMessage.module() <<
			  ", deviceRole " << deviceMessage.devicerole() << ", deviceName " << deviceMessage.devicename() <<
			  ", deviceType " << deviceMessage.devicetype() << ", priority " << deviceConnectMessage.priority()
			  << std::endl;

}

InternalProtocol::DeviceConnectResponse ProtocolMaintainer::createDeviceConnectResponseMessage(
		InternalProtocol::DeviceConnectResponse::ResponseType responseType) {
	InternalProtocol::DeviceConnectResponse deviceConnectResponse;

	deviceConnectResponse.set_responsetype(responseType);
	return deviceConnectResponse;
}

void ProtocolMaintainer::parseDeviceConnectResponseMessage(InternalProtocol::DeviceConnectResponse deviceConnectResponse) {
	std::cout << "Got connect response message with type: " << deviceConnectResponse.responsetype() << std::endl;
}

InternalProtocol::DeviceStatus
ProtocolMaintainer::createExampleModuleStatus(InternalProtocol::Device device, std::string statusData) {
	InternalProtocol::DeviceStatus deviceStatus;

	InternalProtocol::Device* tmpDev = deviceStatus.mutable_device();
	tmpDev->CopyFrom(device);

	deviceStatus.set_statusdata(statusData);

	return deviceStatus;
}


