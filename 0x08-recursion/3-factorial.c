/**
* factorial - Returns the factorial of a given number
* @n: Number to calculate the factorial for
*
* Return: The factorial of n, or -1 if n is less than 0
*/
int factorial(int n)
{
if (n < 0)
return (-1);
else if (n == 0)
return (1);
else
return (n * factorial(n - 1));
}
