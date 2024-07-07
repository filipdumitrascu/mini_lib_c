// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/**
	 * Iterates through the source string and copy char by char
	 * into destination string
	 */
    for (; *source; source++, destination++)
        *destination = *source;

    *destination = '\0';

    return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/**
	 * strcpy is called if len is bigger than source's len or
	 * copy char by char at most len times
	 */
	if (len >= strlen(source)) {
		strcpy(destination, source);

	} else {
    	for (; len > 0; len--, source++, destination++)
        	*destination = *source;
	}

    return destination;
}

char *strcat(char *destination, const char *source)
{
	/**
	 * Start copying char by char in destination from
	 * source right after the existing string
	 */
	return strcpy(destination + strlen(destination), source);
}

char *strncat(char *destination, const char *source, size_t len)
{
	/**
	 * Knowing that in main function there is no '\0' added after the string,
	 * the strncpy function can't be called so do the same and add the '\0'
	 */
	destination += strlen(destination);

	for (; len > 0 && *source; len--, source++, destination++)
        *destination = *source;

	*destination = '\0';

    return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/**
	 * Every case is treated and the correct int is returned based on
	 * the string lengths and their chars
	 */
	if (strlen(str1) < strlen(str2)) {
		return -1;

	} else if ((strlen(str1) > strlen(str2))) {
		return 1;

	} else {
		for (size_t i = 0; i < strlen(str1); i++) {
			if (str1[i] < str2[i])
				return -1;

			else if (str1[i] > str2[i])
				return 1;
		}
	}

	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/**
	 * Only len chars are compared, not taking into account
	 * the string lengths
	 */
	if (len > strlen(str1) || len > strlen(str2))
		return strcmp(str1, str2);

	for (size_t i = 0; i < len; i++) {
		if (str1[i] < str2[i])
			return -1;

		else if (str1[i] > str2[i])
			return 1;
	}

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/**
	 * When the wished char is found, returns his address
	 */
	for (; *str != '\0'; str++) {
		if (*str == (char) c)
			return (char *) str;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/**
	 * Search for the wished char starting with the last
	 * character of the string and returns his address
	 */
	char *copy_pointer = (char *) str;
	str += strlen(str);

	for (;  str > copy_pointer; str--) {
		if (*str == (char) c)
			return (char *) str;
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/**
	 * Starting with the first character of haystack, take every strlen(needle)
	 * sequence of chars from haystack and compares it with the needle string
	 */
	for (size_t i = 0; i <= strlen(haystack) - strlen(needle); i++) {
        size_t j;
        for (j = 0; j < strlen(needle); j++)
            if (haystack[i + j] != needle[j])
                break;

        if (j == strlen(needle))
            return (char *)(haystack + i);
    }

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/**
	 * Starting with the last character of haystack, take every strlen(needle)
	 * sequence of chars from haystack and compares it with the needle string
	 */
	for (size_t i = strlen(haystack) - 1; i >= strlen(needle) - 1; i--) {
        size_t j;
        for (j = 0; j < strlen(needle); j++)
            if (haystack[i - strlen(needle) + 1 + j] != needle[j])
                break;

        if (j == strlen(needle))
            return (char *)(haystack + i - strlen(needle) + 1);
    }

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/**
	 * Knowing that char has one byte, cast the void value
	 * to char and iterates through num chars to copy them
	 */
	char *dest = (char *)destination;
    char *src = (char *)source;

    for (size_t i = 0; i < num; i++)
        dest[i] = src[i];

    return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/**
	 * Move the memory taking into account the overlap
	 */
	char *dest = (char *)destination;
    char *src = (char *)source;

	if (dest < src) {
        for (size_t i = 0; i < num; i++)
            dest[i] = src[i];

    } else if (dest > src) {
        for (size_t i = num; i > 0; i--)
            dest[i - 1] = src[i - 1];
    }

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/**
	 * Compare byte by byte the 2 blocks of memory an returns an integer less
	 * than, equal to, or greater than zero based on which num bytes is greater
	 */
	unsigned char *p1 = (unsigned char *)ptr1;
    unsigned char *p2 = (unsigned char *)ptr2;

    for (size_t i = 0; i < num; i++)
        if (p1[i] != p2[i])
            return p1[i] - p2[i];

    return 0;
}

void *memset(void *source, int value, size_t num)
{
	/**
	 * Fills the first num bytes of the memory area pointed
	 * to by source with the constant byte value
	 */
	unsigned char *p = (unsigned char *)source;

    for (size_t i = 0; i < num; i++)
        p[i] = (unsigned char)value;

    return source;
}
