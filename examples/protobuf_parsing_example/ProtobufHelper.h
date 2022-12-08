#pragma once

#include <ExternalProtocol.pb.h>
#include <modules/MissionModule.pb.h>
#include <modules/CarAccessoryModule.pb.h>


class ProtobufHelper {
public:
    ///fleet client messages
    static ExternalProtocol::ExternalClient createConnect(const std::string& sessionId, const std::string& company, const std::string& vehicleName, const std::vector<std::string>& deviceList);
    static ExternalProtocol::ExternalClient createCommandResponse();

	static ExternalProtocol::ExternalClient createMissionStatus();
    static ExternalProtocol::ExternalClient createAutonomyStatus(const std::string& sessionId, float speed, float fuel, float latitude, float longitude, float altitude, AutonomyModule::AutonomyStatus_State state, const std::string& stop);

    static ExternalProtocol::ExternalClient createSystemLoggerStatus();
    static ExternalProtocol::ExternalClient createGreenButtonStatus();
    static ExternalProtocol::ExternalClient createRedButtonStatus();
    static ExternalProtocol::ExternalClient createWatchdogStatus();

    static ExternalProtocol::ExternalClient createAutonomyErrorStatus(float speed, float fuel, float latitude, float longitude, float altitude, AutonomyModule::AutonomyStatus_State state, const std::string& stop);

    static ExternalProtocol::ExternalClient createSystemLoggerErrorStatus();
    static ExternalProtocol::ExternalClient createGreenButtonErrorStatus();
    static ExternalProtocol::ExternalClient createRedButtonErrorStatus();
    static ExternalProtocol::ExternalClient createWatchdogErrorStatus();

    ///fleet server messages
    static ExternalProtocol::ExternalServer createConnectResponse();
    static ExternalProtocol::ExternalServer createStatusResponse();

    static ExternalProtocol::ExternalServer createAutonomyCommand();
    static ExternalProtocol::ExternalServer createGreenButtonCommand();
    static ExternalProtocol::ExternalServer createRedButtonCommand();
    static ExternalProtocol::ExternalServer createSystemLoggerCommand();
    static ExternalProtocol::ExternalServer createWatchdogCommand(const std::string& sessionId, ActionModule::Device_DeviceType deviceType, const std::string& deviceName, ActionModule::WatchdogCommand_Command watchdogCommand);

    static void printExternalServerMessage(const std::string& serializedMessage);
    static void printExternalClientMessage(const std::string& serializedMessage);

private:
    static void printConnect(const ExternalProtocol::Connect& connectMessage);
    static void printStatus(const ExternalProtocol::Status& statusMessage);
    static void printCommand(const ExternalProtocol::Command& commandMessage);

    static void printAutonomyStatus(const AutonomyModule::AutonomyStatus& status);
    static void printAutonomyError(const AutonomyModule::AutonomyError& error);

    static void printActionCommand(const ActionModule::ActionCommand& actionCommand);
    static void printWatchdogCommand(const ActionModule::WatchdogCommand& watchdogCommand);
};
