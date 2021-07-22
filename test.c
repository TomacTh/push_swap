# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>

#define string "string"

char	*ft_file_manager(char *arg)
{
	int		dict;
	int		i;
	char	c;
	char	*str;
	
	if (!(str = malloc(sizeof(char) * 4096)))
		return (NULL);
	dict = open(arg, O_WRONLY);
	if(dict == -1)
		return (NULL);
	i = 0;
	while (read(dict, &c, 1) > 0)
	{
		str[i] = c;
		i++;
	}
	if(read(dict, &c, 1) == -1)
		return (NULL);
	return (str);
}

void ft_print(char *str)
{

	printf("%s", str);
}

int main(void)
{	
	void *add = 0;
	
	ft_print(string);
	char *result = 	ft_file_manager("test.txt");
	printf("%s", string);
}
