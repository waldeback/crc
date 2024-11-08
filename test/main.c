#include <stdio.h>
#include <stdint.h>

#include <crc.h>
#include <string.h>

int test_crc32(const char *input, uint32_t expected) {
    uint32_t result = crc32(0, (const unsigned char *)input, strlen(input));
    if (result == expected) {
        printf("Test passed for input: %s\n", input);
        return 0;
    } else {
        printf("Test failed for input: %s. Expected: %08x, Got: %08x\n", input, expected, result);
        return 1;
    }
}

int main() {
    int failures = 0;
    failures += test_crc32("", 0);
    failures += test_crc32("hello world", 0x1c291ca3);
    failures += test_crc32("!@#$\%^&*()", 0x2d3dd0ae);
    failures += test_crc32("1234567890", 0x261daee5);

    if (failures > 0) {
        printf("Total failures: %d\n", failures);
    } else {
        printf("All tests passed.\n");
    }

    return failures;
}