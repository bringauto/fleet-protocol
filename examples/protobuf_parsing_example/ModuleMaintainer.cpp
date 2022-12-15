#include "ModuleMaintainer.hpp"



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
		std::cout << "Blinker is flashing: " << blinkerStatus.isflashing();
	} else if (deviceStatus.device().devicetype() == LIGHTS) {
		ExampleModule::LightsStatus lightsStatus;
		lightsStatus.ParseFromString(deviceStatus.statusdata());
		std::cout << "Lights are on: " << lightsStatus.ison();
	} else {
		std::cout << "Unknown deviceType" << std::endl;
	}
}


