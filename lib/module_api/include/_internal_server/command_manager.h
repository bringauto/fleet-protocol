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
 * @param status_message new status message
 * @param buffer pointer to an user allocated buffer, command message structure will be copied to it, structures are defined in device specific header file
 * @param buffer_size size of user allocated buffer
 *
 * @return size of command, -1 if status_message is incorrect, -2 if buffer is too small, -3 for other error
 */
int get_command(void *status_message, void *buffer, unsigned buffer_size);

#endif //MODULE_API_COMMAND_MANAGER_H