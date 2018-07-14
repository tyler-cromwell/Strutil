#include <stdlib.h>
#include <string.h>

#include "strutil.h"


/*
 * Removes contents in range [start, end).
 * Argument(s):
 *   char *original: the string to remove from.
 *   size_t start: the starting index.
 *   size_t end: the ending index.
 * Returns: the new string.
 * (Pointer must be freed)
 */
char * strutil_remove(char *original, size_t start, size_t end) {
    size_t len = end - start;
    size_t length = strlen(original);
    char *condensed = calloc(length-len+1, sizeof(char));
    strncpy(condensed, original, start);
    strncat(condensed, original + end, length - end);
    return condensed;
}
