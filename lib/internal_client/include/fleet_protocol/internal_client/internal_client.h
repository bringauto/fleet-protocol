#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <fleet_protocol/common_headers/device_management.h>
#include <fleet_protocol/common_headers/general_error_codes.h>
#include <fleet_protocol/common_headers/memory_management.h>
#include <fleet_protocol/internal_client/error_codes.h>

/**
 * @section internal_client
 */

/**
 * @short Create context for specific device.
 *
 * Create context for specific device. All other functions have to be used with a initialized context.
 * One context represents one connection to module server.
 * It is possible to create multiple contexts.
 * Single context is NOT thread safe. User have to ensure, that a single context instance is not being
 * used by multiple functions simultaneously.
 * Using multiple contexts IS thread safe and you can use multiple contexts simultaneously.
 *
 * @param context pointer for returning context of the device used for calling other library functions
 * @param ipv4_address null terminated IPv4 address of module server
 * @param port port of module server
 * @param device identification of the device
 *
 * @return OK if context was created and the device connected
 * @return UNABLE_TO_CONNECT if ip connection couldn't be established
 * @return DEVICE_ALREADY_CONNECTED if device with same identification is already connected
 * @return HIGHER_PRIORITY_ALREADY_CONNECTED if device with same identification but higher priority is already connected
 * @return MODULE_NOT_SUPPORTED if module is not supported
 * @return DEVICE_TYPE_NOT_SUPPORTED if the device type is not supported by the module
 * @return DEVICE_INCORRECT if obtained connect response with different device than was connected
 * @return NOT_OK if different error occurred
 */
int init_connection(void **context, const char* const ipv4_address, unsigned port, const struct device_identification device);

/**
 * @short Clean up.
 *
 * Function will destroy and deallocate given context.
 * Using destroyed context will lead to an error (-2).
 * Have to be called before program exit or there will be possibility for a memory leak.
 *
 * @param context context of module client created by init() function
 *
 * @return OK if successful,
 * @return NOT_OK if an error occurred
 */
int destroy_connection(void **context);

/**
 * @short Function sends given status data to internal server using given context and receives command.
 *
 * Communication between internal client and internal server is request-response based, in this case the request is a status message
 * and the response is in form of command which have to be received to successfully complete send_status. Since the communication is request-response based
 * sending request cannot be successful without receiving the response, so send_status does not only send the request (in form of status)
 * but also waits for the response (in form of command).
 *
 * Function is blocking, it will wait until command is received or timeout specified by an argument is reached before returning.
 * The timeout is set for sending status and receiving command, therefore maximum duration of this function is 2x timeout
 * After successful send_status call, command can be retrieved by get_command function.
 *
 * If the server has disconnected the client, this function will attempt once to reconnect
 *
 * @param context context of module client created by init_connection() function
 * @param device_status device specific status data, specific device is set in init_connection() function using device_type, status data structure is defined in a device specific file
 * @param timeout timeout in seconds, how long is acceptable to wait for status send or server response (command), if timeout is reached, error will be returned
 *
 * @return OK if successful
 * @return CONTEXT_INCORRECT if context is incorrect
 * @return TIMEOUT_OCCURRED if timeout occurred
 * @return COMMAND_INCORRECT obtained incorrect command
 * @return DEVICE_INCORRECT obtained command for different device
 * @return UNABLE_TO_CONNECT if reconnect was not successful
 * @return NOT_OK other error
 */
int send_status(void *context, const struct buffer status, unsigned timeout);

/**
 * @short Get command.
 *
 * Get most recent command from given context, command is received during every send_status() call, commands are being overwritten - the most current command is returned.
 * Function uses context created by init() function otherwise error is returned. Command is returned only if at least one send_status() was called with given context,
 * otherwise NO_COMMAND_AVAILABLE is returned.
 *
 * The "command" buffer structure must be initialized.
 * If command->size_in_bytes == 0, the data pointer will be allocated for the required size.
 * If the size of new command > command->size_in_bytes, the data pointer will be REALLOCATED.
 * User has to free the data pointer, after it is no longer needed.
 *
 * @param context context of module client created by init() function
 * @param command pointer to an initialized buffer. Device command data will be copied to the buffer. Structure of the command data is defined in device specific header file
 * @param buffer_size size of user allocated buffer
 *
 * @return OK If command was successfully saved into buffer
 * @return CONTEXT_INCORRECT if context is incorrect
 * @return NO_COMMAND_AVAILABLE if command is not available (successful send_status was not called yet)
 * @return NOT_OK for other error
 */
int get_command(void *context, struct buffer* command);

#ifdef __cplusplus
}
#endif
