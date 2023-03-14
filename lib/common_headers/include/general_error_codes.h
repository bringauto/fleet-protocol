#pragma once

/**
 * @short General set of return codes.
 * @section common_headers
 * @subsection general_error_codes
*/

/**
 * @short General error codes shared across the API
 */
enum general_error_codes_enum {
    OK       = 0,   /// Routine execution succeed
    NOT_OK   = -1,  /// Routine execution does not succeed
    RESERVED = -10, /// Codes from -1 to RESERVED are reserved as General purpose errors
};
