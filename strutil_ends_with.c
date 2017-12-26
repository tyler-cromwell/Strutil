#include <stdlib.h>
#include <string.h>

#include <strutil.h>


/*
 * Compares the last n bytes of string to endtok to
 * see if string ends with endtok.
 * Argument(s):
 *   char *string: The string being searched.
 *   char *endtok: The token being searched for.
 * Returns: an integer (1 for yes, 0 for no).
 */
int strutil_ends_with(char *string, char *endtok) {
    if (strlen(endtok) > strlen(string)) {
        return 0;
    }

    char *substr = strutil_substring(string, strlen(string)-strlen(endtok), strlen(string));

    if (!strncmp(substr, endtok, strlen(endtok))) {
        free(substr);
        return 1;
    } else {
        free(substr);
        return 0;
    }
}
