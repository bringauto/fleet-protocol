#pragma once

#include <general_error_codes.h>

enum mg_error_codes {
	RESERVED = RESERVED, // TODO check if this work like this
	DEVICE_NOT_SUPPORTED,
	DEVICE_NOT_REGISTERED,
	COMMAND_INVALID,
	STATUS_INVALID,
	BUFFER_TOO_SMALL,
};