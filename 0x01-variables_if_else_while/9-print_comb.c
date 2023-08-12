#include <stdio.h>
/**
 * main - a program that prints all possible
 * combinations of single-digit numbers
 *
 * Return: 0 (Success)
 */
int main(void)
{
int k;

for (k = 0; k < 10; k++)
{
	putchar(k + '0');
	if (k < 9)
	{
		putchar(',');
		putchar(' ');
	}
}
putchar('\n');
return (0);
}
