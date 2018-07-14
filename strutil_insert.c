#include <stdlib.h>
#include <string.h>

#include "strutil.h"


/*
 * Argument(s):
 *   char *original: the string to derive the substring from.
 *   size_t start: the starting index.
 *   size_t end: the ending index.
 * Returns: the substring.
 * (Pointer must be freed)
 */
char * strutil_insert(char *original, char *additional, size_t index) {
    size_t lo = strlen(original);
    size_t la = strlen(additional);

    if (index >= lo) {
        return NULL;
    }

    char *expanded = calloc(lo + la, sizeof(char));

    if (index == 0) {
        strncpy(expanded, additional, la);
        strncat(expanded, original, lo);
    } else {
        strncpy(expanded, original, index);
        strncat(expanded, additional, la);
        strncat(expanded, original + index, lo - index);
    }

    return expanded;
}
