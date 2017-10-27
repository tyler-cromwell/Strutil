#include <stdlib.h>
#include <string.h>

#include <strutil.h>

#ifdef STRUTIL_DEBUG
#include <stdio.h>
#endif


/**
 * Sets alphabetic characters to uppercase.
 * Argument(s):
 *   char* string: The original string.
 * Memory Management:
 *   Free the returned pointer when done.
 * Returns: A new string with uppercase letters.
 */
char *strutil_uppercase(char *string) {
#ifdef STRUTIL_DEBUG
    fprintf(stderr, COLOR_YELLOW "STRUTIL: UPPERCASE: Setting all alphabetic characters in \"%s\" to uppercase.\n" COLOR_RESET, string);
#endif

    size_t length = strlen(string);
    char *upper = calloc(length+1, sizeof(char));
    strncpy(upper, string, length);

    for (size_t i = 0; i < length; i++) {
        if (97 <= upper[i] && upper[i] <= 122) {
            upper[i] = (char) (string[i] - 32);
        }
    }

#ifdef STRUTIL_DEBUG
    fprintf(stderr, COLOR_YELLOW "STRUTIL: UPPERCASE: \"%s\" transformed to \"%s\".\n" COLOR_RESET, string, upper);
#endif
    return upper;
}
