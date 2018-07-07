#include <stdio.h>
#include <string.h>

#include "strutil.h"


int main(void) {
    char *str1 = "Hello, world!";
    size_t length = strlen(str1), index = 0;
    char H = 'H', w = 'w', x = 'x';

    index = strutil_index_of(str1, H);
    printf("The index of '%c' in \"%s\" is: ", H, str1);
    if (index < length) {
        printf("%lu\n", index);
    } else {
        printf("Does Not Exist\n");
    }

    index = strutil_index_of(str1, w);
    printf("The index of '%c' in \"%s\" is: ", w, str1);
    if (index < length) {
        printf("%lu\n", index);
    } else {
        printf("Does Not Exist\n");
    }

    index = strutil_index_of(str1, x);
    printf("The index of '%c' in \"%s\" is: ", x, str1);
    if (index == length) {
        printf("%lu\n", index);
    } else {
        printf("Does Not Exist\n");
    }

    return 0;
}
