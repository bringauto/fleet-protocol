#pragma once

#include "../common/memory_management.h"
#include "../common/memory_management.h"

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
 */
void update_command(const struct buffer command, const struct device_identification device);

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
 * @return -1 if status_message is incorrect
 * @return -2 if buffer is too small
 * @return -3 for other error
 */
int get_command(const struct buffer status, const struct device_identification device, struct buffer* command);