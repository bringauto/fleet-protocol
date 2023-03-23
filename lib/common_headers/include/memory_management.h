#pragma once

#include <stddef.h>

/**
 * @brief Memory management related functions and structs
 * @section common_headers
 * @subsection memory_management
 *
 * @details Data return
 * If the function needs to return data represented by a struct the 'buffer' struct
 * needs to be used.
 * The callee allocates a memory block that must be accessible after the callee returns.
 * The memory block must be deletable/free by 'deallocate' function.
 *
 * The data must be copy to the memory block and the start address must be stored
 * to the buffer.data and the number of bytes of data must be stored to the buffer.size_in_bytes.
 *
 * The 'buffer' instance shall be passed as a pointer to the instance from callee called context.
 *
 * @details function output parameters
 * If the 'buffer' is passed as a pointer to the function it's recognized as OUTPUT parameter. (for the function point of view)
 * The called function must handle 'buffer' as described in 'Data return'.
 *
 * After the function return the buffer.data can by freed by '
 *
 * @details function input parameters
 * If the 'buffer' is passed by a copy to the function it's recognized as INPUT parameter. (for the function point of view)
 * The validity of 'buffer' instance passed as INPUT parameter is ensured by the parent context
 * (the context from which the function is called).
 *
 * After the function return the buffer.data can be freed. Look at 'Memory de-allocation'.
 *
 * @details Memory de-allocation
 * Each function that consumes 'buffer' instance as OUTPUT parameter is responsible for allocation of buffer.data.
 *
 * Once the buffer.data is not needed the 'deallocate' function can be called to deallocate buffer.data pointer.
*/

/**
 * @brief Data buffer structure
 * Structure used for packing fleet protocol messages
 */
struct buffer {
    void *data;             /// data buffer
    size_t size_in_bytes;	/// number of bytes of the data stored under memory pointed by .data
};

/**
 * @brief Deallocate allocated memory by the API function referenced in module API.
 *
 * @param buffer_data_pointer is a pointer that needs to be deallocated and was previously allocated
 * by an API function from module API.
*/
void deallocate(void* buffer_data_pointer);