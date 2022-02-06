#include "bytes.h"
#include "frequencies.h"
#include "vigenere.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 40

size_t find_key_length(Bytes ciphertext) {
    double best_score = 0.0;
    size_t best_length = 0;

    for (size_t length = 1; length < ciphertext.size && length < MAX_LENGTH; length += 1) {
        Bytes stream = bytes_slice(ciphertext, 0, ciphertext.size, length);

        // Find the frequency of each byte in the stream.
        double freq[256] = { 0 };
        for (size_t i = 0; i < stream.size; i += 1) {
            freq[stream.bytes[i]] += 1;
        }

        // Normalize and calculate the score.
        double score = 0;
        for (size_t i = 0; i < 256; i += 1) {
            freq[i] /= stream.size;
            score += freq[i] * freq[i];
        }

        if (score > best_score) {
            best_score = score;
            best_length = length;
        }

        bytes_delete(stream);
    }

    return best_length;
}

Bytes find_shift_key(Bytes ciphertext) {
    double best_score = 0.0;
    size_t best_shift = 0;

    for (size_t shift = 0; shift < 256; shift += 1) {
        // The Vigenère cipher's decryption function is the same as the
        // shift cipher's decryption function for a key-length of 1.
        Bytes key = {
            .bytes = (uint8_t *) &shift,
            .size = 1,
        };

        Bytes plaintext = decrypt(ciphertext, key);

        double score = 0.0;
        for (size_t j = 0; j < plaintext.size; j += 1) {
            score += frequencies[j];
        }

        if (score > best_score) {
            best_score = score;
            best_shift = shift;
        }
    }

    Bytes key = bytes_new(1);
    key.bytes[0] = best_shift;
    return key;
}
