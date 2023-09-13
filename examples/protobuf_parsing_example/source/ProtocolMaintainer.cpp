#include <ProtocolMaintainer.hpp>


InternalProtocol::Device
ProtocolMaintainer::createDevice(std::string device_role, uint32_t device_type, std::string device_name) {
	InternalProtocol::Device deviceMessage;

	deviceMessage.set_module(module_);
	deviceMessage.set_devicerole(device_role);
	deviceMessage.set_devicename(device_name);
	deviceMessage.set_devicetype(device_type);
	deviceMessage.set_priority(0);

	return deviceMessage;
}

InternalProtocol::DeviceConnect
ProtocolMaintainer::createDeviceConnectMessage(const InternalProtocol::Device &device, uint32_t priority) {
	InternalProtocol::DeviceConnect deviceConnectMessage;

	InternalProtocol::Device *devicePtr = deviceConnectMessage.mutable_device(); // Returns pointer to device field in deviceConnectMessage
	devicePtr->CopyFrom(device);

	return deviceConnectMessage;
}

ExternalProtocol::ExternalClient ProtocolMaintainer::createConnectMessage(std::string company, std::string vehicleName,
																		  const std::vector<InternalProtocol::Device> &devices) {
	ExternalProtocol::ExternalClient externalClientMessage;

	ExternalProtocol::Connect *connectMessage = externalClientMessage.mutable_connect();

	connectMessage->set_sessionid(sessionId_);
	connectMessage->set_company(company);
	connectMessage->set_vehiclename(vehicleName);

	for(const auto &tmpDevice: devices) {
		auto devicePtr = connectMessage->add_devices();
		devicePtr->CopyFrom(tmpDevice);
	}

	return externalClientMessage;
}

void ProtocolMaintainer::parseDeviceConnectMessage(const InternalProtocol::DeviceConnect &deviceConnectMessage) {
	const InternalProtocol::Device &deviceMessage = deviceConnectMessage.device();

	if(deviceMessage.module()) {

		std::cout << "Got connect message containing: module " << deviceMessage.module() <<
				  ", deviceRole " << deviceMessage.devicerole() << ", deviceName " << deviceMessage.devicename() <<
				  ", deviceType " << deviceMessage.devicetype() << ", priority " << deviceMessage.priority()
				  << std::endl;
	}

}

InternalProtocol::DeviceConnectResponse ProtocolMaintainer::createDeviceConnectResponseMessage(
		InternalProtocol::DeviceConnectResponse::ResponseType responseType) {
	InternalProtocol::DeviceConnectResponse deviceConnectResponse;

	deviceConnectResponse.set_responsetype(responseType);
	return deviceConnectResponse;
}

void ProtocolMaintainer::parseDeviceConnectResponseMessage(
		const InternalProtocol::DeviceConnectResponse &deviceConnectResponse) {
	std::cout << "Got connect response message with type: " << deviceConnectResponse.responsetype() << std::endl;
}

InternalProtocol::DeviceStatus
ProtocolMaintainer::createDeviceStatus(const InternalProtocol::Device &device, std::string statusData) {
	InternalProtocol::DeviceStatus deviceStatus;

	InternalProtocol::Device *tmpDev = deviceStatus.mutable_device();
	tmpDev->CopyFrom(device);

	deviceStatus.set_statusdata(statusData);

	return deviceStatus;
}


ExternalProtocol::ExternalClient
ProtocolMaintainer::createExternalClientStatus(const InternalProtocol::DeviceStatus &deviceStatus) {
	ExternalProtocol::ExternalClient externalClientMessage;

	ExternalProtocol::Status *status = externalClientMessage.mutable_status();

	InternalProtocol::DeviceStatus *tmpDeviceStatus = status->mutable_devicestatus();
	tmpDeviceStatus->CopyFrom(deviceStatus);

	status->set_messagecounter(41); // magic number, will be incremented in real application
	status->set_devicestate(ExternalProtocol::Status_DeviceState_RUNNING);
	status->set_sessionid(sessionId_);

	// No error is sent in this example, otherwise status->set_errormessage(errorBytes)

	return externalClientMessage;
}

InternalProtocol::DeviceStatus
ProtocolMaintainer::parseExternalClientMessage(const ExternalProtocol::ExternalClient &externalClientMessage) {
	if(externalClientMessage.has_status()) {
		const auto &status = externalClientMessage.status();

		std::cout << "Status with sessionId " << status.sessionid() << " and message counter "
				  << status.messagecounter()
				  << ", with state " << status.devicestate() << std::endl;

		if(status.has_errormessage()) {
			std::cout << "Status contains error message" << std::endl;
		}
		return status.devicestatus();
	} else if(externalClientMessage.has_connect()) {
		const auto& connect = externalClientMessage.connect();
		std::cout << "Connect message from " << connect.company() << "/" << connect.vehiclename() << " containing devices: ";
		for(const auto& device : connect.devices()) { // Have to go through whole repeated field
			std::cout << device.devicerole() << ", "; // Printing only roles
		}
		std::cout << std::endl;
	} else if(externalClientMessage.has_commandresponse()) {
		std::cout << "Received command response" << std::endl;
	} else {
		std::cout << "Received an empty external client message" << std::endl;
	}

	return {};
}

InternalProtocol::DeviceCommand ProtocolMaintainer::createDeviceCommand(std::string commandData) {
	InternalProtocol::DeviceCommand deviceCommand;
	deviceCommand.set_commanddata(commandData);
	return deviceCommand;
}

ExternalProtocol::ExternalServer
ProtocolMaintainer::createExternalServerCommand(InternalProtocol::DeviceCommand deviceCommand,
												const InternalProtocol::Device &device) {
	ExternalProtocol::ExternalServer externalServerMessage;

	ExternalProtocol::Command *command = externalServerMessage.mutable_command();

	InternalProtocol::DeviceCommand *tmpDeviceCommand = command->mutable_devicecommand();
	tmpDeviceCommand->CopyFrom(deviceCommand);

	InternalProtocol::Device *tmpDevice = deviceCommand.mutable_device();
	tmpDevice->CopyFrom(device);

	command->set_sessionid(sessionId_);
	command->set_messagecounter(42);

	return externalServerMessage;
}

std::string ProtocolMaintainer::parseExternalServerMessage(const ExternalProtocol::ExternalServer &externalServerMessage) {
	if(externalServerMessage.has_command()) {
		const auto &command = externalServerMessage.command();
		std::cout << "Command with sessionId " << command.sessionid() << " and message counter "
				  << command.messagecounter()
				  << ", for device module " << command.devicecommand().device().module() << ", devicetype "
				  << command.devicecommand().device().devicetype() << std::endl;

		return command.devicecommand().commanddata();
	} else if(externalServerMessage.has_connectresponse()) {
		std::cout << "Received connect response" << std::endl;
	} else if(externalServerMessage.has_statusresponse()) {
		std::cout << "Received status response" << std::endl;
	} else {
		std::cout << "Received an empty external server message" << std::endl;
	}
	return "";
}





