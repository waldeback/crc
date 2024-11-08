#include <stdio.h>
#include <crc.h>


int main() {
    const char *test_string = "Hello, World!";
    uint32_t crc = crc32(0, test_string, 13);
    printf("CRC32: %08x\n", crc);

    print_table();
    return 0;
}   