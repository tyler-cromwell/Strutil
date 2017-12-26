#include <stdlib.h>
#include <string.h>

#include <strutil.h>


/*
 * Gets the first index of a character in a string.
 * Argument(s):
 *   char *string: the string being examined.
 *   char character: the character whose position being searched for.
 * Returns: the index of 'character' in 'string'
 *          or string length if not found
 */
inline size_t strutil_index_of(char *string, char character) {
    size_t i = 0;
    while (string[i] != character && string[i] != '\0') i++;
    return i;
}
