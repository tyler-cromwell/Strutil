#include <stdio.h>

#include "strutil.h"


int main(void) {
    char *str1 = "Hello, world!";
    char *str2 = "world";
    char *str3 = "WORLD";

    printf("\"%s\" contains \"%s\": ", str1, str2);
    switch (strutil_contains(str1, str2)) {
        case 1: puts("true");   break;
        case 0: puts("false");  break;
    }

    printf("\"%s\" contains \"%s\": ", str1, str3);
    switch (strutil_contains(str1, str3)) {
        case 1: puts("true");   break;
        case 0: puts("false");  break;
    }

    return 0;
}
