#include <stdlib.h>
#include <string.h>

#include "strutil.h"

#ifdef STRUTIL_DEBUG
	#include <stdio.h>
#endif

/*
 * Gets the indexes of a character in a string.
 * Argument(s):
 *   const char* string: the string being examined.
 *   const char character: the character whose position being searched for.
 *   size_t* amount: the size of the array of indexes
 * Memory Management:
 *   Free the returned array when done.
 * Returns: an array of all the indexes that 'character' is found at.
 */
int* strutil_indexesOf(char* string, char character, size_t* amount) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: INDEXES_OF: Searching \"%s\" for all occurences of \'%c\'\n" COLOR_RESET, string, character);
	#endif

	size_t length = strlen(string);
	int buff[length];
	memset(buff, 0, length);

	for (size_t i = 0; i < length; i++) {
		if (string[i] == character) {
			#ifdef STRUTIL_DEBUG
				printf(COLOR_YELLOW "STRUTIL: INDEXES_OF: '%c' found at '%zd'.\n" COLOR_RESET, character, i);
			#endif
			buff[*amount] = i;
			(*amount)++;
		}
	}

	int* indexes = calloc(*amount, sizeof(int));
	for (size_t i = 0; i < (*amount); i++)
		indexes[i] = buff[i];

	return indexes;
}
