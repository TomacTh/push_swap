#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void  swap(int *a, int *b)
{
	int copy;

	copy = *a;
	*a = *b;
	*b = copy;
}

int	select_sort(int *tab, int len)
{
	int i;
	int curr;
	int min;
	
	curr = 0;
	while(curr < len - 1)
	{
		min = curr;
		i = curr + 1;
		while(i < len)
		{
			if (tab[i] < tab[min])
				min = i;
			i++;
		}
		if(min != curr)
			swap(&tab[curr], &tab[min]);
		curr++;
	}
	return (0);
}

int bubble_sort(int *tab, int len)
{
	int i;
	int y;
	int bol;

	i = 0;
	while(i < len - 1)
	{
			y = 0;
			bol = 1;
			while(y < len - 1 - i)
			{
				if(tab[y] > tab[y + 1])
				{
					swap(&tab[y], &tab[y + 1]);
					bol = 0;
				}
				y++;
			}
			if(bol)
				return (0);
			i++;
	}
	return (0);
}

int	insert_sort(int *tab, int len)
{
	int curr;
	int i;
	int swap;

	curr = 1;
	while(curr < len)
	{
		i = curr - 1;
		if(tab[curr] < tab[i])
		{
			swap = tab[curr];
			while(i >= 0 && swap < tab[i])
			{	
				tab[i + 1] = tab[i];
				i--;
			}
			tab[i] = swap;
			curr++;
		}
	}
	return (0);
}

int main(void)
{
	int tab[] = {58, 3, 27, 69, 1, 2};
	int len = 6;
	bubble_sort(tab, len);
	int i = 0;
	while(i < len)
	{	
		printf("%i\n", tab[i]);
		i++;
	}
}
