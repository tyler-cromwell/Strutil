#include <stdio.h>
#include <stdlib.h>

#include "strutil.h"


int main(void) {
    size_t amount = 0;
    char *str = "Hello, world!";
    char **tokens = strutil_split(str, ", ", &amount);

    printf("Spliting \"%s\"\n", str);

    for (size_t i = 0; i < amount; i++) {
        printf("[%lu]: \"%s\"\n", i, tokens[i]);
        free(tokens[i]);
    }

    free(tokens);
    return 0;
}
