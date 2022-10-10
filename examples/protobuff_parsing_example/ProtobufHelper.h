#pragma once

#include <FleetProtocol.pb.h>
#include <modules/AutonomyModule.pb.h>
#include <modules/ActionModule.pb.h>


class ProtobufHelper {
public:
    ///fleet client messages
    static FleetProtocol::FleetClient createConnect(const std::string& sessionId, const std::string& company, const std::string& vehicleName, const std::vector<std::string>& deviceList);
    static FleetProtocol::FleetClient createCommandResponse();

    static FleetProtocol::FleetClient createAutonomyStatus(const std::string& sessionId, float speed, float fuel, float latitude, float longitude, float altitude, AutonomyModule::AutonomyStatus_State state, const std::string& stop);

    static FleetProtocol::FleetClient createSystemLoggerStatus();
    static FleetProtocol::FleetClient createGreenButtonStatus();
    static FleetProtocol::FleetClient createRedButtonStatus();
    static FleetProtocol::FleetClient createWatchdogStatus();

    static FleetProtocol::FleetClient createAutonomyErrorStatus(float speed, float fuel, float latitude, float longitude, float altitude, AutonomyModule::AutonomyStatus_State state, const std::string& stop);

    static FleetProtocol::FleetClient createSystemLoggerErrorStatus();
    static FleetProtocol::FleetClient createGreenButtonErrorStatus();
    static FleetProtocol::FleetClient createRedButtonErrorStatus();
    static FleetProtocol::FleetClient createWatchdogErrorStatus();

    ///fleet server messages
    static FleetProtocol::FleetServer createConnectResponse();
    static FleetProtocol::FleetServer createStatusResponse();

    static FleetProtocol::FleetServer createAutonomyCommand();
    static FleetProtocol::FleetServer createGreenButtonCommand();
    static FleetProtocol::FleetServer createRedButtonCommand();
    static FleetProtocol::FleetServer createSystemLoggerCommand();
    static FleetProtocol::FleetServer createWatchdogCommand(const std::string& sessionId, ActionModule::Device_DeviceType deviceType, const std::string& deviceName, ActionModule::WatchdogCommand_Command watchdogCommand);

    static void printFleetServerMessage(const std::string& serializedMessage);
    static void printFleetClientMessage(const std::string& serializedMessage);

private:
    static void printConnect(const FleetProtocol::Connect& connectMessage);
    static void printStatus(const FleetProtocol::Status& statusMessage);
    static void printCommand(const FleetProtocol::Command& commandMessage);

    static void printAutonomyStatus(const AutonomyModule::AutonomyStatus& status);
    static void printAutonomyError(const AutonomyModule::AutonomyError& error);

    static void printActionCommand(const ActionModule::ActionCommand& actionCommand);
    static void printWatchdogCommand(const ActionModule::WatchdogCommand& watchdogCommand);
};
