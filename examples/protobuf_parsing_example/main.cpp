#include <iostream>

#include <modules/ExampleModule.pb.h>
#include <ProtocolMaintainer.hpp>
#include <ModuleMaintainer.hpp>

void serializeConnectMessages(const InternalProtocol::Device& device) {
	auto connectMessage = ProtocolMaintainer::createDeviceConnectMessage(device, 1); // created in Internal Client
	ProtocolMaintainer::parseDeviceConnectMessage(connectMessage); // Internal Server

	auto deviceConnectResponse = ProtocolMaintainer::createDeviceConnectResponseMessage(
			InternalProtocol::DeviceConnectResponse_ResponseType_OK); // Internal Server
	ProtocolMaintainer::parseDeviceConnectResponseMessage(deviceConnectResponse); // Internal Client

	auto device2 = ProtocolMaintainer::createDevice("rightBlinker", ModuleMaintainer::BLINKER, "blinkerA1"); // Internal Client
	std::vector<InternalProtocol::Device> devices = {device, device2};
	auto externalConnect = ProtocolMaintainer::createConnectMessage("BringAuto", "Vehicle1", devices);

	ProtocolMaintainer::parseExternalClientMessage(externalConnect);
}

void serializeStatusMessages(const InternalProtocol::Device& device) {
	auto blinkerStatus = ModuleMaintainer::createBlinkerStatus(true); // created in Device

	std::string bytes = blinkerStatus.SerializeAsString();	// Message must be serialized as string, so it can be put into bytes field
	auto deviceStatus = ProtocolMaintainer::createDeviceStatus(device, bytes); // Internal Client

	auto status = ProtocolMaintainer::createExternalClientStatus(deviceStatus); // External Client

	auto deviceStatusParsed = ProtocolMaintainer::parseExternalClientMessage(status); // internal server / external server
	ModuleMaintainer::parseDeviceStatus(deviceStatusParsed); // device / cloud application
}

void serializeCommandMessages(const InternalProtocol::Device& device) {
	auto blinkerCommand = ModuleMaintainer::createBlinkerCommand(ExampleModule::BlinkerCommand_Command_TURN_OFF); // created in Cloud application for controlling device
	auto deviceCommand = ProtocolMaintainer::createDeviceCommand(blinkerCommand.SerializeAsString()); // External server / Internal Client

	auto command = ProtocolMaintainer::createExternalServerCommand(deviceCommand, device); // External Server

	auto commandData = ProtocolMaintainer::parseExternalServerMessage(command); // parse all parts of the command, External Client
	ModuleMaintainer::parseBlinkerCommand(commandData); // called based on deviceType in the Command, the Command sent to Device doesn't have device identification

}

int main(int argc, char **argv) {
	// creating device
	auto device = ProtocolMaintainer::createDevice("leftBlinker", ModuleMaintainer::BLINKER, "blinkerA1"); // Internal Client

	serializeConnectMessages(device);
	serializeStatusMessages(device);
	serializeCommandMessages(device);
}