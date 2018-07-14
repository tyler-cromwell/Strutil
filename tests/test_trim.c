#include <stdio.h>
#include <stdlib.h>

#include "strutil.h"


int main(void) {
    char *str = "  Hello, World!    ";
    char *trimmed = strutil_trim(str);

    printf("Original:  \"%s\"\n", str);
    printf("Trimmed:   \"%s\"\n", trimmed);

    free(trimmed);
    return 0;
}
