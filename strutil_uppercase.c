#include <stdlib.h>
#include <string.h>

#include <strutil.h>


/**
 * Sets alphabetic characters to uppercase.
 * Argument(s):
 *   char* string: The original string.
 */
void strutil_uppercase(char *string) {
    size_t length = strlen(string);

    for (size_t i = 0; i < length; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] = (char) (string[i] - 32);
        }
    }
}
