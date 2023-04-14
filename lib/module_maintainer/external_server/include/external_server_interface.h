#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <device_management.h>
#include <general_error_codes.h>
#include <memory_management.h>

#include <external_server_structures.h>

/**
 * @file external_server_interface.h
 * @brief Interface implemented by module maintainers
 *
 * @section Module maintainer
 */

/**
 * @subsection External server interface
 */

/**
 * @short Create context for specific application.
 *
 * Create context for specific application. All other functions have to be used with an initialized context.
 * Arguments for context initialization are passed in config structure.
 * Arguments are defined in External servers in an ini configuration file. Description: TODO link
 * It is possible to create multiple contexts.
 * Single context is NOT thread safe. User have to ensure, that a single context instance is not being
 * used by multiple functions simultaneously.
 * Using multiple contexts IS thread safe and you can use multiple contexts simultaneously.
 *
 * @param config_data - parameters from a configuration file
 *
 * @return context of the device used for calling other library functions
 * @return NOT_OK if an error occurs
 */
void *init(const struct config config_data);

/**
 * @short Clean up.
 *
 * Function will destroy and deallocate given context. Context pointer is set to NULL, so it cannot be used again
 * Using destroyed context will lead to an error (-1).
 * Have to be called before program exit or there will be possibility for a memory leak.
 *
 * @param context context created by init() function, which will be destroyed and set to null
 *
 * @return OK if successful
 * @return NOT_OK if an error occurred
 */
int destroy(void **context);

/**
 * @short Forwards status to given context.
 *
 * @param device_status buffer structure, containing device status
 * @param device device_identification structure, containing role, type and name of the device
 * @param context context created by init() function
 *
 * @return OK if successful
 * @return CONTEXT_INCORRECT if context is incorrect
 * @return TIMEOUT_OCCURRED if timeout occurred
 * @return NOT_OK other error
 */
int forward_status(const struct buffer device_status, const struct device_identification device, void *context);

/**
 * @brief Forwards error message to given context.
 *
 * @param error_msg buffer structure, containing error message
 * @param device device_identification structure, containing role, type and name of the device
 * @param context context created by init() function
 *
 * @return OK if successful
 * @return CONTEXT_INCORRECT if context is incorrect
 * @return TIMEOUT_OCCURRED if timeout occurred
 * @return NOT_OK other error
 */
int forward_error_message(const struct buffer error_msg, const struct device_identification device, void *context);

/**
 * @brief Notify that a device has disconnected
 *
 * @param disconnect_type enumeration of disconnection type
 * @param context context created by init() function
 *
 * @return OK if successful
 * @return CONTEXT_INCORRECT if context is incorrect
 * @return TIMEOUT_OCCURRED if timeout occurred
 * @return NOT_OK other error
 */
int device_disconnected(const disconnect_types disconnect_type, const struct device_identification device, void *context);

/**
 * @brief Notify that a device has connected
 *
 * @param device device identification structure
 * @param context context created by init() function
 *
 * @return OK if successful
 * @return CONTEXT_INCORRECT if context is incorrect
 * @return TIMEOUT_OCCURRED if timeout occurred
 * @return NOT_OK other error
 */
int device_connected(const struct device_identification device, void *context);

/**
 * @brief Blocking function waiting for an event.
 * This event signalize, that there is a command, that can be obtained with get_command() function.
 * If the event didn't happened, the function MUST timeout in time given by parameter timeout_time_in_ms
 *
 * @param timeout_time_in_ms - maximum blocking time until timeout
 * @param context context created by init() function
 *
 * @return OK if a command is obtainable
 * @return TIMEOUT_OCCURRED if command is not available, therefore timeout occurred
 * @return CONTEXT_INCORRECT if context is incorrect
 */
int wait_for_command(int timeout_time_in_ms, void *context);

/**
 * @brief Obtain a single command from API
 * Function is called for each command that is available in API
 *
 * @param command - buffer pointer, where the command will be put
 * @param device - identification of the target device of the command
 * @param context context created by init() function
 *
 * @return number of remaining commands
 * @return CONTEXT_INCORRECT if the context is incorrect
 * @return NOT_OK an error occurred
 */
int get_command(buffer* command, device_identification* device, void *context);

/**
 * @brief Acknowledge that command has been successfully delivered to the device
 *
 * @param command successfully delivered command
 * @param device which device got the command
 * @param context context created by init() function
 *
 * @return OK if successful
 * @return CONTEXT_INCORRECT if context is incorrect
 * @return TIMEOUT_OCCURRED if timeout occurred while sending ack
 * @return NOT_OK other error
 */
int command_ack(const struct buffer command, const struct device_identification device, void *context);


#ifdef __cplusplus
}
#endif

