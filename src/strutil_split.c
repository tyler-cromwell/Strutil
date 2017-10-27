#include <stdlib.h>
#include <string.h>

#include <strutil.h>

#ifdef STRUTIL_DEBUG
#include <stdio.h>
#endif


/*
 * Splits up a string at a given token.
 * Each element WILL BE null-terminated.
 * Argument(s):
 *   char *string: the string to be split.
 *   char *delimiter: the token used to split 'string' at.
 *   size_t *tokenAmount: a pointer to the number of tokens produced.
 * Memory Management:
 *   Free the string array when done.
 * Returns: an array of tokens.
 */
char **strutil_split(char *string, char *delimiter, size_t *tokenAmount) {
    char *local = calloc(strlen(string)+1, sizeof(char));
    strncpy(local, string, strlen(string)+1);

#ifdef STRUTIL_DEBUG
    char original[strlen(string)+1];
    strncpy(original, string, strlen(string)+1);
    fprintf(stdout, COLOR_YELLOW "STRUTIL: SPLIT_STRING: Spliting \"%s\" at every occurence of \"%s\"\n" COLOR_RESET, string, delimiter);
#endif

    char **tokens = calloc(1, sizeof(char*));
    char *tok = strtok(local, delimiter);

    for (size_t i = 0; tok != NULL; i++) {
        size_t length = strlen(tok)+1;
        char *token = calloc(length, sizeof(char));

        strncpy(token, tok, length);
        tokens[i] = token;
        (*tokenAmount)++;
        tok = strtok(NULL, delimiter);

        if (tok != NULL) {
            tokens = realloc(tokens, ((*tokenAmount)+1) * sizeof(char*));
        }
    }

#ifdef STRUTIL_DEBUG
    fprintf(stdout, COLOR_YELLOW "STRUTIL: SPLIT_STRING: \"%s\" after split: [", original);

    for (size_t i = 0; i < *tokenAmount; i++) {
        if (i == *tokenAmount-1) {
            fprintf(stdout, "\"%s\"", tokens[i]);
        } else {
            fprintf(stdout, "\"%s\", ", tokens[i]);
        }
    }

    fprintf(stdout, "]\n" COLOR_RESET);
#endif

    free(local);
    return tokens;
}

