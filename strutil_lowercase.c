#include <stdlib.h>
#include <string.h>

#include <strutil.h>


/**
 * Sets alphabetic characters to lowercase.
 * Argument(s):
 *   char *string: The original string.
 */
void strutil_lowercase(char *string) {
    size_t length = strlen(string);

    for (size_t i = 0; i < length; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = (char) (string[i] + 32);
        }
    }
}
