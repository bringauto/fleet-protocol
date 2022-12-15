#include "ProtocolMaintainer.hpp"



InternalProtocol::DeviceConnect
ProtocolMaintainer::createDeviceConnectMessage(std::string device_role, uint32_t device_type, std::string device_name,
											   uint32_t priority) {
	InternalProtocol::DeviceConnect deviceConnectMessage;
	InternalProtocol::Device deviceMessage;

	deviceMessage.set_module(module_);
	deviceMessage.set_devicerole(device_role);
	deviceMessage.set_devicename(device_name);
	// deviceConnectMessage.set_allocated_devicename(&device_name); TODO whats different??
	deviceMessage.set_devicetype(device_type);

	deviceConnectMessage.set_allocated_device(&deviceMessage);
	deviceConnectMessage.set_priority(priority);

	deviceConnectMessage.

	return deviceConnectMessage;
}

void ProtocolMaintainer::parseDeviceConnectMessage(InternalProtocol::DeviceConnect deviceConnectMessage) {
	const InternalProtocol::Device& deviceMessage = deviceConnectMessage.device();

	std::cout << "Got connect message containing: module " << deviceMessage.module() <<
		", deviceRole " << deviceMessage.devicerole() << ", deviceName " << deviceMessage.devicename() <<
		", deviceType " << deviceMessage.devicetype() << ", priority " << deviceConnectMessage.priority() << std::endl;

}
