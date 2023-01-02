#ifndef MODULE_API_COMMAND_MANAGER_H
#define MODULE_API_COMMAND_MANAGER_H

/**
 * @short Update command message.
 *
 * Replaces the actual command message with the provided one.
 *
 * @param command_message new command message
 */
void update_command(void *command_message);

/**
 * @short Get command message.
 *
 * After providing a status message, the actual command message is updated and returned.
 *
 * @param status_message new protobuf status message in binary form
 * @param status_size size of the status message
 * @param device_name null terminated name of unique device
 * @param device_type integer specifying module specific device, device type is defined in specific module header
 * @param buffer pointer to an user allocated buffer, command message structure will be copied to it, structures are defined in device specific header file
 * @param buffer_size size of user allocated buffer
 *
 * @return size of command, -1 if status_message is incorrect, -2 if buffer is too small, -3 for other error
 */
int get_command(void *status_message, int status_size, char *device_name, int device_type, void *buffer, unsigned buffer_size);

#endif //MODULE_API_COMMAND_MANAGER_H