#include <stdlib.h>
#include <string.h>

#include <strutil.h>

#ifdef STRUTIL_DEBUG
#include <stdio.h>
#endif

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
char* strutil_removeThese(char* string, char* chars) {
    #ifdef STRUTIL_DEBUG
    fprintf(stderr, COLOR_YELLOW "STRUTIL: REMOVE_THESE: Attempting to remove characters \"%s\" from \"%s\"\n" COLOR_RESET, chars, string);
    #endif

    char* shortened = calloc(strlen(string) - strlen(chars) + 1, sizeof(char));
    size_t index = 0;

    for (size_t i = 0; i < strlen(string); i++) {
        for (size_t j = 0; j < strlen(chars); j++) {
            if (string[i] != chars[j]) {
                #ifdef STRUTIL_DEBUG
                fprintf(stderr, COLOR_YELLOW "STRUTIL: REMOVE_THESE: \'%c\'\n" COLOR_RESET, string[i]);
                #endif
                shortened[index] = string[i];
                index++;
            }
        }
    }

    shortened[index] = ASCII_NULL;

    #ifdef STRUTIL_DEBUG
    fprintf(stderr, COLOR_YELLOW "STRUTIL: REMOVE_THESE: \"%s\" shortened to \"%s\"\n" COLOR_RESET, string, shortened);
    #endif
    return shortened;
}
