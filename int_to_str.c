#include "monty.h"
#include <stdlib.h>

/**
 * getInt - gets char pointer to new str containing int
 * @num: Number to convert to string
 *
 * Return: char pointer to new string. NULL i fmalloc fails
 */

char *getInt(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
		length++;
	ret = malloc(length + 1);
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - gets the absolute value of an integer
 * @i: Integer to get absolute value of
 *
 * Return: Unsigned integer abs rep of 1
 */

unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - gets length of buffer needed for an unsigned int
 * @num: Number we are getting length of
 * @base: base of number representations used by buffer
 *
 * Return: Integer containing length of buffer needed
 */

int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - fills buffer with correct num to base of 36
 * @num: Number to convert to string given base
 * @base: Base of number in conversion only till base 36
 * @buff:buffer to fill with result of conversion
 * @buff_size:size of buffer in bytes
 *
 * Return: void always
 */

void fill_numbase_buff(unsigned int num, unsigned int base,
					   char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = rem % base;
		if (rem > 9)
			buff[i] = rem + 87;
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
