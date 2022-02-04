#ifndef VIGENERE_H
#define VIGENERE_H

#include "bytes.h"

/**
 * Encrypt the PLAINTEXT with the KEY. Return the CIPHERTEXT.
 *
 * NOTE:
 *     The bytes of the CIPHERTEXT are malloc'd, the caller must free.
 */
Bytes encrypt(Bytes plaintext, Bytes key);

/**
 * Decrypt the CIPHERTEXT with the KEY. Return the PLAINTEXT.
 *
 * NOTE:
 *     The bytes of the PLAINTEXT are malloc'd, the caller must free.
 */
Bytes decrypt(Bytes ciphertext, Bytes key);

#endif
