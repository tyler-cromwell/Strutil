#include <stdlib.h>
#include <string.h>

#include "strutil.h"


/**
 * Sets alphabetic characters to lowercase.
 * Argument(s):
 *   char *string: The original string.
 * Returns: the lowercase string.
 * (Pointer must be freed)
 */
char * strutil_lowercase(char *string) {
    size_t length = strlen(string);
    char *lower = calloc(length + 1, sizeof(char));

    for (size_t i = 0; i < length; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            lower[i] = string[i] + 32;
        }
    }

    return lower;
}
