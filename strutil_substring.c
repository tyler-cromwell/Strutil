#include <stdlib.h>
#include <string.h>

#include "strutil.h"


/*
 * Derives a substring from a given string. (start <= i < end)
 * Substring WILL BE null-terminated.
 * Argument(s):
 *   char *original: the string to derive the substring from.
 *   size_t start: the starting index.
 *   size_t end: the ending index.
 * Memory Management:
 *   Free the returned pointer when done.
 * Returns: the substring.
 */
char *strutil_substring(char *original, size_t start, size_t end) {
    char *substring = calloc((end-start)+1, sizeof(char));
    strncpy(substring, original+start, end-start);
    return substring;
}
