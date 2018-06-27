#include <stdlib.h>
#include <string.h>

#include <strutil.h>


/*
 * Reverses a given string.
 * Argument(s):
 *   char *string: the string being reversed.
 */
void strutil_reverse(char *string) {
    char temp = 0;
    size_t length = strlen(string);

    for (size_t i = 0; i < (length / 2); i++) {
        temp = string[i];
        string[i] = string[length-1-i];
        string[length-1-i] = temp;
    }
}
