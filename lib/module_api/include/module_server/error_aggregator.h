
#ifndef MODULE_API_ERROR_AGGREGATOR_H
#define MODULE_API_ERROR_AGGREGATOR_H

/**
 * @short Error aggregator init.
 *
 * Initialization of error aggregator, have to be called first before any other library function
 * Not thread safe.
 * Aggregator contains multiple contexts, one for every device registered by add_status function, working with different devices IS thread
 * safe, you can call function on device1 in thread1 and function on device2 in thread2 without any problem this is thread safe, but working with one
 * device in multiple threads is NOT thread safe.
 *
 * @return 0 if initialization was successful, -1 if an error occurred
 */
int init();

/**
 * @short Clean up.
 *
 * Destroy will deallocate all resources used by error aggregator, if not called before program exit, memory leaks can occur.
 *
 * @return 0 if successful, -1 if an error occurred
 */
int destroy();

/**
 * @short Add protobuf status message to an error aggregator, aggregator will aggregate each unique devices messages of type device_type separately.
 *
 * When this function is called, protobuf message will add this message to implementation defined error aggregation function.
 * The target of error aggregation function is to create one status and one error message from all unsent messages during connection outage
 * If device is not registered, error code is returned.
 *
 * @param status protobuf status message in binary form
 * @param status_size size of the status message
 * @param device_name null terminated name of unique device
 * @param device_type integer specifying module specific device, device type is defined in specific module header
 *
 * @return 0 if successful, -1 if device is not registered, -2 for other error
 */
int add_status_to_error_aggregator(void* protobuf_status, int status_size, char *device_name, int device_type);

/**
 * @short Get status from error aggregator for a specific device.
 *
 * Create error status using an error aggregation function and return it through given buffer.
 * If device is not registered an error is returned. If no messages for given device are present, no error status message is created and 0 is returned.
 * This function will not clear error status container.
 *
 * @param protobuf_error_status_buffer buffer for created protobuf error status (allocated by user)
 * @param buffer_size maximum buffer size
 * @param device_name name of specific device
 * @param device_type type of the device
 *
 * @return size of message, 0 if no message was generated, -1 if device was no registered, -2 for other errors
 */
int get_error_status(void *protobuf_error_status_buffer, int buffer_size , char *device_name, int device_type);
/**
 * @short Get error message from error aggregator for a specific device.
 *
 * Messages in error status container will be used to generate error message for given device,
 * If device is not registered an error is returned. If no messages for given device are present, no error status message is created and 0 is returned;
 * This function will not clear error status container.
 *
 * @param protobuf_error buffer for created protobuf error status
 * @param buffer_size maximum buffer size
 * @param device_name name of specific device
 * @param device_type type of the device
 *
 * @return size of message, 0 if no message was generated, -1 if device was no registered, -2 for other errors
 */
int get_error(void *protobuf_error, int buffer_size , char *device_name, int device_type);

/**
 * @short Clear error aggregator
 *
 * All messages for all registered devices will be removed.
 *
 * @return 0 if successful, -1 if an error occurs
 */
int clear_error_aggregator();

#endif //MODULE_API_ERROR_AGGREGATOR_H
