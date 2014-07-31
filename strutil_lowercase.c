#include <stdlib.h>
#include <string.h>

#include "strutil.h"

#ifdef STRUTIL_DEBUG
	#include <stdio.h>
#endif

/**
 * Sets alphabetic characters to lowercase.
 * The number of characters altered is the number given
 * if less than the length of the string.
 * Argument(s):
 *   char* string: The original string.
 *   size_t amount: The number of characters to alter.
 * Memory Management:
 *   Free the returned pointer when done.
 * Returns: A new string with lowercase letters.
 */
char* strutil_lowercase(char* string, size_t amount) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: LOWERCASE: Setting all alphabetic characters in \"%s\" to lowercase.\n" COLOR_RESET, string);
	#endif

	size_t length = strlen(string);
	char* lower = calloc(length+1, sizeof(char));

	strncpy(lower, string, length);

	for (size_t i = 0; i < length && i < amount; i++) {
		if (65 <= lower[i] && lower[i] <= 90)
			lower[i] = (char) (string[i] + 32);
	}

	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: LOWERCASE: \"%s\" transformed to \"%s\".\n" COLOR_RESET, string, lower);
	#endif

	return lower;
}
