#include <stdio.h>
#include <string.h>

int main() {
    char array[] = "programming";

    int length = strlen(array);

    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (array[i] == array[j]) {
                printf("Character '%c' is repeated at indices %d and %d\n", array[i], i, j);
            }
        }
    }

    return 0;
}
