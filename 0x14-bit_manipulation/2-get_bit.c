#include "main.h"

/**
 * get_bit - returns the value of a bit at an index in a decimal number
 * @n: num to search
 * @index: index of a bit
 * Return: The value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int b;

	if (index > 63)
		return (-1);

	b = (n >> index) & 1;

	return (b);
}
