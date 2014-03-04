/* Standard: gnu99 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strutil.h"

#ifdef STRUTIL_DEBUG
	#ifndef COLOR_YELLOW
		#define COLOR_YELLOW "\x1b[33m" // ANSI Escape Code for turning on yellow terminal text
	#endif
	#ifndef COLOR_RESET
		#define COLOR_RESET  "\x1b[0m"  // ANSI Escape Code for turning off colored terminal text
	#endif
#endif

#ifndef ASCII_SPACE
	#define ASCII_SPACE	32 // The ASCII value for the Space character.
#endif

#ifndef ASCII_NULL
	#define ASCII_NULL 0 // The ASCII value for the Null character.
#endif

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

/*
 * Compares the last n bytes of string to endtok to
 * see if string ends with endtok.
 * Argument(s):
 *   char* string: The string being searched.
 *   char* endtok: The token being searched for.
 * Returns: an integer (1 for yes, 0 for no).
 */
int strutil_endsWith(char* string, char* endtok) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: ENDS_WITH: Comparing the last \'%d\' bytes of \"%s\" to \"%s\"\n" COLOR_RESET, strlen(endtok), string, endtok);
	#endif
	char* substr = strutil_substring(string, strlen(string)-strlen(endtok), strlen(string));
	int bit = 0;
	if (!strncmp(substr, endtok, strlen(endtok)))
		bit = 1;
	free(substr);
	return bit;
}

/*
 * Compares the first n bytes of string to starttok to
 * see if string starts with starttok.
 * Argument(s):
 *   char* string: The string being searched.
 *   char* starttok: The token being searched for.
 * Returns: an integer (1 for yes, 0 for no).
 */
inline int strutil_startsWith(char* string, char* starttok) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: STARTS_WITH: Comparing the first \'%d\' bytes of \"%s\" to \"%s\"\n" COLOR_RESET, strlen(starttok), string, starttok);
	#endif
	return !strncmp(string, starttok, strlen(starttok));
}

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
	return i;
}

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
int* strutil_indexesOf(char* string, char character, int* amount) {
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

/*
 * Removes all occurences of each character in 'chars' from 'string'.
 * Argument(s):
 *   char* string: the string to be shortened.
 *   char* chars: the characters to be removed from 'string'.
 * Pre-Condition(s):
 *   strlen(chars) < strlen(string)
 * Memory Management:
 *   Free the returned string when done.
 * Returns: the shortened string.
 */
char* strutil_removeThese(char* string, char* chars) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: REMOVE_THESE: Attempting to remove characters \"%s\" from \"%s\"\n" COLOR_RESET, chars, string);
	#endif
	char* shortened = calloc(strlen(string) - strlen(chars) + 1, sizeof(char));
	size_t index = 0;
	for (size_t i = 0; i < strlen(string); i++) {
		for (size_t j = 0; j < strlen(chars); j++) {
			if (string[i] != chars[j]) {
				#ifdef STRUTIL_DEBUG
					printf(COLOR_YELLOW "STRUTIL: REMOVE_THESE: \'%c\'\n" COLOR_RESET, string[i]);
				#endif
				shortened[index] = string[i];
				index++;
			}
		}
	}
	shortened[index] = ASCII_NULL;
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: REMOVE_THESE: \"%s\" shortened to \"%s\"\n" COLOR_RESET, string, shortened);
	#endif
	return shortened;
}

/*
 * Replaces all the characters in a string that match the
 * given, with the new given character.
 * Argument(s):
 *   char* string: the string to be modified.
 *   char old: the character being replaced.
 *   char new: the character doing the replacing.
 */
void strutil_replaceAll(char* string, char old, char new) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: REPLACE_ALL: Replacing all occurences of \'%c\' with \'%c\' in \"%s\"\n" COLOR_RESET, old, new, string);
	#endif
	int amount = 0;
	int* indexes = strutil_indexesOf(string, old, &amount);
	for (size_t i = 0; i < amount; i++)
		string[indexes[i]] = new;
	free(indexes);
}

/*
 * Splits up a string at a given token.
 * Argument(s):
 *   char* string: the string to be split.
 *   char* delimiter: the token used to split 'string' at.
 *   int* tokenAmount: a pointer to the number of tokens produced.
 * Memory Management:
 *   Free the string array when done.
 * Returns: an array of tokens.
 */
char** strutil_split(char* string, const char* delimiter, int* tokenAmount) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: SPLIT_STRING: Spliting \"%s\" at every occurence of \"%s\"\n" COLOR_RESET, string, delimiter);
	#endif
	char** tokens = calloc(1, sizeof(char*));
	char* tok = strtok(string, delimiter);
	for (size_t i = 0; tok != NULL; i++) {
		tokens[i] = tok;
		(*tokenAmount)++;
		tok = strtok(NULL, delimiter);
		if (tok != NULL) tokens = realloc(tokens, ((*tokenAmount)+1) * sizeof(char*));
	}
	return tokens;
}

/*
 * Derives a substring from a given string. (start <= N < end)
 * Argument(s):
 *   char* original: the string to derive the substring from.
 *   int start: the starting index.
 *   int end: the ending index.
 * Memory Management:
 *   Free the returned pointer when done.
 * Returns: the substring.
 */
char* strutil_substring(char* original, int start, int end) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: SUBSTRING: Retrieving substring of \"%s\" from %d to %d\n" COLOR_RESET, original, start, end);
	#endif
	char* substring = calloc((end-start)+1, sizeof(char));
	strncpy(substring, original+start, end-start);
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: SUBSTRING: Substring of \"%s\" from %d to %d is \"%s\"\n" COLOR_RESET, original, start, end, substring);
	#endif
	return substring;
}

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
