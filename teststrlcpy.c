#include <stdio.h>
#include <string.h>

int	main(void)
{
	

	
	char haystack[] = "ef";

	char needle[] = "ex";
	
	char *result = strnstr(haystack, needle,1) ;
	printf("%s\n", result);
}
