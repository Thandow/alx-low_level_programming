#include "main.h"
/**
 * flip_bits - counts the number of bits to alter
 * to get from one num to the other
 * @n: 1st number
 * @m: 2nd number
 * Return: number of bits to alter
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int a, c = 0;
	unsigned long int cur;
	unsigned long int exc = n ^ m;

	for (a = 63; a >= 0; a--)
	{
		cur = exc >> a;
		if (cur & 1)
			c++;
	}

	return (c);
}
