#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <device_management.h>
#include <mg_error_codes.h>
#include <memory_management.h>

/**
 * @section module_gateway
 * @subsection status_aggregator
 */

/**
 * @short Status aggregator init.
 *
 * Initialization of status aggregator, have to be called first before any other library function
 * Not thread safe. Aggregator contains multiple contexts, one for every device registered by add_status function, working with different devices IS thread
 * safe, you can call function on device1 in thread1 and function on device2 in thread2 without any problem this is thread safe, but working with one
 * device in multiple threads is NOT thread safe.
 *
 * @return OK if initialization was successful
 *         NOT_OK if an error occurred
 */
int init_status_aggregator();

/**
 * @short Clean up.
 *
 * Destroy will deallocate all resources used by status aggregator, if not called before program exit, memory leaks can occur.
 * Not thread safe.
 *
 * @return OK if successful,
 * @return NOT_OK if an error occurred
 */
int destroy_status_aggregator(); ///module specific

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
 * @return OK if clearing was successful
 * @return NOT_OK if error occurs
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
 * @param device identification of the device
 *
 * @return OK if clearing was successful,
 * @return DEVICE_NOT_REGISTERED if device does not exists
 * @return NOT_OK for other errors
 */
int clear_device(const struct device_identification device);

/**
 * @short Remove device from aggregator
 * 
 * What will be removed:
 * - whole device entry in status aggregator along with command and all messages,
 * After this operation, device will not be registered in aggregator and trying to get data for this device will result in error.
 * 
 * @param device identification of the device
 * 
 * @return OK if removing was successful
 * @return DEVICE_NOT_REGISTERED if device does not exist
 * @return NOT_OK for other errors
*/
int remove_device(const struct device_identification device);

/**
 * @short Add protobuf status message to aggregator, aggregator will aggregate each unique devices messages of type device_type separately
 *
 * Aggregation is a implementation defined function for removing duplicity in messages.
 * When this function is called, device specified by device_name and device_type will be registered if it is not already registered.
 * Registered device is keeping track of messages it has already received and not yet aggregated and already aggregated messages not yet taken out using get_aggregated_status() function
 *
 * If device of device_type is not supported, error code is returned.
 * Message given in protobuf status will be added to aggregator, and aggregation condition will be checked. Aggregation condition is change of states of device.
 * Aggregation conditions are defined for each device type separately. Aggregation condition marks a change in state that the end user have to be informed about.
 *
 * If aggregation condition is not met, status is declared as duplicate and will be aggregated.
 *
 * @param status protobuf status message buffer
 * @param device identification of the device
 *
 * @return number of aggregated messages waiting in container for given device to be obtained by get_aggregated_status() function,
 * @return DEVICE_NOT_SUPPORTED if device type is not supported,
 * @return NOT_OK for other error
 */
int add_status_to_aggregator(const struct buffer status, const struct device_identification device);

/**
 * @short Get the oldest aggregated protobuf status message that is aggregated
 *
 * Function will take an oldest message from given device from container with aggregated messages and put it in protobuf_status.
 * If device is not registered, or no aggregated message for given device is present and error is returned.
 *
 * If return code is equal to -3 then the allocated buffer size is not huge enought to hold a message
 *
 * @param generated_status status message buffer, have to be already allocated by user. Look at 'memory_management' section
 * @param device identification of the device
 *
 * @return OK if successful
 * @return NO_MESSAGE_AVAILABLE if no status message for device is ready
 * @return DEVICE_NOT_REGISTERED if device is not registered
 * @return NOT_OK for other error
 */
int get_aggregated_status(struct buffer *generated_status, const struct device_identification device);

/**
 * @short Get all devices registered to aggregator
 *
 * Devices are registered by add_status_to_aggregator() message when called with first message for given device.
 * This function will return information about all unique devices that were registered during the lifetime of status aggregator.
 *
 * @param unique_devices_buffer pointer to buffer to retrieve unique devices. Number of bytes in buffer.size_in_bytes
 *                              is equal to number_of_devices * sizeof(struct device_identifier). Look at 'memory_management' section
 *
 * @return NOT_OK if error occurred
 * @return Number of unique devices - number of 'device_identifier' structs stored at buffer.data.
 *
 * @code
 *      struct buffer unique_devices;
 *      int number_of_devices = get_unique_devices(&unique_devices);
 *      assert(buffer.size_in_bytes == number_of_devices * sizeof(struct device_identifier));
 * @endcode
 */
int get_unique_devices(struct buffer* unique_devices_buffer);

/**
 * @short Force status message aggregation on given device.
 *
 * Force aggregation on a device - even if aggregation condition was not met. This function should be
 * used for periodic message generation as it triggers the creation of status message every time it is called and will create duplicity in status messages.
 * Function will aggregate all messages in non-aggregated container, empty the container and add created message into
 * aggregated container.
 *
 * @param device identification of the device
 *
 * @return number of messages in aggregated container for given device, that can be obtained by calling get_aggregated_status() function
 * @return DEVICE_NOT_REGISTERED if device is not registered
 * @return NOT_OK if an error occurred
 */
int force_aggregation_on_device(const struct device_identification device);

/**
 * @short Check if device is supported and registered
 *
 * @param device
 *
 * @return OK if the device is valid
 * @return NOT_OK if the device is not valid
 */
int is_device_valid(const struct device_identification device);

#ifdef __cplusplus
}
#endif