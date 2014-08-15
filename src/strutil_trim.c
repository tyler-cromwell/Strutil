#include <stdlib.h>
#include <string.h>

#include <strutil.h>

#ifdef STRUTIL_DEBUG
	#include <stdio.h>
#endif

/*
 * Trims the leading and trailing whitespace from a string.
 * Argument(s):
 *   char* original: the string to be trimmed.
 * Note for Memory Management:
 *   Free the returned pointer when done.
 * Returns:
 *   The trimmed version of 'original' or NULL if original was NULL
 */
char* strutil_trim(char* original) {
	if (original != NULL) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: TRIM: Trimming \"%s\"\n" COLOR_RESET, original);
	#endif
		size_t i = 0;
		while (original[i] == ASCII_SPACE && i < strlen(original)) i++;

		size_t start = i;
		for (i = strlen(original)-1; original[i] == ASCII_SPACE && i > 0; i--);

		size_t end = i;
		char* new = calloc(end-start+2, sizeof(char));
		strncpy(new, original+start, end-start+1);

	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: TRIM: \"%s\" trimmed to \"%s\"\n" COLOR_RESET, original, new);
	#endif
		return new;
	} else {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: TRIM: Null was given, nothing done\n" COLOR_RESET);
	#endif
		return NULL;
	}
}
