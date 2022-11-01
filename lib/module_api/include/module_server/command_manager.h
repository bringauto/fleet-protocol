#ifndef MODULE_API_COMMAND_MANAGER_H
#define MODULE_API_COMMAND_MANAGER_H

/**
 * @short Update command message.
 *
 * When a module server receives a new command message from the _external_ client, module server
 * saves and replaces the old message with the incomming one.
 */
void update_command();

/**
 * @short Get command message.
 *
 * When a device has command to do and finishes its task, he needs to update this command. So he provides
 * a status message with finished state and gets a new updated command.
 *
 * @return Command message if successes, null pointer if an error occurred
 */
void *get_command(void *status_message);

#endif //MODULE_API_COMMAND_MANAGER_H