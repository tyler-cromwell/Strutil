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

int indexOf(const char* string, const char character) {
	int i = 0;
	while (string[i] != character)
		i++;
	return i;
}

// Free array when done
CVector split(char* str, const char* delim) {
	CVector separation = cv_init(0);
	char* part;
	part = strtok(str, delim);
	int i = 0;
	while (part != NULL) {
		add(&separation, i, (GenericType) part);
		part = strtok(NULL, delim);
		i++;
	}
	return separation;
}

// Free string when done
char* substr(char* original, int start, int end) {
	char* substring = calloc(end-start+1, sizeof(char));
	int i = 0;
	while (i < (end-start)) {
		substring[i] = original[start+i];
		i++;
	}
	substring[end-start] = '\0';
	return substring;
}