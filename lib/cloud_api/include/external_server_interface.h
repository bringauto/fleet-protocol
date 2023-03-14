#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define NAME_LENGTH 64

enum disconnect_types {
	announced = 0,
	timeout = 1,
	error = 2
};

/**
 * @brief Unique device identification.
 * The Device message contains also module number, which is not needed, as every API is implemented for concrete module
 * and the module number is processed earlier in the External Server.
 */
struct device_identification {
	int device_type;
	char device_role[NAME_LENGTH];
	char device_name[NAME_LENGTH];
};

/**
 * @brief Generic message data buffer. Contains data pointer and the length of this data.
 * @data array must be allocated and allocated size should be put into @size.
 */
struct buffer {
	void *data;
	size_t size;
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
 * @return context of the device used for calling other library functions, NULL if an error occurs
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
 * @return 0 if successful, -1 if an error occurred
 */
int destroy(void **context);

/**
 * @short Forwards status to given context.
 *
 * @param device_status buffer structure, containing device status
 * @param device device_identification structure, containing role, type and name of the device
 * @param context context created by init() function
 *
 * @return 0 if successful, -1 if context is incorrect, -2 if timeout occurred, -3 other error
 */
int forward_status(const struct buffer device_status, const struct device_identification device, void *context);

/**
 * @brief Forwards error message to given context.
 *
 * @param error_msg buffer structure, containing error message
 * @param device device_identification structure, containing role, type and name of the device
 * @param context context created by init() function
 *
 * @return 0 if successful, -1 if context is incorrect, -2 if timeout occurred, -3 other error
 */
int forward_error_message(const struct buffer error_msg, const struct device_identification device, void *context);

/**
 * @brief Notify that a device has disconnected
 *
 * @param disconnect_type enumeration of disconnection type
 * @param context context created by init() function
 *
 * @return 0 if successful, -1 if context is incorrect, -2 if timeout occurred, -3 other error
 */
int device_disconnected(const disconnect_types disconnect_type, const struct device_identification device, void *context);

/**
 * @brief Notify that a device has connected
 *
 * @param device device identification structure
 * @param context context created by init() function
 *
 * @return 0 if successful, -1 if context is incorrect, -2 if timeout occurred, -3 other error
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
 * @return 0 if a command is obtainable, -1 otherwise, -2 if context is incorrect
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
 * @return number of remaining commands, -1 if the context is incorrect, -2 an error occurred
 */
int get_command(buffer* command, device_identification* device, void *context);

/**
 * @brief Acknowledge that command has been successfully delivered to the device
 *
 * @param command successfully delivered command
 * @param device which device got the command
 * @param context context created by init() function
 *
 * @return 0 if successful, -1 if context is incorrect, -2 if timeout occurred while sending ack, -3 other error
 */
int command_ack(const struct buffer command, const struct device_identification device, void *context);

/**
 * @short Get number of the module application
 *
 * Serves for controlling that each module has exactly one implementation.
 * The number must copy the module number from protobuf.
 *
 * @return module number
 */
int get_module_number();

#ifdef __cplusplus
}
#endif

