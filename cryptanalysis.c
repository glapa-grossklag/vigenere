#include <stdio.h>
#include <stdlib.h>

#include "bytes.h"

#define MAX_LENGTH 40

size_t find_key_length(Bytes ciphertext) {
    double best_score = 0.0;
    size_t best_length = 0;

    for (size_t length = 1; length < ciphertext.size && length < MAX_LENGTH;
         length += 1) {
        Bytes stream = slice(ciphertext, 0, ciphertext.size, length);

        // Find the frequency of each byte in the stream.
        double freq[256] = {0};
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

        free(stream.bytes);
    }

    return best_length;
}
