#include <ModuleMaintainer.hpp>


ExampleModule::BlinkerStatus ModuleMaintainer::createBlinkerStatus(bool isFlashing) {
	ExampleModule::BlinkerStatus blinkerStatus;
	blinkerStatus.set_isflashing(isFlashing);
	return blinkerStatus;
}

ExampleModule::LightsStatus ModuleMaintainer::createLightsStatus(bool isOn) {
	ExampleModule::LightsStatus lightsStatus;
	lightsStatus.set_ison(isOn);
	return lightsStatus;
}

void ModuleMaintainer::parseDeviceStatus(InternalProtocol::DeviceStatus deviceStatus) {
	if (deviceStatus.device().devicetype() == BLINKER) {
		ExampleModule::BlinkerStatus blinkerStatus;
		blinkerStatus.ParseFromString(deviceStatus.statusdata());
		std::cout << "Blinker is flashing: " << blinkerStatus.isflashing() << std::endl;
	} else if (deviceStatus.device().devicetype() == LIGHTS) {
		ExampleModule::LightsStatus lightsStatus;
		lightsStatus.ParseFromString(deviceStatus.statusdata());
		std::cout << "Lights are on: " << lightsStatus.ison() << std::endl;
	} else {
		std::cout << "Unknown deviceType" << std::endl;
	}
}

ExampleModule::BlinkerCommand ModuleMaintainer::createBlinkerCommand(ExampleModule::BlinkerCommand::Command command) {
	ExampleModule::BlinkerCommand blinkerCommand;

	blinkerCommand.set_command(command);

	return blinkerCommand;
}

void ModuleMaintainer::parseBlinkerCommand(const std::string& commandData) {
	ExampleModule::BlinkerCommand blinkerCommand;
	blinkerCommand.ParseFromString(commandData);
	std::cout << "command = " << blinkerCommand.command();
}


