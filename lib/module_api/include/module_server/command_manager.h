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
 *
 * @return command message if successes, null pointer if an error occurred
 */
void *get_command(void *status_message);

#endif //MODULE_API_COMMAND_MANAGER_H