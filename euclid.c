#include <stdio.h>


int euclid(int m, int n)
{
	if(!n)
		return (m);
	return (euclid(n, m % n));
}

int main(void)
{
	printf("%i\n", euclid(32, 15));
}
