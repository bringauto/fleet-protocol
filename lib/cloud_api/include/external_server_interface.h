#ifndef FLEET_EXTERNAL_SERVER_API_H
#define FLEET_EXTERNAL_SERVER_API_H

#ifdef __cplusplus
extern "C" {
#endif

enum disconnect_types {
	announced = 0,
	timeout = 1,
	error = 2
};

struct device_identification {
	int device_type;
	const char *device_role;
	const char *device_name;
};

struct buffer {
	void *data;
	unsigned size;
};

/**
 * @brief Get value from configuration file based on passed key TODO correct word usage
 */
typedef void *(*key_getter)(const char *const key);

/**
 * @brief Callback function, which serializes command and sends it to a device.
 */
typedef int (*command_forwarder)(const struct buffer command, const struct device_identification device);

/**
 * @short Create context for specific application.
 *
 * Create context for specific application. All other functions have to be used with an initialized context.
 * One context represents one connection to module server.
 * It is possible to create multiple contexts.
 * Single context is NOT thread safe. User have to ensure, that a single context instance is not being
 * used by multiple functions simultaneously.
 * Using multiple contexts IS thread safe and you can use multiple contexts simultaneously.
 *
 * @param get_key - callback function, that gets key-value from config
 *
 * @return context of the device used for calling other library functions, NULL if an error occurs
 */
void *init(key_getter get_key);

/**
 * @short Clean up.
 *
 * Function will destroy and deallocate given context.
 * Using destroyed context will lead to an error (-2).
 * Have to be called before program exit or there will be possibility for a memory leak.
 *
 * @param context context of module client created by init() function, which will be destroyed
 *
 * @return 0 if successful, -1 if an error occurred
 */
int destroy(void **context);

/**
 * @short Forwards status to given context.
 *
 * @param device_status pointer to buffer structure, containing device status
 * @param device pointer to device_identification structure, containing role, type and name of the device
 * @param context context of module client created by init() function
 *
 * @return 0 if successful, -1 if context is incorrect, -2 if timeout occurred, -3 other error
 */
int forward_status(const struct buffer device_status, const struct device_identification device, void *context);

/**
 * @brief Forwards error message to given context.
 *
 * @param error_msg pointer to buffer structure, containing error message
 * @param device pointer to device_identification structure, containing role, type and name of the device
 * @param context context of module client created by init() function
 *
 * @return 0 if successful, -1 if context is incorrect, -2 if timeout occurred, -3 other error
 */
int
forward_error_message(const struct buffer error_msg, const struct device_identification device, void *context);

/**
 * @brief Notify that a device has disconnected
 *
 * @param disconnect_type enumeration of disconnection type
 * @param context context of module client created by init() function
 *
 * @return 0 if successful, -1 if context is incorrect, -2 if timeout occurred, -3 other error
 */
int device_disconnected(const disconnect_types disconnect_type, const struct device_identification device, void *context);

/**
 * @brief Notify that a device has connected
 *
 * @param device device identification structure
 * @param context context of module client created by init() function
 *
 * @return 0 if successful, -1 if context is incorrect, -2 if timeout occurred, -3 other error
 */
int device_connected(const struct device_identification device, void *context);

// command_creator takes command and device and adds session ID and sends
/**
 * @brief Define how the commands will passed to the External server.
 *
 * @param forward_command callback function, that forwards command and device identification to the External server
 * @param context
 *
 * @return 0 if successful, -1 if context is incorrect, -2 other error
 */
int register_command_callback(command_forwarder forward_command, void *context);

/**
 * @brief Acknowledge that command has been successfully delivered to the device
 *
 * @param command successfully delivered command
 * @return 0 if successful, -1 if context is incorrect, -2 if timeout occurred, -3 other error
 */
int command_ack(const struct buffer command, void *context);

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

#endif // FLEET_EXTERNAL_SERVER_API_H
