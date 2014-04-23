/* Standard: gnu99 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strutil.h"

/*
 * Gets the indexes of a character in a string.
 * Argument(s):
 *   const char* string: the string being examined.
 *   const char character: the character whose position being searched for.
 *   int* amount: the size of the array of indexes
 * Memory Management:
 *   Free the returned array when done.
 * Returns: an array of all the indexes that 'character' is found at.
 */
int* strutil_indexesOf(char* string, char character, unsigned int* amount) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: INDEXES_OF: Searching \"%s\" for all occurences of \'%c\'\n" COLOR_RESET, string, character);
	#endif
	int buff[strlen(string)];
	for (size_t i = 0; i < strlen(string); i++) {
		if (string[i] == character) {
			buff[*amount] = i;
			(*amount)++;
		}
	}
	int* indexes = calloc(*amount, sizeof(int));
	for (size_t i = 0; i < (*amount); i++)
		indexes[i] = buff[i];
	return indexes;
}
