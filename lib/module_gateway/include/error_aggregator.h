#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <device_management.h>
#include <mg_error_codes.h>
#include <memory_management.h>

/**
 * @section module_gateway
 * @subsection error_aggregator
 */

/**
 * @short Error aggregator init.
 *
 * Initialization of error aggregator, have to be called first before any other library function
 * Not thread safe.
 * Aggregator contains multiple contexts, one for every device registered by add_status function, working with different devices IS thread
 * safe, you can call function on device1 in thread1 and function on device2 in thread2 without any problem this is thread safe, but working with one
 * device in multiple threads is NOT thread safe.
 *
 * @return OK if initialization was successful
 * @return NOT_OK if an error occurred
 */
int init_error_aggregator();

/**
 * @short Clean up.
 *
 * Destroy will deallocate all resources used by error aggregator, if not called before program exit, memory leaks can occur.
 *
 * @return OK if successful
 * @return NOT_OK if an error occurred
 */
int destroy_error_aggregator();

/**
 * @short Add protobuf status message to an error aggregator, aggregator will aggregate each unique devices messages of type device_type separately.
 *
 * When this function is called, protobuf message will add this message to implementation defined error aggregation function.
 * The target of error aggregation function is to create one status and one error message from all unsent messages during connection outage
 * If device is not registered, error code is returned.
 *
 * @param status protobuf status message in binary form
 * @param device identification of the device
 *
 * @return OK if successful
 * @return DEVICE_NOT_REGISTERED if device is not registered
 * @return NOT_OK for other error
 */
int add_status_to_error_aggregator(const struct buffer status, const struct device_identification device);

//todo this function might be not needed
/**
 * @short Get status from error aggregator for a specific device.
 *
 * Create error status using an error aggregation function and return it through given buffer.
 * If device is not registered an error is returned. If no messages for given device are present, no error status message is created and 0 is returned.
 * This function will not clear error status container.
 *
 * @param error_status user allocated message_buffer for the error status. Look at 'memory management' section
 * @param device identification of the device
 *
 * @return OK if successful
 * @return NO_MESSAGE_AVAILABLE if no message was generated
 * @return DEVICE_NOT_REGISTERED if device was not registered
 * @return NOT_OK for other errors
 */
int get_error_status(struct buffer *error_status, const struct device_identification device);

/**
 * @short Get error message from error aggregator for a specific device.
 *
 * Messages in error status container will be used to generate error message for given device,
 * If device is not registered an error is returned. If no messages for given device are present,
 * no error status message is created and 0 is returned;
 * This function will not clear error status container.
 *
 * @param error user allocated message_buffer for created protobuf error status. Look at 'memory management' section.
 * @param device identification of the device
 *
 * @return OK if successful
 * @return NO_MESSAGE_AVAILABLE if no message was generated
 * @return DEVICE_NOT_REGISTERED if device was no registered
 * @return NOT_OK for other errors
 */
int get_error(struct buffer *error, const struct device_identification device);

/**
 * @short Clear error aggregator
 *
 * All messages for all registered devices will be removed.
 *
 * @return OK if successful
 * @return NOT_OK if an error occurs
 */
int clear_error_aggregator();

#ifdef __cplusplus
}
#endif