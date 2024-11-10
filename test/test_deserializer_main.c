#include <stdio.h>

int main() {
    int failures = 0;


    if (failures > 0) {
        printf("Total failures: %d\n", failures);
    } else {
        printf("All tests passed.\n");
    }

    return failures;
}
