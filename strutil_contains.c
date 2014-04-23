/* Standard: gnu99 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strutil.h"

/*
 * Checks if a string contains another string.
 * Argument(s):
 *   char* string: the string being searched.
 *   char* sequence: the sequence to search for.
 * Returns: an integer (1 for found, 0 for not).
 */
int strutil_contains(char* string, char* sequence) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: CONTAINS: Searching \"%s\" for \"%s\"\n" COLOR_RESET, string, sequence);
	#endif
	for (size_t i = 0; i < strlen(string); i++) {
		#ifdef STRUTIL_DEBUG
			printf(COLOR_YELLOW "STRUTIL: CONTAINS: \"%s\" \"%s\"\n" COLOR_RESET, string, sequence);
		#endif
		if (!strncmp(string, sequence, strlen(sequence)))
			return 1;
		else string++;
	}
	return 0;
}
