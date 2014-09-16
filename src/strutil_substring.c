#include <stdlib.h>
#include <string.h>

#include <strutil.h>

#ifdef STRUTIL_DEBUG
#include <stdio.h>
#endif

/*
 * Derives a substring from a given string. (start <= i < end)
 * Substring WILL BE null-terminated.
 * Argument(s):
 *   char* original: the string to derive the substring from.
 *   size_t start: the starting index.
 *   size_t end: the ending index.
 * Memory Management:
 *   Free the returned pointer when done.
 * Returns: the substring.
 */
char* strutil_substring(char* original, size_t start, size_t end) {
    #ifdef STRUTIL_DEBUG
    printf(COLOR_YELLOW "STRUTIL: SUBSTRING: Retrieving substring of \"%s\" from %zu to %zu\n" COLOR_RESET, original, start, end);
    #endif

    char* substring = calloc((end-start)+1, sizeof(char));
    strncpy(substring, original+start, end-start);

    #ifdef STRUTIL_DEBUG
    printf(COLOR_YELLOW "STRUTIL: SUBSTRING: Substring of \"%s\" from %zu to %zu is \"%s\"\n" COLOR_RESET, original, start, end, substring);
    #endif
    return substring;
}
