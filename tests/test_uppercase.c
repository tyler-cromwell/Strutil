#include <stdio.h>
#include <stdlib.h>

#include "strutil.h"


int main(void) {
    char *str = "Hello, WORLD!";
    char *upper = strutil_uppercase(str);
    printf("Original:  \"%s\"\n", str);
    printf("Uppercase: \"%s\"\n", upper);
    free(upper);
    return 0;
}
