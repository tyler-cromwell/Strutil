#include <stdlib.h>
#include <string.h>

#include <strutil.h>


/**
 * Sets alphabetic characters to lowercase.
 * Argument(s):
 *   char *string: The original string.
 * Memory Management:
 *   Free the returned pointer when done.
 * Returns: A new string with lowercase letters.
 */
char *strutil_lowercase(char *string) {
    size_t length = strlen(string);
    char *lower = calloc(length+1, sizeof(char));
    strncpy(lower, string, length);

    for (size_t i = 0; i < length; i++) {
        if (65 <= lower[i] && lower[i] <= 90) {
            lower[i] = (char) (string[i] + 32);
        }
    }

    return lower;
}
