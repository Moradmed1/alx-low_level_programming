#include "main.h"
/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int dep;
	int arr;

	dep = 0;
	while (dest[dep] != '\0')
	{
		dep++;
	}
	arr = 0;
	while (src[arr] != '\0')
	{
		dest[dep] = src[arr];
		dep++;
		arr++;
	}

	dest[dep] = '\0';
	return (dest);
}
