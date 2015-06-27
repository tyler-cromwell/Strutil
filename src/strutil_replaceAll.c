#include <stdlib.h>
#include <string.h>

#include <strutil.h>

#ifdef STRUTIL_DEBUG
#include <stdio.h>
#endif

/*
 * Replaces all the characters in a string that match the
 * given, with the new given character.
 * Argument(s):
 *   char *string: the string to be modified.
 *   char old: the character being replaced.
 *   char new: the character doing the replacing.
 */
void strutil_replaceAll(char *string, char old, char new) {
    #ifdef STRUTIL_DEBUG
    char original[strlen(string)+1];
    strncpy(original, string, strlen(string)+1);
    fprintf(stderr, COLOR_YELLOW "STRUTIL: REPLACE_ALL: Replacing all occurences of \'%c\' with \'%c\' in \"%s\"\n" COLOR_RESET, old, new, string);
    #endif

    size_t amount = 0;
    size_t *indexes = strutil_indexesOf(string, old, &amount);

    for (size_t i = 0; i < amount; i++) {
        string[indexes[i]] = new;
    }

    free(indexes);

    #ifdef STRUTIL_DEBUG
    fprintf(stderr, COLOR_YELLOW "STRUTIL: REPLACE_ALL: \"%s\" is now \"%s\"\n" COLOR_RESET, original, string);
    #endif
}
