#pragma once

#include <modules/ExampleModule.pb.h>
#include <InternalProtocol.pb.h>
#include <ExternalProtocol.pb.h>

class ModuleMaintainer {
public:
	enum {
		BLINKER = 0,
		LIGHTS = 1
	};

	static ExampleModule::BlinkerStatus createBlinkerStatus(bool isFlashing);
	static ExampleModule::LightsStatus createLightsStatus(bool isOn);

	static void parseDeviceStatus(InternalProtocol::DeviceStatus deviceStatus);

	static void createBlinkerCommand();

	void parseBlinkerCommand();
	void parseLightsCommand();

private:
	/// Module enum. It is constant for every device / module
	static constexpr InternalProtocol::Device_Module module = InternalProtocol::Device_Module_EXAMPLE_MODULE;

};
