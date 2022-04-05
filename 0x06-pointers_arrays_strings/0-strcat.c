#include "main.h"
/**
 * _strcat - concatenates the source and dest strings
 * @dest: the destination string
 * @src: the source string
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int destlen = strlen(dest);
	int srclen = strlen(src);
	int i;

	for (i = 0; i <= srclen; i++)
	{
		dest[destlen + i] = src[i];
	}
	return (dest);
}
