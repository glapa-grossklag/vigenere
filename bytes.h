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
 * Print the BYTES to stdout.
 *
 * EXAMPLE:
 *     [ 72, 101, 108, 108, 111,  44,  32, 119, 111, 114, 108, 100,  33,   0]
 */
void bytes_print(Bytes bytes);

#endif
