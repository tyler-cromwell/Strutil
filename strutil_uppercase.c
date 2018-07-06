#include <stdlib.h>
#include <string.h>

#include "strutil.h"


/**
 * Sets alphabetic characters to uppercase.
 * Argument(s):
 *   char* string: The original string.
 * Returns: the uppercase string.
 * (Pointer must be freed)
 */
char * strutil_uppercase(char *string) {
    size_t length = strlen(string);
    char *upper = calloc(length + 1, sizeof(char));

    for (size_t i = 0; i < length; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            upper[i] = string[i] - 32;
        }
    }

    return upper;
}
