#include <stdio.h>
/**
 * is_palindrome - fuction that check if int is palidrome
 * @n: long int
 * Return: 1 or 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long  rev = 0, x, ntest;

	ntest = n;
	while (ntest != 0)
	{
		x = ntest % 10;
		rev = rev * 10 + x;
		ntest /= 10;
	}
	if (n == rev)
		return (1);
	return (0);
}
