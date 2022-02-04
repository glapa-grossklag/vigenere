#include "bytes.h"

#include <stdio.h>
#include <inttypes.h>

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
