#include <stdlib.h>
#include <string.h>

#include <strutil.h>

#ifdef STRUTIL_DEBUG
#include <stdio.h>
#endif

/*
 * Gets the first index of a character in a string.
 * Argument(s):
 *   char* string: the string being examined.
 *   char character: the character whose position being searched for.
 * Returns: the index of 'character' in 'string'
 */
inline size_t strutil_indexOf(char* string, char character) {
	#ifdef STRUTIL_DEBUG
	printf(COLOR_YELLOW "STRUTIL: INDEX_OF: Searching \"%s\" for first occurence of \'%c\'\n" COLOR_RESET, string, character);
	#endif

	size_t i = 0;
	while (string[i] != character) i++;

	#ifdef STRUTIL_DEBUG
	printf(COLOR_YELLOW "STRUTIL: INDEX_OF: \'%c\' found at \'%zu\'\n" COLOR_RESET, character, i);	
	#endif
	return i;
}
