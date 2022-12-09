#pragma once

#include <modules/ExampleModule.pb.h>
#include <InternalProtocol.pb.h>
#include <ExternalProtocol.pb.h>

class ModuleMaintainer {
public:

	void createBlinkerStatus();
	void createLightsStatus();

	void parseBlinkerStatus();

	void createBlinkerCommand();

	void parseBlinkerCommand();
	void parseLightsCommand();

private:
	/// Module enum. It is constant for every device / module
	static constexpr ExampleModule::Device_Module module = ExampleModule::Device_Module_EXAMPLE_MODULE;

};
