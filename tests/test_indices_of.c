#include <stdio.h>
#include <stdlib.h>

#include "strutil.h"


int main(void) {
    size_t amount = 0;
    char l = 'l';
    char *str = "Hello, world!";
    size_t *indices = strutil_indices_of(str, l, &amount);

    printf("Indices of '%c' in \"%s\"\n", l, str);
    for (size_t i = 0; i < amount; i++) {
        if (i < amount-1) {
            printf("%lu, ", indices[i]);
        } else {
            printf("%lu\n", indices[i]);
        }
    }

    free(indices);
    return 0;
}
