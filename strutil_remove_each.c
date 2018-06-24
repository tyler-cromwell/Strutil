#include <stdlib.h>
#include <string.h>

#include <strutil.h>


/*
 * Removes all occurences of each character in 'chars' from 'string'.
 * Argument(s):
 *   char* string: the string to be shortened.
 *   char* chars: the characters to be removed from 'string'.
 * Pre-Condition(s):
 *   strlen(chars) < strlen(string)
 * Memory Management:
 *   Free the returned string when done.
 * Returns: the shortened string.
 */
char* strutil_remove_each(char* string, char* chars) {
    char* shortened = calloc(strlen(string) - strlen(chars) + 1, sizeof(char));
    size_t index = 0;
    char exclude = 0;

    for (size_t i = 0; i < strlen(string); i++) {
        for (size_t j = 0; j < strlen(chars); j++) {
            if (string[i] == chars[j]) {
                exclude = 1;
                break;
            }
        }

        if (!exclude) {
            shortened[index] = string[i];
            index++;
        }

        exclude = 0;
    }

    shortened[index] = '\0';
    return shortened;
}
