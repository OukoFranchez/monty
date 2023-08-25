#include "monty.h"
#include <stdlib.h>
/**
 * strtow - separate string's words
 *
 * @string: string to seperate into words
 * @delim: delimitors to use to delimit words
 *
 * Return: 2D array of pointers to each word
 */

char **strtow(char *string, char *delim)
{
	char **words = NULL;
	int word_count, word_length, n, k = 0;

	if (string == NULL || !*string)
		return (NULL);
	word_count = get_word_count(string, delim);

	if (word_count == 0)
		return (NULL);
	words = malloc((word_count + 1) * sizeof(char *));

	if (words == NULL)
		return (NULL);
	while (k < word_count)
	{
		word_length = get_word_length(string, delim);
		if (is_char_delim(*string, delim))
			string = get_next_word(string, delim);
		words[k] = malloc((word_length + 1) * sizeof(char));
		if (words[k] == NULL)
		{
			while (k >= 0)
			{
				k--;
				free(words[k]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < word_length)
		{
			words[k][n] = *(string + n);
			n++;
		}
		words[k][n] = '\0'; /* set end of string */
		string = get_next_word(string, delim);
		k++;
	}
	words[k] = NULL; /* last element is null for iteration */
	return (words);
}

/**
 * is_char_delim - checks if stream has delimitor char
 * @ch: character in stream
 * @delim: pointer to null terminated array of delimitors
 * Return: 1 (success) 0 (failure)
 */

int is_char_delim(char ch, char *delim)
{
	int k = 0;

	while (delim[k])
	{
		if (delim[k] == ch)
			return (1);
		k++;
	}

	return (0);
}

/**
 * get_word_length - gets the word length of current word in string
 *
 * @string: string to get word length from current word
 * @delim: delimitors to use to delimit words
 *
 * Return: word length of current word
 */

int get_word_length(char *string, char *delim)
{
	int word_length = 0, pending = 1, k = 0;

	while (*(string + k))
	{
		if (is_char_delim(string[k], delim))
			pending = 1;
		else if (pending)
		{
			word_length++;
		}
		if (word_length > 0 && is_char_delim(string[k], delim))
			break;
		k++;
	}
	return (word_length);
}

/**
 * get_word_count - gets the word count of string
 * @string: string to get word count from
 * @delim: delimitors to use to delimit words
 * Return: the word count of the string
 */

int get_word_count(char *string, char *delim)
{
	int word_count = 0, pending = 1, k = 0;

	while (*(string + k))
	{
		if (is_char_delim(string[k], delim))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			word_count++;
		}
		k++;
	}
	return (word_count);
}

/**
 * get_next_word - gets the next word in a string
 *
 * @string: string to get next word from
 * @delim: delimitors to use in delemiting words
 * Return: pointer to first char of next word
 */

char *get_next_word(char *string, char *delim)
{
	int pending = 0;
	int k = 0;

	while (*(string + k))
	{
		if (is_char_delim(string[k], delim))
		{
			pending = 1;
		}
		else if (pending)
		{
			break;
		}
		k++;
	}

	return (string + k);
}
