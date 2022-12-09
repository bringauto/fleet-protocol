#include "ProtocolMaintainer.hpp"



InternalProtocol::DeviceConnect
ProtocolMaintainer::createDeviceConnectMessage(std::string device_name, uint32_t device_type, uint32_t priority) {
	InternalProtocol::DeviceConnect deviceConnectMessage;

	deviceConnectMessage.set_devicename(device_name);
	// deviceConnectMessage.set_allocated_devicename(&device_name); TODO whats different??
	deviceConnectMessage.set_devicetype(device_type);
	deviceConnectMessage.set_priority(priority);
	deviceConnectMessage.set_module((InternalProtocol::DeviceConnect_Module)module_);

	return deviceConnectMessage;
}

void ProtocolMaintainer::parseDeviceConnectMessage(InternalProtocol::DeviceConnect deviceConnectMessage) {
	std::cout << "Got connect message containing: module " << deviceConnectMessage.module() << ", deviceName " << deviceConnectMessage.devicename() <<
	", deviceType " << deviceConnectMessage.devicetype() << ", priority " << deviceConnectMessage.priority() << std::endl;

}
