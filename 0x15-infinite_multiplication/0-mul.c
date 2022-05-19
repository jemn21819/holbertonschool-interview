#include <stdio.h>
#include <stdlib.h>
#include "mult.h"
/**
 * isint - function to check if it is a number
 * @str: string
 * Return: 0 or i
 */
int isint(char *str)
{
	int i = 0, b = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i]  < '0' || str[i] > '9')
			b++;
	}
	return (b);
}

/**
 * infinite_multiplication - function to multiply 2 numbers
 * @num1: first number
 * @num2: second number
 * @len1: length
 * @len2: length
 * Return: str
 */
char *infinite_multiplication(char *num1, char *num2, int len1, int len2)
{
	char *res = NULL;
	int i, j, n;

	res = malloc(sizeof(char) * (len1 + len2));
	for (i = 0; i <  (len1 + len2); i++)
		res[i] = '0';
	for (i = len1 - 1; i >= 0; i--)
	{
		n = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			n += (num1[i] - '0') * (num2[j] - '0');
			n += res[i + j + 1] - '0';
			res[i + j + 1] = (n % 10) + '0';
			n /= 10;
		}
		if (n)
			res[i + j + 1] = (n % 10) + '0';
	}
	return (res);
}

/**
 * _print - function to print
 * @str: string
 */
void _print(char *str)
{
	int i = 0;

	while (*(str + i) != '\0')
	{
		_putchar(*(str + i));
		i++;
	}
	_putchar('\n');
}
/**
 * ifzeros - chek if zeros
 * @str: input to check
 * Return: 0 or 1
 */
int ifzeros(char *str)
{
	int i, b = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != '0')
			b++;
	}
	if (b != 0)
		return (0);
	return (1);
}
/**
 * main - main function
 * @argc: argument
 * @argv: argument
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *num1 = argv[1], *num2 = argv[2], *res = NULL;
	int len1 = 0, len2 = 0, b = 0, i = 0, res2;

	if (argc != 3 || isint(num1) || isint(num2))
	{
		_print("Error");
		exit(98);
	}
	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	res = infinite_multiplication(num1, num2, len1, len2);
	res2 = ifzeros(res);
	if (res2 == 0)
	{
		while (res[i] != '\0')
		{
			if (b == 0 && res[i] == '0')
				i++;
			else
			{
				b = 1;
				_putchar(*(res + i));
				i++;
			}
		}
		_putchar('\n');
	}
	else
	{
		_putchar('0');
		_putchar('\n');
	}
	free(res);
	return (0);
}
