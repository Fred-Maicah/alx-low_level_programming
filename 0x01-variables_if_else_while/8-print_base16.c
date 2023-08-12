#include <stdio.h>
/**
 * main - program that prints all the numbers
 * of base 16 in lowercase
 *
 * Return: 0 (Success)
 */
int main(void)
{
char k;

int l;

k = 'a';
l = 0;
while
	(l < 10) {
		putchar(l + '0');
		l++;
	}
while
	(k <= 'f') {
		putchar(k);
		k++;
	}
putchar('\n');
return (0);
}
