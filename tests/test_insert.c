#include <stdio.h>
#include <stdlib.h>

#include "strutil.h"


int main(void) {
    char *str = "Hello, world!";
    char *extra = "beautiful ";
    char *expanded = strutil_insert(str, extra, 7);

    printf("Original: \"%s\"\n", str);
    printf("Expanded: \"%s\"\n", expanded);

    free(expanded);
    return 0;
}
