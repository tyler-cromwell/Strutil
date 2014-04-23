/* Standard: gnu99 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strutil.h"

/*
 * Splits up a string at a given token.
 * Argument(s):
 *   char* string: the string to be split.
 *   char* delimiter: the token used to split 'string' at.
 *   int* tokenAmount: a pointer to the number of tokens produced.
 * Memory Management:
 *   Free the string array when done.
 * Returns: an array of tokens.
 */
char** strutil_split(char* string, const char* delimiter, unsigned int* tokenAmount) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: SPLIT_STRING: Spliting \"%s\" at every occurence of \"%s\"\n" COLOR_RESET, string, delimiter);
	#endif
	char** tokens = calloc(1, sizeof(char*));
	char* tok = strtok(string, delimiter);
	for (size_t i = 0; tok != NULL; i++) {
		tokens[i] = tok;
		(*tokenAmount)++;
		tok = strtok(NULL, delimiter);
		if (tok != NULL) tokens = realloc(tokens, ((*tokenAmount)+1) * sizeof(char*));
	}
	return tokens;
}
