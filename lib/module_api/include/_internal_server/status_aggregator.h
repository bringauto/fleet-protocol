#ifndef MODULE_API_AGGREGATION_H
#define MODULE_API_AGGREGATION_H

//todo enum for error codes?

/**
 * @short Status aggregator init.
 *
 * Initialization of status aggregator, have to be called first before any other library function
 * Not thread safe. Aggregator contains multiple contexts, one for every device registered by add_status function, working with different devices IS thread
 * safe, you can call function on device1 in thread1 and function on device2 in thread2 without any problem this is thread safe, but working with one
 * device in multiple threads is NOT thread safe.
 *
 * @return 0 if initialization was successful, -1 if an error occurred
 */
int init();

/**
 * @short Clean up.
 *
 * Destroy will deallocate all resources used by status aggregator, if not called before program exit, memory leaks can occur.
 * Not thread safe.
 *
 * @return 0 if successful, -1 if an error occurred
 */
int destroy(); ///module specific

/**
 * @short Clear states and messages for all devices.
 *
 * Every device, registered by an add_status_to_aggregator() function will be cleared.
 * What will be cleared:
 * - all messages received from client server not yet aggregated will be deleted for every device,
 * - all aggregated messages not yet obtained from aggregator by get_aggregated_status(),
 * All devices will be reset to same state as they were just registered.
 * Not thread safe.
 *
 * @return 0 if clearing was successful, -1 if error occurs
 */
int clear_all_devices();

/**
 * @short Clear state and messages for given device
 *
 * What will be cleared:
 * - all messages received from module client by given device and not yet aggregated,
 * - all aggregated messages ready to be obtained using get_aggregated_status() for given device,
 * Device will be reset to same state as it was just registered.
 *
 * @param device_name name of device to be cleared
 *
 * @return 0 if clearing was successful, -1 if device does not exists, -2 for other errors
 */
int clear_device(const char *device_name);

/**
 * @short Add protobuf status message to aggregator, aggregator will aggregate each unique devices messages of type device_type separately
 *
 * Aggregation is a implementation defined function for removing duplicity in messages.
 * When this function is called, device specified by device_name and device_type will be registered if it is not already registered.
 * Registered device is keeping track of messages it has already received and not yet aggregated and already aggregated messages not yet taken out using get_aggregated_status() function
 * If device of device_type is not supported, error code is returned.
 * Message given in protobuf status will be added to aggregator, and aggregation condition will be checked. Aggregation condition is change of states of device.
 * Aggregation conditions are defined for each device type separately. Aggregation condition marks a change in state that the end user have to be informed about.
 * If aggregation condition is not met, status is declared as duplicate and will be aggregated.
 *
 * @param status protobuf status message in binary form
 * @param status_size size of the status message
 * @param device_name null terminated name of unique device
 * @param device_type integer specifying module specific device, device type is defined in specific module header
 *
 * @return number of aggregated messages waiting in container for given device to be obtained by get_aggregated_status() function, -1 if device is not supported, -2 for other error
 */
int add_status_to_aggregator(void* protobuf_status, int status_size, const char *device_name, int device_type);

/**
 * @short Get the oldest aggregated protobuf status message that is aggregated
 *
 * Function will take an oldest message from given device from container with aggregated messages and put it in protobuf_status.
 * If device is not registered, or no aggregated message for given device is present and error is returned.
 *
 * @param status buffer for status message, have to be already allocated by user
 * @param buffer_size size of user allocated status buffer
 * @param device_name name of device
 * @param device_type type of device
 *
 * @return size of message returned or -1 if no message for given device is ready -2 if device is not registered, -3 for other error
 */
int get_aggregated_status(void *protobuf_status_buffer, int buffer_size, char *device_name, int device_type);

/**
 * @short Get all devices registered to aggregator
 *
 * Devices are registered by add_status_to_aggregator() message when called with first message for given device.
 * This function will return information about all unique devices that were registered during the lifetime of status aggregator.
 *
 * @return number size of data written to the unique_devices_buffer
 */
int get_unique_devices(void* unique_devices_buffer, int buffer_size);

/**
 * @short Force status message aggregation on given device.
 *
 * Force aggregation on a device - even if aggregation condition was not met. This function should be
 * used for periodic message generation as it triggers the creation of status message every time it is called and will create duplicity in status messages.
 * Function will aggregate all messages in non-aggregated container, empty the container and add created message into
 * aggregated container.
 *
 * @param device_name name of device for aggregation
 * @param device_type type of device
 *
 * @return number of messages in aggregated container for given device, that can be obtained by calling get_aggregated_status() function
 */
int force_aggregation_on_device(char *device_name, int device_type);

#endif //MODULE_API_AGGREGATION_H
