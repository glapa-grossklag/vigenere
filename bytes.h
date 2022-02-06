#ifndef BYTES_H
#define BYTES_H

#include <stddef.h>
#include <stdint.h>

/**
 * A struct that holds a collection of BYTES and it's SIZE.
 */
typedef struct {
    uint8_t *bytes;
    size_t size;
} Bytes;

/**
 * Allocate memory for a Bytes object of a given SIZE.
 */
Bytes bytes_new(size_t size);

/**
 * Free the memory associate with BYTES.
 */
void bytes_delete(Bytes bytes);

/**
 * Print the BYTES to stdout.
 *
 * EXAMPLE:
 *     [ 72, 101, 108, 108, 111,  44,  32, 119, 111, 114, 108, 100,  33,   0]
 */
void bytes_print(Bytes bytes);

/**
 * Return BYTES from START to STOP, including every INTERVAL byte. This
 * is similar to Python's list indexing syntax. If INTERVAL is 1, every
 * byte will be included.
 *
 * NOTE:
 *     The bytes that are returned are malloc'd, the caller must free.
 */
Bytes bytes_slice(Bytes bytes, size_t start, size_t stop, size_t interval);

#endif
