#include <stdio.h>
#include <stdlib.h>

#include "strutil.h"


int main(void) {
    char *str = "Hello, world!";
    char *reversed = strutil_reverse(str);

    printf("Original: \"%s\"\n", str);
    printf("Reversed: \"%s\"\n", reversed);

    free(reversed);
    return 0;
}
