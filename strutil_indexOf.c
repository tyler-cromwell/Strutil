/* Standard: gnu99 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strutil.h"

/*
 * Gets the first index of a character in a string.
 * Argument(s):
 *   const char* string: the string being examined.
 *   const char character: the character whose position being searched for.
 * Returns: the index of 'character' in 'string'
 */
inline int strutil_indexOf(const char* string, const char character) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: INDEX_OF: Searching \"%s\" for first occurence of \'%c\'\n" COLOR_RESET, string, character);
	#endif
	size_t i = 0;
	while (string[i] != character) i++;
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: INDEX_OF: \'%c\' found at \'%d\'\n" COLOR_RESET, character, i);	
	#endif
	return i;
}
