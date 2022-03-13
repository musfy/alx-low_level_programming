#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - program starts here
 * Return: always 0
 **/
int main(void)
{
	int n;
	int last_digit_of_n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	last_digit_of_n = n % 10;
	printf("Last digit of ");
	printf("%d ", n);
	printf("is ");
	printf("%d ", last_digit_of_n);
	if (last_digit_of_n > 5)
	{
		printf("and is greater than 5");
	}
	else if (last_digit_of_n == 0)
	{
		printf("and is 0");
	}
	else
		printf("and is less than 6 and not 0\n");
	return (0);
}
