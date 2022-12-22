#include "ProtocolMaintainer.hpp"

InternalProtocol::Device
ProtocolMaintainer::createDevice(std::string device_role, uint32_t device_type, std::string device_name) {
	InternalProtocol::Device deviceMessage;

	deviceMessage.set_module(module_);
	deviceMessage.set_devicerole(device_role);
	deviceMessage.set_devicename(device_name);
	deviceMessage.set_devicetype(device_type);

	//deviceMessage->release_devicename();
	//deviceMessage->release_devicerole();
	return deviceMessage;
}

InternalProtocol::DeviceConnect
ProtocolMaintainer::createDeviceConnectMessage(const InternalProtocol::Device& device, uint32_t priority) {
	InternalProtocol::DeviceConnect deviceConnectMessage;

	//deviceConnectMessage.mutable_device() = device;

	InternalProtocol::Device* tmpDev = deviceConnectMessage.mutable_device();
	tmpDev->CopyFrom(device);
	deviceConnectMessage.set_priority(priority);

	//deviceConnectMessage.release_device(); /// release_* prevents protobuf from deleting the object, we need to use device more times, therefore we need to call release

	return deviceConnectMessage;
}

void ProtocolMaintainer::parseDeviceConnectMessage(const InternalProtocol::DeviceConnect& deviceConnectMessage) {
	const InternalProtocol::Device &deviceMessage = deviceConnectMessage.device();

	if(deviceMessage.module())

	std::cout << "Got connect message containing: module " << deviceMessage.module() <<
			  ", deviceRole " << deviceMessage.devicerole() << ", deviceName " << deviceMessage.devicename() <<
			  ", deviceType " << deviceMessage.devicetype() << ", priority " << deviceConnectMessage.priority()
			  << std::endl;

}

InternalProtocol::DeviceConnectResponse ProtocolMaintainer::createDeviceConnectResponseMessage(
		InternalProtocol::DeviceConnectResponse::ResponseType responseType) {
	InternalProtocol::DeviceConnectResponse deviceConnectResponse;

	deviceConnectResponse.set_responsetype(responseType);
	return deviceConnectResponse;
}

void ProtocolMaintainer::parseDeviceConnectResponseMessage(const InternalProtocol::DeviceConnectResponse& deviceConnectResponse) {
	std::cout << "Got connect response message with type: " << deviceConnectResponse.responsetype() << std::endl;
}

InternalProtocol::DeviceStatus
ProtocolMaintainer::createDeviceStatus(const InternalProtocol::Device& device, std::string statusData) {
	InternalProtocol::DeviceStatus deviceStatus;

	InternalProtocol::Device* tmpDev = deviceStatus.mutable_device();
	tmpDev->CopyFrom(device);

	deviceStatus.set_statusdata(statusData);

	return deviceStatus;
}

InternalProtocol::DeviceCommand ProtocolMaintainer::createDeviceCommand(std::string commandData) {
	InternalProtocol::DeviceCommand deviceCommand;
	deviceCommand.set_commanddata(commandData);
	return deviceCommand;
}

ExternalProtocol::ExternalServer ProtocolMaintainer::createExternalServerCommand(const InternalProtocol::DeviceCommand& deviceCommand, const InternalProtocol::Device& device) {
	ExternalProtocol::ExternalServer externalServerMessage;

	ExternalProtocol::Command* command = externalServerMessage.mutable_command();

	InternalProtocol::DeviceCommand* tmpDeviceCommand = command->mutable_devicecommand();
	tmpDeviceCommand->CopyFrom(deviceCommand);

	InternalProtocol::Device* tmpDevice = command->mutable_device();
	tmpDevice->CopyFrom(device);

	command->set_sessionid(sessionId_);
	command->set_messagecounter(42);

	return externalServerMessage;
}

std::string ProtocolMaintainer::parseCommand(const ExternalProtocol::ExternalServer& externalServerMessage) {
	if(externalServerMessage.has_command()) {
		const auto& command = externalServerMessage.command();
		std::cout << "Command with sessionId " << command.sessionid() << " and message counter " << command.messagecounter()
		<< ", for device module " << command.device().module() << ", devicetype " << command.device().devicetype() << std::endl;

		/*ExampleModule::BlinkerCommand blinkerCommand;
		blinkerCommand.ParseFromString(command.devicecommand().commanddata());
		std::cout << "command = " << blinkerCommand.command();*/
		return command.devicecommand().commanddata();
	} else if (externalServerMessage.has_connectreponse()) {
		// parse as connect response
	} else if (externalServerMessage.has_statusresponse()) {
		// parse as status response
	} else {
		std::cout << "Obtained an empty external server message" << std::endl;
	}
	return "";
}

ExternalProtocol::ExternalClient
ProtocolMaintainer::createExternalClientStatus(const InternalProtocol::DeviceStatus& deviceStatus) {
	ExternalProtocol::ExternalClient externalClientMessage;

	ExternalProtocol::Status* status = externalClientMessage.mutable_status();

	InternalProtocol::DeviceStatus* tmpDeviceStatus = status->mutable_devicestatus();
	tmpDeviceStatus->CopyFrom(deviceStatus);

	status->set_messagecounter(41); // magic number, will be incremented in real application
	status->set_devicestate(ExternalProtocol::Status_DeviceState_RUNNING);
	status->set_sessionid(sessionId_);

	// No error is sent in this example, otherwise status->set_errormessage(errorBytes)

	return externalClientMessage;
}

InternalProtocol::DeviceStatus ProtocolMaintainer::parseStatus(const ExternalProtocol::ExternalClient& externalClientMessage) {
	if(externalClientMessage.has_status()) {
		const auto& status = externalClientMessage.status();

		std::cout << "Status with sessionId " << status.sessionid() << " and message counter " << status.messagecounter()
				  << ", with state " << status.devicestate() << std::endl;

		if(status.has_errormessage()) {
			std::cout << "Status contains error message" << std::endl;
		}
		return status.devicestatus();
	} else if (externalClientMessage.has_connect()) {
		// connect message
	} else if (externalClientMessage.has_commandresponse()) {
		// command response
	} else {
		std::cout << "Obtained an empty external client message" << std::endl;
	}

	return {};
}




