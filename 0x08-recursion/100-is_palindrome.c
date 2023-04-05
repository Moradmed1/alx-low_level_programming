#include "main.h"

/**
 * _strlen_recursion - Computes the length of a string recursively
 * @s: The string to be measured
 *
 * Return: The length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	else
	{
		return (1 + _strlen_recursion(s + 1));
	}
}

/**
 * pal_checker - Checks if a string is a palindrome recursively
 * @s: The string to be checked
 * @i: The index of the left character to be compared
 * @j: The index of the right character to be compared
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int pal_checker(char *s, int i, int j)
{
	if (i >= j)
	{
		return (1);
	}
	else if (s[i] != s[j])
	{
		return (0);
	}
	else
	{
		return (pal_checker(s, i + 1, j - 1));
	}
}

/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: The string to be checked
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = _strlen_recursion(s);

	if (len == 0 || len == 1)
	{
		return (1);
	}
	else
	{
		return (pal_checker(s, 0, len - 1));
	}
}
