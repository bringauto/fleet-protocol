#pragma once

#include <general_error_codes.h>
/**
 * @brief Specific error codes for internal_client
 */
enum ic_error_codes {
	CONTEXT_INCORRECT = RESERVED-1,		/// Incorrect context (nullptr) was passed to a function
	TIMEOUT_OCCURRED = RESERVED-2,		/// Timeout while sending status or receiving command occurred
	NO_COMMAND_AVAILABLE = RESERVED-3,	/// get_command function was called before any command was received
	UNABLE_TO_CONNECT = RESERVED-4,		/// Unable to create connection to the Internal server
	DEVICE_ALREADY_CONNECTED = RESERVED-5,	/// A device with same identification and priority is already connected to the Internal server
	MODULE_NOT_SUPPORTED = RESERVED-6,	/// module set in the Device identification is not supported by Module gateway
	DEVICE_TYPE_NOT_SUPPORTED = RESERVED-7,	/// device_type set in the Device identification is not supported by module
	HIGHER_PRIORITY_ALREADY_CONNECTED = RESERVED-8,	/// A device with the same identification, but higher priority is already connected to the Internal server
	COMMAND_INCORRECT = RESERVED-9,		/// Received command cannot be deserialized or is missing some data
	DEVICE_INCORRECT = RESERVED-10		/// Received command has different target device than current
};