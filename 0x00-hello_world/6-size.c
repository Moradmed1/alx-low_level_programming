#include <stdio.h>
/**
* main - A program that print the size of various camputer types
* Return: 0 (success)
*/
int main(void)
        char a;
	int b;
	long int c;
	long long int d;
	float f;
	
printf("size of a char: %lu byte(s)\n", (unsigned long)siseof(a));
printf("size of a int:% lu byte(s)\n", (unsigned long)siseof(b));
printf("size of a long int: %lu byte(s)\n", (unsigned long)siseof(c));
printf("size of a long long int: %lu byte(s)\n", (unsigned long)siseof(d));
printf("size of a float: %lu byte(s)\n", (unsigned long)siseof(f));
return (0);
}
