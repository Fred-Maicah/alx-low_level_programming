#include <stdio.h>
/**
 * main -  a program that prints all the alphabets in lowercase
 * excluding q and e
 *
 * Return: 0 (Success)
 */
int main(void)
{
char k;

k = 'a';
while
	(k <= 'z') {
		if ((k != 'q' && k != 'e') && k <= 'z')
			putchar(k);
		k++;
	}
putchar('\n');
return (0);
}
