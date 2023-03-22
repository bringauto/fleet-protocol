#pragma once

#include <memory_management.h>
#include <general_error_codes.h>

/**
 * @brief Specific error codes for external server interface
 */
enum es_error_codes {
	CONTEXT_INCORRECT = RESERVED-1,
	TIMEOUT_OCCURRED = RESERVED-2,
};

/**
 * @brief Types of device disconnection
 */
enum disconnect_types {
	announced = 0,
	timeout = 1,
	error = 2
};

/**
 * @brief Parameter structure containing the parameters key and its value in buffers
 */
struct key_value {
	buffer key;
	buffer value;
};

/**
 * @brief Configuration structure, containing key-value parameters and the number of them
 */
struct config {
	key_value* parameters;
	size_t size;
};