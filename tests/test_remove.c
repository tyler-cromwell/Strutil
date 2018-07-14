#include <stdio.h>
#include <stdlib.h>

#include "strutil.h"


int main(void) {
    char *str = "Hello, world!";
    char *condensed = strutil_remove(str, 5, 12);

    printf("Original:  \"%s\"\n", str);
    printf("Condensed: \"%s\"\n", condensed);

    free(condensed);
    return 0;
}
