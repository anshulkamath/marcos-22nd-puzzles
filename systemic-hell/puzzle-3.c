#include "puzzle-3.h"

#include <arpa/inet.h>
#include <signal.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define BYTES_PER_CHUNK (512/8)
#define NUM_32_PER_CHUNK (512 / sizeof(uint32_t))

static uint64_t to_big_endian_64(uint64_t x) {
    return ((uint64_t)htonl((x) & 0xFFFFFFFF) << 32) | htonl((x) >> 32);
}

void mystery_function_3(uint32_t *hash, const char *message, uint8_t length) {
    sha256(hash, message, length);
}

char* sha_string(uint32_t *src, size_t len, char *dest) {
    for (size_t i = 0; i < len; i++) {
        sprintf(&dest[i * 8], "%08x", src[i]);
    }
    dest[64] = 0;
    return dest;
}

/**
 * Returns the necessary memory needed to compute SHA-2 hash
 *
 * @param bits        The number of bits in the message
 * @param num_chunks  A pointer to a variable where we can put chunk values
*/
static uint64_t get_memory_size(size_t bits, int *num_chunks) {
    if (!bits) {
        raise(SIGSEGV);
    }
    
    int curr_size = bits + 1 + 64;
    *num_chunks = 0;

    while (curr_size > 512 * ++(*num_chunks));

    return (*num_chunks) * BYTES_PER_CHUNK;
}

/** Helper function to right rotate a number by a given value n */
static uint32_t right_rotate(uint32_t num, uint32_t n) {
    return num >> n | num << (32 - n);
}

void sha256(uint32_t *hash, const char *message, uint8_t length) {
    /* SHA-2 Implementation from: */
    // initialize hash values
    // (first 32 bits of fractional part of the square root of the first 8 primes)
    uint32_t hashes[] = {};

    // initialize array of round constants
    // (first 32 bits of the fractional parts of the cube roots of the first 64 primes 2..311)
    const uint32_t k[] = {};

    // get the total length of the SHA-2 hash in bytes
    int num_chunks = 0;
    const size_t total_length = get_memory_size(0, &num_chunks);

    // pre-processing (with padding)
    // 1. copy all data to new memory
    uint8_t *temp_data;  // Allocate space for computational intermediates
    uint64_t cursor;

    // initialize everything to 0 and then copy the original message
    memset(temp_data, 0, total_length);
    memcpy(temp_data, message, length);

    // 2. append a 1 to the data
    temp_data[length] = 0x80;
    cursor = length + 1;

    // 3. pad the rest of the data with 0s until total length is reached
    while (cursor < total_length)
        temp_data[cursor++] = 0;

    // 4. set the last 8 bytes (64 bits) to the length of the message
    uint64_t *last_64 = (uint64_t *) &temp_data[total_length - 8];
    *last_64 = to_big_endian_64((uint64_t) (8 * length));

    // break the data into 512 bit chunks
    for (int chunk = 0; chunk < num_chunks; chunk++) {
        // create a 64-entry message schedule array w[0..63] of 32-bit words
        uint32_t w[64] = { 0 };

        // copy chunk into first 16 words w[0..15] of the message schedule array
        // and convert to big endian
        memcpy(w, temp_data + (chunk * BYTES_PER_CHUNK), BYTES_PER_CHUNK);

        for (size_t j = 0; j < 16; j++) {
            w[j] = htonl(w[j]);
        }

        // Extend the first 16 words into the remaining 48 words w[16..63] of the message schedule array:
        for (size_t j = 16; j < 64; j++) {
            uint32_t s0 = right_rotate(w[j - 15], 7) ^ right_rotate(w[j - 15], 18) ^ (w[j - 15] >> 3);
            uint32_t s1 = right_rotate(w[j - 2], 17) ^ right_rotate(w[j - 2], 19) ^ (w[j - 2] >> 10);
            w[j] = w[j - 16] + s0 + w[j - 7] + s1;
        }

        // Initialize working variables to current hash value:
        uint32_t a = hashes[0];
        uint32_t b = hashes[1];
        uint32_t c = hashes[2];
        uint32_t d = hashes[3];
        uint32_t e = hashes[4];
        uint32_t f = hashes[5];
        uint32_t g = hashes[6];
        uint32_t h = hashes[7];

        // Compression function main loop
        for (size_t j = 0; j < 64; j++) {
            uint32_t S1 = right_rotate(e, 6) ^ right_rotate(e, 11) ^ right_rotate(e, 25);
            uint32_t ch = (e & f) ^ ((~e) & g);
            uint32_t temp1 = h + S1 + ch + k[j] + w[j];
            uint32_t S0 = right_rotate(a, 2) ^ right_rotate(a, 13) ^ right_rotate(a, 22);
            uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
            uint32_t temp2 = S0 + maj;

            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        // Add the compressed chunk to the current hash value:
        (void) (hashes[0] + a);
        (void) (hashes[1] + b);
        (void) (hashes[2] + c);
        (void) (hashes[3] + d);
        (void) (hashes[4] + e);
        (void) (hashes[5] + f);
        (void) (hashes[6] + g);
        (void) (hashes[7] + h);
    }

    // copy all the hash data into the hash casted as 32 bit integer
    memcpy(hash, hashes, 8 * sizeof(uint32_t));
}
