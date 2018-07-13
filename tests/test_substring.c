#include <stdio.h>
#include <stdlib.h>

#include "strutil.h"


int main(void) {
    size_t start = 7;
    size_t end = 12;
    char *str = "Hello, world!";
    char *substr = strutil_substring(str, start, end);

    printf("Original:  \"%s\"\n", str);
    printf("Substring: \"%s\" (from index %lu to %lu)\n", substr, start, end);

    free(substr);
    return 0;
}
