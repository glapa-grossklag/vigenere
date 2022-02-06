#include "bytes.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

Bytes bytes_new(size_t size) {
    return (Bytes) {
        .bytes = calloc(size, sizeof(uint8_t)),
        .size = size,
    };
}

void bytes_delete(Bytes bytes) {
    free(bytes.bytes);
}

void bytes_print(Bytes bytes) {
    printf("[");
    if (bytes.size != 0) {
        printf("%3" PRIu8, bytes.bytes[0]);
    }

    for (size_t i = 1; i < bytes.size; i += 1) {
        printf(", %3" PRIu8, bytes.bytes[i]);
    }
    printf("]\n");
}

Bytes bytes_slice(Bytes bytes, size_t start, size_t stop, size_t interval) {
	Bytes result = bytes_new((stop - start) / interval);

    for (size_t i = 0; i < result.size; i += 1) {
        result.bytes[i] = bytes.bytes[(i + start) * interval];
    }

    return result;
}
