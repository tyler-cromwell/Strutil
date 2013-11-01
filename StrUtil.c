/***************************************************************************
	Copyright (C) 2013  Tyler J. Cromwell

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
***************************************************************************/

/* Standard: gnu99 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <CVector.h>
#include <StrUtil.h>
    
#define STRING_END '\0' // Null terminator, marks end of a string.

/*
 * Gets the index of a character in a string.
 * Argument(s):
 *   const char* string, the string being examined.
 *   const char character, the character whose position being searched for.
 * Memory Management:
 *   Nothing to worry about here.
 * Returns: the index of 'character' in 'string'
 */
int indexOf(const char* string, const char character) {
	int i = 0;
	while (string[i] != character) i++;
	return i;
}

/*
 * Gets the indexes of a character in a string.
 * Argument(s):
 *   const char* string, the string being examined.
 *   const char character, the character whose position being searched for.
 *   int* amount, the size of the array of indexes
 * Memory Management:
 *   Free the returned pointer when done.
 * Returns: an array of all the indexes that 'character' is found at.
 */
int* indexesOf(char* string, char character, int* amount) {
	int buff[strlen(string)];
	*amount = 0;
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == character) {
			buff[*amount] = i;
			(*amount)++;
		}
	}
	int* indexes = calloc(*amount, sizeof(int));
	for (int i = 0; i < *amount; i++)
		indexes[i] = buff[i];
	return indexes;
}

/*
 * Splits up a string at a given token.
 * Argument(s):
 *   char* str, the string to be split.
 *   const char* token, the token used to split 'str' at.
 * Memory Management:
 *   Free the array member from the returned pointer when done.
 * Returns: a resizeable array of tokens.
 */
CVector split(char* str, const char* token) {
	CVector tokens = cv_init(0);
	char* part;
	part = strtok(str, token);
	int i = 0;
	while (part != NULL) {
		add(&tokens, i, (GenericType) part);
		part = strtok(NULL, token);
		i++;
	}
	return tokens;
}

/*
 * Derives a substring from a given string.
 * Argument(s):
 *   char* original, the string to derive the substring from.
 *   int start, the starting index.
 *   int end, the ending index.
 * Memory Management:
 *   Free the returned pointer when done.
 * Returns: the substring.
 */
char* substr(char* original, int start, int end) {
	char* substring = calloc(end-start+1, sizeof(char));
	int i = 0;
	while (i < (end-start)) {
		substring[i] = original[start+i];
		i++;
	}
	substring[end-start] = STRING_END;
	return substring;
}
