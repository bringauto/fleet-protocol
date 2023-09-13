#pragma once

#include <modules/ExampleModule.pb.h>
#include <InternalProtocol.pb.h>
#include <ExternalProtocol.pb.h>

/**
 * @brief Contains methods (parsing examples) that are done in one of BringAuto libraries
 */
class ProtocolMaintainer {
public:
	// Connect
	/**
	 * @brief Create Device Message
	 * @param device_role
	 * @param device_type
	 * @param device_name
	 * @return device
	 */
	static InternalProtocol::Device
	createDevice(std::string device_role, uint32_t device_type, std::string device_name);

	/**
	 * @brief Create DeviceConnect message
	 * @param device
	 * @param priority
	 * @return DeviceConnect
	 */
	static InternalProtocol::DeviceConnect
	createDeviceConnectMessage(const InternalProtocol::Device& device, uint32_t priority);

	/**
	 * @brief Creates ExternalClient message containing Connect message
	 * @param company
	 * @param vehicleName
	 * @param devices
	 * @return ExternalClient containing Connect message
	 */
	static ExternalProtocol::ExternalClient createConnectMessage(std::string company, std::string vehicleName, const std::vector<InternalProtocol::Device>& devices);

	/**
	 * @brief Parse and print DeviceConnect message
	 * @param deviceConnectMessage
	 */
	static void parseDeviceConnectMessage(const InternalProtocol::DeviceConnect& deviceConnectMessage);

	/**
	 * @brief Create DeviceConnectResponse message
	 * @param responseType
	 * @return DeviceConnectResponse
	 */
	static InternalProtocol::DeviceConnectResponse createDeviceConnectResponseMessage(
			InternalProtocol::DeviceConnectResponse::ResponseType responseType);

	static void parseDeviceConnectResponseMessage(const InternalProtocol::DeviceConnectResponse& deviceConnectResponse);

	// Status
	/**
	 * @brief Create DeviceStatus from Device and binary data (implemented as string)
	 * @param device
	 * @param statusData
	 * @return DeviceStatus
	 */
	static InternalProtocol::DeviceStatus createDeviceStatus(const InternalProtocol::Device& device, std::string statusData);

	/**
	 * @brief Create ExternalClient message containing Status
	 * @param deviceStatus
	 * @return
	 */
	static ExternalProtocol::ExternalClient createExternalClientStatus(const InternalProtocol::DeviceStatus& deviceStatus);
	/**
	 * @brief Parse and print information from status from external communication, but not the actual status data
	 * @param externalClientMessage
	 * @return DeviceStatus containing device identification and data
	 */
	static InternalProtocol::DeviceStatus parseExternalClientMessage(const ExternalProtocol::ExternalClient& externalClientMessage);

	// Command

	/**
	 * @brief Creates Device command (only puts serialized data to the field)
	 * @param commandData command serialized as string
	 * @return
	 */
	static InternalProtocol::DeviceCommand createDeviceCommand(std::string commandData);

	/**
	 * @brief Creates ExternalServer message, containing Command
	 * @param deviceCommand
	 * @param device
	 * @return ExternalServer message, containing Command
	 */
	static ExternalProtocol::ExternalServer createExternalServerCommand(InternalProtocol::DeviceCommand deviceCommand, const InternalProtocol::Device& device);

	/**
	 * @brief Parse ExternalServer message
	 * @param externalServerMessage
	 * @return commandData (bytes) if command was received
	 */
	static std::string parseExternalServerMessage(const ExternalProtocol::ExternalServer& externalServerMessage);

private:
	/// Module enum. It is constant for every device / module
	static constexpr InternalProtocol::Device_Module module_ = InternalProtocol::Device_Module_EXAMPLE_MODULE;
	/// session ID should be randomly generated and prepended with robot ID
	inline static const std::string sessionId_ = {"8p2HPtE9"};
};
