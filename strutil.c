/***************************************************************************
	The MIT License (MIT)
	
	Copyright (c) 2013 Tyler Cromwell
	
	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:
	
	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
***************************************************************************/

/* Standard: gnu99 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data-structs/vector.h"
#include "strutil.h"

#define STRING_END '\0' // Null terminator, marks end of a string.
#define BLANK_SPACE 32  // The ASCII value for the Space character.

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
	unsigned int i = 0;
	while (string[i] != character)
		i++;
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
	for (unsigned int i = 0; i < strlen(string); i++) {
		if (string[i] == character) {
			buff[*amount] = i;
			(*amount)++;
		}
	}
	int* indexes = calloc(*amount, sizeof(int));
	for (unsigned int i = 0; i < (*amount); i++)
		indexes[i] = buff[i];
	return indexes;
}

/*
 * Replaces all the characters in a string that match the
 * given, with the new given character.
 * Argument(s):
 *   char* string, the string to be modified.
 *   char old, the character being replaced.
 *   char new, the character doing the replacing.
 * Memory Management:
 *   Nothing to worry about here.
 * Returns: void.
 */
void replaceAll(char* string, char old, char new) {
	int amount = 0;
	int* indexes = indexesOf(string, old, &amount);
	for (unsigned int i = 0; i < amount; i++)
		string[indexes[i]] = new;
	free(indexes);
}

/*
 * Splits up a string at a given token.
 * Argument(s):
 *   char* string, the string to be split.
 *   const char* token, the token used to split 'str' at.
 * Memory Management:
 *   Free the array member from the returned pointer when done.
 * Returns: a resizeable array of tokens.
 */
Vector vect_split(char* string, const char* token) {
	Vector tokens = vect_init(0);
	char* part;
	part = strtok(string, token);
	for (unsigned int i = 0; part != NULL; i++) {
		add(&tokens, i, (GenType) part);
		part = strtok(NULL, token);
	}
	return tokens;
}

/*
 * Splits up a string at a given token.
 * Argument(s):
 *   char* string, the string to be split.
 *   char* delimiter, the token used to split 'string' at.
 *   int* tokenAmount, a pointer to the number of tokens produced.
 * Memory Management:
 *   Free the string array when done.
 * Returns: an array of tokens.
 */
char** split_string(char* string, char* delimiter, int* tokenAmount) {
	char** tokens = calloc((*tokenAmount)+1, sizeof(char));
	char* tok = strtok(string, delimiter);
	for (unsigned int i = 0; tok != NULL; i++) {
		tokens[i] = tok;
		(*tokenAmount)++;
		tok = strtok(NULL, delimiter);
		if (tok != NULL) tokens = realloc(tokens, ((*tokenAmount)+1) * sizeof(char*));
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
char* substring(char* original, int start, int end) {
	char* substring = calloc(end-start+1, sizeof(char));
	for (unsigned int i = 0; i < (end-start); i++)
		substring[i] = original[start+i];
	substring[end-start] = STRING_END;
	return substring;
}

/*
 * Trims the leading and trailing whitespace from a string.
 * Argument(s):
 *   char* original, the string to be trimmed.
 * Memory Management:
 *   Free the returned pointer when done.
 * Returns: the trimmed version of 'original'.
 */
char* trim(char* original) {
	int i = 0;
	for (; original[i] == BLANK_SPACE; i++);
	int start = i;
	for (i = strlen(original)-1; original[i] == BLANK_SPACE; i--);
	int end = i;
	char* new = calloc(end-start+2, sizeof(char));
	for (int j = 0; j < end-start+1; j++)
		new[j] = original[j+start];
	new[end-start+1] = STRING_END;
	return new;
}
