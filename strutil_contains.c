#include <stdlib.h>
#include <string.h>

#include <strutil.h>

#ifdef STRUTIL_DEBUG
#include <stdio.h>
#endif


/*
 * Checks if a string contains another string.
 * Argument(s):
 *   char *string: the string being searched.
 *   char *sequence: the sequence to search for.
 * Returns: an integer (1 for found, 0 for not).
 */
int strutil_contains(char *string, char *sequence) {
    char *s = string;
#ifdef STRUTIL_DEBUG
    fprintf(stdout, COLOR_YELLOW "STRUTIL: CONTAINS: Searching through \"%s\" for \"%s\".\n" COLOR_RESET, string, sequence);
#endif

    if (strlen(sequence) > strlen(string)) {
#ifdef STRUTIL_DEBUG
        fprintf(stdout, COLOR_YELLOW "STRUTIL: CONTAINS: Sequence \"%s\" is longer than \"%s\".\n" COLOR_RESET, sequence, string);
#endif
        return 0;
    }

    for (size_t i = 0; i < strlen(string); i++) {
#ifdef STRUTIL_DEBUG
        fprintf(stdout, COLOR_YELLOW "STRUTIL: CONTAINS: \"%s\" \"%s\"\n" COLOR_RESET, s, sequence);
#endif
        if (!strncmp(s, sequence, strlen(sequence))) {
#ifdef STRUTIL_DEBUG
            fprintf(stdout, COLOR_YELLOW "STRUTIL: CONTAINS: Found \"%s\" in \"%s\".\n" COLOR_RESET, sequence, string);
#endif
            return 1;
        } else {
            s++;
        }
    }

#ifdef STRUTIL_DEBUG
    fprintf(stdout, COLOR_YELLOW "STRUTIL: CONTAINS: Sequence \"%s\" was not found in \"%s\".\n" COLOR_RESET, sequence, string);
#endif
    return 0;
}
