#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <device_management.h>
#include <general_error_codes.h>
#include <memory_management.h>

/**
 * @section internal_client
 */

/**
 * @brief Specific error codes for internal_client
 */
enum ic_error_codes {
    CONTEXT_INCORRECT = RESERVED-1,
    TIMEOUT_OCCURRED = RESERVED-2,
    BUFFER_TOO_SMALL = RESERVED-3
};

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
 * @param ipv4_address null terminated IPv4 address of module server
 * @param port port of module server
 * @param device identification of the device
 *
 * @return context of the device used for calling other library functions
 * @return NULL if an error occurs
 */
void *init_connection(const char* const ipv4_address, unsigned port, const struct device_identification device);

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
 * @short Function sends given status data to module server using given context and receives command.
 *
 * Communication between module client and module server is request-response based, in this case the request is a status message
 * and the response is in form of command which have to be received to successfully complete send_status. Since the communication is request-response based
 * sending request cannot be successful without receiving the response, so send_status does not only send the request (in form of status)
 * but also waits for the response (in form of command).
 * Function is blocking, it will wait until command is received or timeout specified by an argument is reached before returning.
 * After successful send_status call, command can be retrieved by receive_command function.
 *
 * @param context context of module client created by init() function
 * @param device_status pointer to device specific structure, specific device is set in init() function using device_type, structures are defined in device specific header file
 * @param status_size size of status data
 * @param timeout timeout in seconds, how long is acceptable to wait for server response (command) if timeout is reached, error will be returned
 *
 * @return OK if successful
 * @return CONTEXT_INCORRECT if context is incorrect
 * @return TIMEOUT_OCCURRED if timeout occurred
 * @return NOT_OK other error
 */
int send_status(void *context, const struct buffer status, unsigned timeout);

/**
 * @short Get command.
 *
 * Get most recent command from given context, command is received during every send_status() call, commands are being overwritten - the most current command is returned.
 * Function uses context created by init() function otherwise error is returned. Command is returned only if at least one send_status() was called with given context,
 * otherwise 0 is returned.
 *
 * @param context context of module client created by init() function
 * @param device_command_buffer pointer to an user allocated buffer, device command structure will be copied to it, structures are defined in device specific header file
 * @param buffer_size size of user allocated buffer
 *
 * @return size of device_command in bytes
 * @return OK if no message was yet received (send_status was not called yet)
 * @return CONTEXT_INCORRECT if context is incorrect
 * @return BUFFER_TOO_SMALL if buffer is too small
 * @return NOT_OK for other error
 */
int get_command(void *context, struct buffer* command);

#ifdef __cplusplus
}
#endif