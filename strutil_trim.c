#include <stdlib.h>
#include <string.h>

#include "strutil.h"


/*
 * Trims the leading and trailing whitespace from a string.
 * Argument(s):
 *   char *original: the string to be trimmed.
 * Note for Memory Management:
 *   Free the returned pointer when done.
 * Returns:
 *   The trimmed version of 'original' or NULL if original was NULL
 */
char *strutil_trim(char *original) {
    if (original != NULL) {
        size_t i = 0;
        while (original[i] == ' ' && i < strlen(original)) i++;

        size_t start = i;
        for (i = strlen(original)-1; original[i] == ' ' && i > 0; i--);

        size_t end = i;
        char *new = calloc(end-start+2, sizeof(char));
        strncpy(new, original+start, end-start+1);
        return new;
    }
    else {
        return NULL;
    }
}
