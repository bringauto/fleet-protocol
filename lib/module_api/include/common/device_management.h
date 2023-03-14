#pragma once

/**
 * @section internal_server
 * @subsection internal_server_structures
 */

/**
 * @brief Device identification
 */
struct device_identification {
	int device_type;                /// integer specifying module specific device, device type is defined in specific module header
	const char* const device_role;  /// null terminated role of device
	const char* const device_name;  /// null terminated name of unique device
};