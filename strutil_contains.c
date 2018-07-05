#include <stdlib.h>
#include <string.h>

#include "strutil.h"


/*
 * Checks if a string contains another string.
 * Argument(s):
 *   char *string: the string being searched.
 *   char *sequence: the sequence to search for.
 * Returns: an integer (1 for found, 0 for not).
 */
int strutil_contains(char *string, char *sequence) {
    char *s = string;

    if (strlen(sequence) > strlen(string)) {
        return 0;
    }

    for (size_t i = 0; i < strlen(string); i++) {
        if (!strncmp(s, sequence, strlen(sequence))) {
            return 1;
        } else {
            s++;
        }
    }

    return 0;
}
