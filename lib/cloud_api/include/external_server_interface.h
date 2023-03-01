#pragma once

#ifdef __cplusplus
extern "C" {
#endif

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
	const char *device_role;
	const char *device_name;
};

/**
 * @brief Generic message data buffer. Contains data pointer and the length of this data.
 * @data array must be allocated and allocated size should be put into @size.
 */
struct buffer {
	void *data;
	unsigned size;
};

/**
 * @brief Get value from configuration file based on passed key
 * TODO link for key_getter and how to pass keys for structures etc.
 * @param key - key-value parameter's key
 * @param external_server_context - context maintained in the External server, needed by callback functions
 *
 * @return key-value's value
 */
typedef void *(*key_getter)(const char *const key, void *external_server_context);

/**
 * @brief Callback function, which pass a serialized command to the External server, which adds necessary information and sends it to the device
 *
 * @param command - serialized command data
 * @param device - device identification structure
 * @param external_server_context - context maintained in the External server, needed by callback functions
 *
 * @return TODO Should it control if device is connected? I think not, but discuss. Otherwise return void, since command is asynchronous and if it was successfully delivered, command_ack is called
 */
typedef int (*command_forwarder)(const struct buffer command, const struct device_identification device, void *external_server_context);

/**
 * @short Create context for specific application.
 *
 * Create context for specific application. All other functions have to be used with an initialized context.
 * It is possible to create multiple contexts.
 * Single context is NOT thread safe. User have to ensure, that a single context instance is not being
 * used by multiple functions simultaneously.
 * Using multiple contexts IS thread safe and you can use multiple contexts simultaneously.
 * TODO externalServerContext je pointer na strukturu v ES, kde si on uklada data k dane,mu modulu (jako jeho cilso) a potrebuje ho predavat callback funkcim
 * @param get_key - callback function, that gets key-value from config
 * @param external_server_context - context maintained in the External server, needed by callback functions
 *
 * @return context of the device used for calling other library functions, NULL if an error occurs
 */
void *init(key_getter get_key, void *external_server_context);

/**
 * @short Clean up.
 *
 * Function will destroy and deallocate given context. Context pointer is set to NULL, so it cannot be used again
 * Using destroyed context will lead to an error (-1).
 * Have to be called before program exit or there will be possibility for a memory leak.
 *
 * @param context context of module client created by init() function, which will be destroyed and set to null
 *
 * @return 0 if successful, -1 if an error occurred
 */
int destroy(void **context);

/**
 * @short Forwards status to given context.
 *
 * @param device_status buffer structure, containing device status
 * @param device device_identification structure, containing role, type and name of the device
 * @param context context of module client created by init() function
 *
 * @return 0 if successful, -1 if context is incorrect, -2 if timeout occurred, -3 other error
 */
int forward_status(const struct buffer device_status, const struct device_identification device, void *context);

/**
 * @brief Forwards error message to given context.
 *
 * @param error_msg buffer structure, containing error message
 * @param device device_identification structure, containing role, type and name of the device
 * @param context context of module client created by init() function
 *
 * @return 0 if successful, -1 if context is incorrect, -2 if timeout occurred, -3 other error
 */
int forward_error_message(const struct buffer error_msg, const struct device_identification device, void *context);

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
 * @param external_server_context - context maintained in the External server, needed by callback functions
 *
 * @return 0 if successful, -1 if context is incorrect, -2 other error
 */
int register_command_callback(command_forwarder forward_command, void *context, void *external_server_context);

/**
 * @brief Acknowledge that command has been successfully delivered to the device
 *
 * @param command successfully delivered command TODO only acknowledge succesfull or also the reason of unsucefull? As a user, I would like to know
 * @return 0 if successful, -1 if context is incorrect, -2 if timeout occurred while sending ack, -3 other error
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
