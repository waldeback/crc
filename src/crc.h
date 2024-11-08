#ifndef CRC_H
#define CRC_H

#include <stdint.h>

uint32_t crc32(uint32_t crc, const void *data, size_t length);

#endif // CRC_H
