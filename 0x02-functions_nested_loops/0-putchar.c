#include <stdio.h>
#include "_putchar.c"
/**
 * main - Entry point of program
 * Return: always 0
 **/
int main(void)
{
	char words[9] = "_puthchar";
	int i;

	for (i = 0; i < 9; i++)
	{
		_putchar(words[i]);
	}
	putchar(10);
	return (0);
}
