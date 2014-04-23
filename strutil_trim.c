/* Standard: gnu99 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strutil.h"

/*
 * Trims the leading and trailing whitespace from a string.
 * Argument(s):
 *   char* original: the string to be trimmed.
 * Memory Management:
 *   Free the returned pointer when done.
 * Returns: the trimmed version of 'original'.
 */
char* strutil_trim(char* original) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: TRIM: Trimming \"%s\"\n" COLOR_RESET, original);
	#endif
	int i = 0;
	while (original[i] == ASCII_SPACE) i++;
	int start = i;
	for (i = strlen(original)-1; original[i] == ASCII_SPACE; i--);
	int end = i;
	char* new = calloc(end-start+2, sizeof(char));
	strncpy(new, original+start, end-start+1);
	return new;
}
