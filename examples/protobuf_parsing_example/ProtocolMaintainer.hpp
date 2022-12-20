#pragma once

#include <modules/ExampleModule.pb.h>
#include <InternalProtocol.pb.h>
#include <ExternalProtocol.pb.h>

class ProtocolMaintainer {
public:
	static InternalProtocol::Device
	createDevice(std::string device_role, uint32_t device_type, std::string device_name);

	static InternalProtocol::DeviceConnect
	createDeviceConnectMessage(const InternalProtocol::Device& device, uint32_t priority);

	static void parseDeviceConnectMessage(const InternalProtocol::DeviceConnect& deviceConnectMessage);

	static InternalProtocol::DeviceConnectResponse createDeviceConnectResponseMessage(
			InternalProtocol::DeviceConnectResponse::ResponseType responseType);

	static void parseDeviceConnectResponseMessage(const InternalProtocol::DeviceConnectResponse& deviceConnectResponse);

	/**
	 * @brief Function for packing messages into Module messages
	 */
	static InternalProtocol::DeviceStatus createExampleModuleStatus(const InternalProtocol::Device& device, std::string statusData);

	void parseExampleModuleCommand();

	void createExampleModuleError();
	void createBlinkerErrorMessage();

	// TODO external communication

private:
	/// Module enum. It is constant for every device / module
	static constexpr InternalProtocol::Device_Module module_ = InternalProtocol::Device_Module_EXAMPLE_MODULE;
	std::string sessionId {"8p2HPtE9"}; 		/// session ID should be randomly generated and prepended with robot ID
};
