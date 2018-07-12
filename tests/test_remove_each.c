#include <stdio.h>
#include <stdlib.h>

#include "strutil.h"


int main(void) {
    char *str = "HeFOOllo, FOOWorld!FOO";
    char *seq = "FOO";
    char *new = strutil_remove_each(str, seq);

    printf("Original:  \"%s\"\n", str);
    printf("Processed: \"%s\"\n", new);

    free(new);
    return 0;
}
