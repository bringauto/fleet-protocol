#include "ProtobufHelper.h"

ExternalProtocol::ExternalClient
ProtobufHelper::createConnect(const std::string& sessionId, const std::string &company, const std::string &vehicleName,
                              const std::vector<std::string> &deviceList) {

    ExternalProtocol::ExternalClient connectMessage;
    auto allocatedConnect = new ExternalProtocol::Connect();

    allocatedConnect->set_sessionid(sessionId);
    allocatedConnect->set_company(company);
    allocatedConnect->set_vehiclename(vehicleName);

    for(const auto& device: deviceList){
        allocatedConnect->add_devicenames(device);
    }

    connectMessage.set_allocated_connect(allocatedConnect);

    return connectMessage;
}

void ProtobufHelper::printExternalClientMessage(const std::string& serializedMessage) {
    ExternalProtocol::ExternalClient message;

    message.ParseFromString(serializedMessage);

    switch(message.MessageType_case()){
        case ExternalProtocol::ExternalClient::kConnect:
            printConnect(message.connect());
            break;
        case ExternalProtocol::ExternalClient::kStatus:
            printStatus(message.status());
            break;
        case ExternalProtocol::ExternalClient::kCommandResponse:
            std::cout << "[ERROR] Command response print not implemented";
            break;
        case ExternalProtocol::ExternalClient::MESSAGETYPE_NOT_SET:
            std::cout << "[ERROR] Unknown message type";
            break;
    }
}

void ProtobufHelper::printConnect(const ExternalProtocol::Connect &connectMessage) {
    std::cout << "[INFO] Received connect message:" << std::endl;
    std::cout << "Session id: " << connectMessage.sessionid() << std::endl;
    std::cout << "Company: " << connectMessage.company() << std::endl;
    std::cout << "Vehicle name: " << connectMessage.vehiclename() << std::endl;

    std::string devices;
    for(const auto& device: connectMessage.devicenames()){
        devices += device + " ";
    }
    std::cout << "Connected devices: " << devices << std::endl;
}

ExternalProtocol::ExternalClient
ProtobufHelper::createAutonomyStatus(const std::string& sessionId, float speed, float fuel, float latitude, float longitude, float altitude,
                                     AutonomyModule::AutonomyStatus_State state, const std::string& stopTo) {

    auto stop = new AutonomyModule::Stop();
    stop->set_to(stopTo);

    ///create position
    auto position = new AutonomyModule::AutonomyStatus_Position();
    position->set_altitude(altitude);
    position->set_latitude(latitude);
    position->set_longitude(longitude);

    ///create telemetry
    auto telemetry = new AutonomyModule::AutonomyStatus_Telemetry();
    telemetry->set_speed(speed);
    telemetry->set_fuel(fuel);
    telemetry->set_allocated_position(position);

    ///create module status message
    auto autonomyStatus = new AutonomyModule::AutonomyStatus();
    autonomyStatus->set_state(state);
    autonomyStatus->set_allocated_telemetry(telemetry);
    autonomyStatus->set_allocated_stop(stop);

    ///create module error message
    auto autonomyError = new AutonomyModule::AutonomyError();
    autonomyError->set_type(AutonomyModule::AutonomyError_Type_OK);

    ///create fleet status
    auto status = new ExternalProtocol::Status();
    status->set_sessionid(sessionId);
    status->set_allocated_autonomystatus(autonomyStatus);
    status->set_allocated_autonomyerror(autonomyError);

    ExternalProtocol::ExternalClient fleetMessage;
    fleetMessage.set_allocated_status(status);

    return fleetMessage;
}

void ProtobufHelper::printStatus(const ExternalProtocol::Status &statusMessage) {
    std::cout << "[INFO] Received status message" << std::endl;
    std::cout << "Session id: " << statusMessage.sessionid() << std::endl;

    switch(statusMessage.StatusType_case()){
        case ExternalProtocol::Status::kAutonomyStatus:
            std::cout << "Module: Autonomy module" << std::endl;
            printAutonomyStatus(statusMessage.autonomystatus());
            printAutonomyError(statusMessage.autonomyerror());
            break;
        case ExternalProtocol::Status::kActionStatus:
            std::cout << "Module: Action module" << std::endl;
            std::cout << "Error: Action module print is not supported" << std::endl;
            break;
        case ExternalProtocol::Status::STATUSTYPE_NOT_SET:
            break;
    }
}

void ProtobufHelper::printAutonomyStatus(const AutonomyModule::AutonomyStatus &status) {
    std::cout << "Speed: " << status.telemetry().speed() << std::endl;
    std::cout << "Fuel: " << status.telemetry().fuel() << std::endl;
    std::cout << "Latitude: " << status.telemetry().position().latitude() << std::endl;
    std::cout << "Longitude: " << status.telemetry().position().longitude() << std::endl;
    std::cout << "Altitude: " << status.telemetry().position().altitude() << std::endl;
    std::cout << "State: " << status.state() << std::endl;
    std::cout << "Stop: " << status.stop().to() << std::endl;
}

