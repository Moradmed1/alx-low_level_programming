#include "main.h"

/**
* _strncat - concatenate two strings
* using at most n bytes from src
* @dest: destination  value
* @src: destination value
* @n: input value
*
* Return: dest
*/
char *_strncat(char *dest, char *src, int n)
{
int dep = 0;
int arr = 0;
int i;

for (i = 0 ; dest[i] != '\0' ; i++)
dep++;

for (i = 0 ; src[i] != '\0' ; i++)
arr++;

for (i = 0 ; i < n ; i++)
dest[dep + i] = src[i];

return (dest);
}

