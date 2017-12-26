#include <stdlib.h>
#include <string.h>

#include <strutil.h>


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

    free(local);
    return tokens;
}
