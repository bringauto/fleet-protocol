#pragma once

#include <modules/ExampleModule.pb.h>
#include <InternalProtocol.pb.h>
#include <ExternalProtocol.pb.h>

class ProtocolMaintainer {
public:
	static InternalProtocol::DeviceConnect createDeviceConnectMessage(std::string device_name, uint32_t device_type, uint32_t priority);

	static void parseDeviceConnectMessage(InternalProtocol::DeviceConnect deviceConnectMessage);

	void createDeviceConnectResponseMessage();

	/**
	 * @brief Function for packing messages into Module messages
	 */
	void createExampleModuleStatus();

	void parseExampleModuleCommand();

	void createExampleModuleError();
	void createBlinkerErrorMessage();

	// TODO external communication

private:
	/// Module enum. It is constant for every device / module
	static constexpr ExampleModule::Device_Module module_ = ExampleModule::Device_Module_EXAMPLE_MODULE;
	std::string sessionId {"8p2HPtE9"}; 		/// session ID should be randomly generated and prepended with robot ID
};
