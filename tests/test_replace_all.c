#include <stdio.h>
#include <stdlib.h>

#include "strutil.h"


int main(void) {
    char *str = "Hezzo, Worzd!";
    char *new = strutil_replace_all(str, 'z', 'l');

    printf("Original:  \"%s\"\n", str);
    printf("Processed: \"%s\"\n", new);

    free(new);
    return 0;
}
