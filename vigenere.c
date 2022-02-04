#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "bytes.h"

Bytes encrypt(Bytes plaintext, Bytes key) {
	Bytes ciphertext = {
		.bytes = calloc(plaintext.size, sizeof(uint8_t)),
		.size = plaintext.size,
	};

	for (size_t i = 0, j = 0; i < plaintext.size; i += 1, j = (j + 1) % key.size) {
		ciphertext.bytes[i] = plaintext.bytes[i] ^ key.bytes[j];
	}

	return ciphertext;
}

Bytes decrypt(Bytes ciphertext, Bytes key) {
	Bytes plaintext = {
		.bytes = calloc(ciphertext.size, sizeof(uint8_t)),
		.size = ciphertext.size,
	};

	for (size_t i = 0, j = 0; i < ciphertext.size; i += 1, j = (j + 1) % key.size) {
		plaintext.bytes[i] = ciphertext.bytes[i] ^ key.bytes[j];
	}

	return plaintext;
}
