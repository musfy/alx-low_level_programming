#include <stdio.h>
/**
 * main - entry point
 * Return: always 0
 **/
int main(void)
{
	int ch;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		putchar(ch);
	}
	for (ch = 'A'; ch <= 'Z'; ch++)
	{
		putchar(ch);
	}
	putchar(10);
	return (0);
}
