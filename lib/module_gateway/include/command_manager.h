#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <device_management.h>
#include <mg_error_codes.h>
#include <memory_management.h>

/**
 * @section module_gateway
 * @subsection command_manager
 */

/**
 * @short Update command message.
 *
 * Replaces the actual command data with the provided one.
 *
 * @param command new command data in binary form
 * @param device identification of device
 *
 * @return OK if command was successfully updated
 * @return DEVICE_NOT_SUPPORTED if device_type is not supported by concrete module
 * @return DEVICE_NOT_REGISTERED if device is not registered
 * @return COMMAND_INVALID if command data are invalid
 */
int update_command(const struct buffer command, const struct device_identification device);

/**
 * @short Get command message.
 *
 * After providing a status message, the actual command message is updated and returned.
 *
 * @param status new protobuf status message in binary form. Look at memory_management section
 * @param device specification of device
 * @param command user allocated message_buffer structure, command message structure will be copied to it,
 *        structures are defined in device specific header file. Look at memory_management section
 *
 * @return size of command in bytes
 * @return STATUS_INVALID if status_message is incorrect
 * @return BUFFER_TOO_SMALL if buffer is too small
 * @return DEVICE_NOT_SUPPORTED if device_type is not supported by concrete module
 * @return NOT_OK for other error
 */
int get_command(const struct buffer status, const struct device_identification device, struct buffer* command);

#ifdef __cplusplus
}
#endif