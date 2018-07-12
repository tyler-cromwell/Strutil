#include <stdio.h>
#include <stdlib.h>

#include "strutil.h"


int main(void) {
    char *str = "Hello, WORLD!";
    char *lower = strutil_lowercase(str);
    printf("Original:  \"%s\"\n", str);
    printf("Lowercase: \"%s\"\n", lower);
    free(lower);
    return 0;
}
