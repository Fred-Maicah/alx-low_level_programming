#include <stdio.h>
/**
 * main - Prints the alphabet
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char s;

char t;

s = 'a';
t = 'A';
while
	(s <= 'z') {
		putchar(s);
			s++;
	}
while
	(t <= 'Z') {
		putchar(t);
			t++;
	}
putchar('\n');
return (0);
}
