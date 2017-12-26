#include <stdlib.h>
#include <string.h>

#include <strutil.h>


/*
 * Replaces all the characters in a string that match the
 * given, with the new given character.
 * Argument(s):
 *   char *string: the string to be modified.
 *   char old: the character being replaced.
 *   char new: the character doing the replacing.
 */
void strutil_replace_all(char *string, char old, char new) {
    size_t amount = 0;
    size_t *indices = strutil_indices_of(string, old, &amount);

    for (size_t i = 0; i < amount; i++) {
        string[indices[i]] = new;
    }

    free(indices);
}
