#include <stdlib.h>
#include <string.h>

#include "strutil.h"


/*
 * Reverses a given string.
 * Argument(s):
 *   char *string: the string being reversed.
 */
char * strutil_reverse(char *string) {
    char temp = 0;
    size_t length = strlen(string);
    char *reversed = calloc(length + 1, sizeof(char));
    strncpy(reversed, string, length);

    for (size_t i = 0; i < (length / 2); i++) {
        temp = reversed[i];
        reversed[i] = reversed[length-1-i];
        reversed[length-1-i] = temp;
    }

    return reversed;
}
