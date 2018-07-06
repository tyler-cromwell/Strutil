#include <stdlib.h>
#include <string.h>

#include "strutil.h"


/*
 * Replaces all the characters in a string that match the
 * given, with the new given character.
 * Argument(s):
 *   char *string: the string to be modified.
 *   char old: the character being replaced.
 *   char new: the character doing the replacing.
 * Returns: the string with replaced characters.
 * (Pointer must be freed)
 */
char * strutil_replace_all(char *string, char old, char new) {
    size_t amount = 0;
    size_t length = strlen(string);
    size_t *indices = strutil_indices_of(string, old, &amount);
    char *replaced = calloc(length + 1, sizeof(char));

    strncpy(replaced, string, length);

    for (size_t i = 0; i < amount; i++) {
        replaced[indices[i]] = new;
    }

    free(indices);
    return replaced;
}
