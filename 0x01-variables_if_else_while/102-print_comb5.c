#include <stdio.h>
/**
 * main -  a program that prints all the alphabets in lowercase
 * excluding q and e
 *
 * Return: 0 (Success)
 */
int main(void)
{
int k;
int r;

for (k = 0; k < 100; k++)
{
	for (r = 0; r < 100; r++)
	{
		if (k < r)
		{
			putchar((k / 10) + 48);
			putchar((k % 10) + 48);
			putchar(' ');
			putchar((r / 10) + 48);
			putchar((r % 10) + 48);
			if (k != 98 || r != 99)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
}
putchar('\n');
return (0);
}