void ProtobufHelper::printAutonomyError(const AutonomyModule::AutonomyError &error) {
    switch(error.type()){

        case AutonomyModule::AutonomyError_Type_OK:
            std::cout << "Error type: OK"<< std::endl;
            break;
        case AutonomyModule::AutonomyError_Type_SERVER_ERROR:
            std::cout << "Error type: Server error"<< std::endl;
            break;
        case AutonomyModule::AutonomyError_Type_AutonomyError_Type_INT_MIN_SENTINEL_DO_NOT_USE_:
            break;
        case AutonomyModule::AutonomyError_Type_AutonomyError_Type_INT_MAX_SENTINEL_DO_NOT_USE_:
            break;
    }
    if(error.type() == AutonomyModule::AutonomyError_Type_SERVER_ERROR){
        std::string stops;
        for(auto const& stop: error.stops()){
            stops += stop.to() + " ";
        }
        std::cout << "Error stops: " << stops << std::endl;
    }

}

void ProtobufHelper::printExternalServerMessage(const std::string &serializedMessage) {
    ExternalProtocol::ExternalServer message;

    message.ParseFromString(serializedMessage);

    switch(message.MessageType_case()){

        case ExternalProtocol::ExternalServer::kConnectReponse:
            std::cout << "[ERROR] Connect response print not implemented";
            break;
        case ExternalProtocol::ExternalServer::kStatusResponse:
            std::cout << "[ERROR] Status response print not implemented";
            break;
        case ExternalProtocol::ExternalServer::kCommand:
            printCommand(message.command());
            break;
        case ExternalProtocol::ExternalServer::MESSAGETYPE_NOT_SET:
            std::cout << "[ERROR] Unknown message type";
            break;
    }


}

ExternalProtocol::ExternalServer ProtobufHelper::createWatchdogCommand(const std::string& sessionId, ActionModule::Device_DeviceType deviceType, const std::string& deviceName, ActionModule::WatchdogCommand_Command watchdogCommandEnum) {

    auto watchdogCommand = new ActionModule::WatchdogCommand();
    watchdogCommand->set_command(watchdogCommandEnum);

    auto device = new ActionModule::Device();
    device->set_devicename(deviceName);
    device->set_devicetype(deviceType);

    auto actionCommand = new ActionModule::ActionCommand();
    actionCommand->set_allocated_device(device);
    actionCommand->set_allocated_watchdogcommand(watchdogCommand);

    auto command = new ExternalProtocol::Command();
    command->set_sessionid(sessionId);
    command->set_allocated_actioncommand(actionCommand);

    ExternalProtocol::ExternalServer fleetServer;
    fleetServer.set_allocated_command(command);

    return fleetServer;
}

void ProtobufHelper::printCommand(const ExternalProtocol::Command &commandMessage) {
    std::cout << "[INFO] Received Command message" << std::endl;
    std::cout << "Session id: " << commandMessage.sessionid() << std::endl;

    switch(commandMessage.CommandType_case()){
        case ExternalProtocol::Command::kAutonomyCommand:
            std::cout << "Module: Autonomy module" << std::endl;
            std::cout << "Error autonomy command print not implemented" << std::endl;
            break;
        case ExternalProtocol::Command::kActionCommand:
            std::cout << "Module: Action module" << std::endl;
            printActionCommand(commandMessage.actioncommand());
            break;
        case ExternalProtocol::Command::COMMANDTYPE_NOT_SET:
            break;
    }
}

void ProtobufHelper::printActionCommand(const ActionModule::ActionCommand &actionCommand) {
    std::cout << "Device name: " << actionCommand.device().devicename() << std::endl;

    switch (actionCommand.DeviceCommandType_case()) {

        case ActionModule::ActionCommand::kGreenButtonCommand:
            std::cout << "Device type: green button" << std::endl;
            std::cout << "Error green button command print not implemented" << std::endl;
            break;
        case ActionModule::ActionCommand::kRedButtonCommand:
            std::cout << "Device type: red button" << std::endl;
            std::cout << "Error red button command print not implemented" << std::endl;
            break;
        case ActionModule::ActionCommand::kWatchdogCommand:
            std::cout << "Device type: watchdog" << std::endl;
            printWatchdogCommand(actionCommand.watchdogcommand());
            break;
        case ActionModule::ActionCommand::kSystemLoggerCommand:
            std::cout << "Device type: system logger" << std::endl;
            std::cout << "Error system logger command print not implemented" << std::endl;
            break;
        case ActionModule::ActionCommand::DEVICECOMMANDTYPE_NOT_SET:
            std::cout << "Error unknown device type" << std::endl;
            break;
    }
}

void ProtobufHelper::printWatchdogCommand(const ActionModule::WatchdogCommand &watchdogCommand) {
    std::cout << "Watchdog command: " << watchdogCommand.command() << std::endl;
}
