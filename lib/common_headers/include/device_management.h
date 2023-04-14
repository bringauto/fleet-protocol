#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @section module_gateway
 * @subsection internal_server_structures
 */

/**
 * @brief Device identification
 */
struct device_identification {
	int module;                     /// module identification number
	int device_type;                /// integer specifying module specific device, device type is defined in specific module header
	const char *const device_role;  /// null terminated role of device
	const char *const device_name;  /// null terminated name of unique device
	int priority;                   /// specify priority of the device, smaller number equals higher priority (0 is highest)
};

/**
 * @short Get number of the module
 *
 * Serves for identification of module implementation.
 * The number corresponds with the module number from InternalProtocol.proto protobuf file.
 *
 * @return module number
 */
int get_module_number();

#ifdef __cplusplus
}
#endif
