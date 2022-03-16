#include <stdio.h>
#include "main.h"
/**
 * main - Entry point of program
 *
 * Return: always 0
 **/
int main(void)
{
	char words[9] = "_putchar";
	int i;

	for (i = 0; i < 9; i++)
	{
		_putchar(words[i]);
	}
	_putchar('\n');
	return (0);
}
