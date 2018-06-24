#include <stdlib.h>
#include <string.h>

#include <strutil.h>


/**
 * Sets alphabetic characters to uppercase.
 * Argument(s):
 *   char* string: The original string.
 * Memory Management:
 *   Free the returned pointer when done.
 * Returns: A new string with uppercase letters.
 */
char *strutil_uppercase(char *string) {
    size_t length = strlen(string);
    char *upper = calloc(length+1, sizeof(char));

    for (size_t i = 0; i < length; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            upper[i] = (char) (string[i] - 32);
        } else {
            upper[i] = string[i];
        }
    }

    return upper;
}
