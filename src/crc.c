#include <stdio.h>
#include <stdint.h>

    static uint32_t table[256];
    static int have_table = 0;

uint32_t crc32(uint32_t crc, const void *data, size_t size) {

    uint32_t rem;
    uint8_t octet;
    const uint8_t *p, *q;
    int i, j;
    
    if (have_table == 0) {
        for (i = 0; i < 256; i++) {
            rem = i;
            for (j = 0; j < 8; j++) {
                if (rem & 1) {
                    rem >>= 1;
                    rem ^= 0xEDB88320;
                } else
                    rem >>= 1;
            }
            table[i] = rem;
        }
        have_table = 1;
    }

    crc = ~crc;
    q = (const uint8_t *)data + size;
    for (p = (const uint8_t *)data; p < q; p++) {
        octet = *p;
        crc = (crc >> 8) ^ table[(crc & 0xff) ^ octet];
    }
    return ~crc;
}
