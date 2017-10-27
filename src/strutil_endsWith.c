#include <stdlib.h>
#include <string.h>

#include <strutil.h>

#ifdef STRUTIL_DEBUG
#include <stdio.h>
#endif


/*
 * Compares the last n bytes of string to endtok to
 * see if string ends with endtok.
 * Argument(s):
 *   char *string: The string being searched.
 *   char *endtok: The token being searched for.
 * Returns: an integer (1 for yes, 0 for no).
 */
int strutil_endsWith(char *string, char *endtok) {
    if (strlen(endtok) > strlen(string)) {
#ifdef STRUTIL_DEBUG
        fprintf(stderr, COLOR_YELLOW "STRUTIL: ENDS_WITH: Token \"%s\" is longer than \"%s\".\n" COLOR_RESET, endtok, string);
#endif
        return 0;
    }

#ifdef STRUTIL_DEBUG
    fprintf(stderr, COLOR_YELLOW "STRUTIL: ENDS_WITH: Comparing the last \'%zu\' byte(s) of \"%s\" to \"%s\"\n" COLOR_RESET, strlen(endtok), string, endtok);
#endif

    char *substr = strutil_substring(string, strlen(string)-strlen(endtok), strlen(string));

    if (!strncmp(substr, endtok, strlen(endtok))) {
#ifdef STRUTIL_DEBUG
        fprintf(stderr, COLOR_YELLOW "STRUTIL: ENDS_WIDTH: \"%s\" ends with \"%s\".\n" COLOR_RESET, string, endtok);
#endif
        free(substr);
        return 1;
    } else {
#ifdef STRUTIL_DEBUG
        fprintf(stderr, COLOR_YELLOW "STRUTIL: ENDS_WIDTH: \"%s\" does not end with \"%s\".\n" COLOR_RESET, string, endtok);
#endif
        free(substr);
        return 0;
    }
}
