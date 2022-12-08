#include <iostream>

#include "ProtobufHelper.h"

int main(int argc, char **argv){
    auto connect = ProtobufHelper::createConnect("01ad25e", "BringAuto", "TPCi", {"autonomy", "green_button", "red_button", "watchdog", "system_logger"});
    ProtobufHelper::printExternalClientMessage(connect.SerializeAsString());

    auto autonomyStatus = ProtobufHelper::createAutonomyStatus("01ad25e", 15.6,99.9,69.4875,63.5445, 1584.54, AutonomyModule::AutonomyStatus_State_DRIVE, "Zastavka 1");
    ProtobufHelper::printExternalClientMessage(autonomyStatus.SerializeAsString());

    auto watchdogCommand = ProtobufHelper::createWatchdogCommand("01ad25e", ActionModule::Device_DeviceType_WATCHDOG, "watchdog", ActionModule::WatchdogCommand_Command_RESET);
    ProtobufHelper::printExternalServerMessage(watchdogCommand.SerializeAsString());

}