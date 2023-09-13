#pragma once

#include <modules/ExampleModule.pb.h>
#include <InternalProtocol.pb.h>
#include <ExternalProtocol.pb.h>

/**
 * @brief This is a class working on ExampleModule. Serves for helping a customer use protobuf
 */
class ModuleMaintainer {
public:
	/**
	 * @brief Enumeration for all available devices in a module
	 */
	enum {
		BLINKER = 0,
		LIGHTS = 1
	};

	/**
	 * @brief accept data and put them in protobuf message structure.
	 * @param isFlashing
	 * @return
	 */
	static ExampleModule::BlinkerStatus createBlinkerStatus(bool isFlashing);
	static ExampleModule::LightsStatus createLightsStatus(bool isOn);

	/**
	 * @brief Parse, deserialize and print DeviceStatus
	 * @param deviceStatus
	 */
	static void parseDeviceStatus(InternalProtocol::DeviceStatus deviceStatus);

	/**
	 * @brief Create command for a concrete device
	 * @param command enum value
	 * @return BlinkerCommand
	 */
	static ExampleModule::BlinkerCommand createBlinkerCommand(ExampleModule::BlinkerCommand::Command command);

	/**
	 * @brief Parse and print command for a concrete device
	 * @param commandData binary data that are deserialized
	 */
	static void parseBlinkerCommand(const std::string& commandData);

private:
	/// Module enum. It is constant for every device / module
	static constexpr InternalProtocol::Device_Module module_ = InternalProtocol::Device_Module_EXAMPLE_MODULE;

};
