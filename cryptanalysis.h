#ifndef CRYPTANALYSIS_H
#define CRYPTANALYSIS_H

#include <stddef.h>

#include "bytes.h"

/**
 * Find the most likely key length of the CIPHERTEXT.
 */
size_t find_key_length(Bytes ciphertext);

#endif
