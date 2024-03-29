#pragma once

#include <fleet_protocol/common_headers/general_error_codes.h>

enum mg_error_codes {
	DEVICE_NOT_SUPPORTED = RESERVED -1,
	DEVICE_NOT_REGISTERED = RESERVED -2,
	COMMAND_INVALID = RESERVED -3,
	STATUS_INVALID = RESERVED -4,
	BUFFER_TOO_SMALL = RESERVED -5,
	NO_MESSAGE_AVAILABLE = RESERVED -6
};