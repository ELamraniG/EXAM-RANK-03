//Allowed functions: puts, malloc, calloc, realloc, free, write
#include <stdio.h>
#include <unistd.h>

void swap(char *c, char *b)
{
	char tmp = *c;
	*c = *b;
	*b = tmp;
}

void ft_sort(char *str)
{
	int i = 0;
	int j = 0;
	while(str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] > str[j])
				swap(str + j, str + i);
			j++;
		}
		i++;
	}
}

void ft_permutations(char *str, int pos,int size)
{
	if (pos == size)
		puts(str);
	for (int i = pos; i < size; i++)
	{
		ft_sort(str + pos);
		swap(str + i, str + pos);
		ft_permutations(str,pos + 1, size);
		swap(str + i, str + pos);
	}
}

int main(int ac,char **av)
{
	if (ac != 2 || !av[1][0])
		return (0);
	int size= 0;
	while (av[1][size])
		size++;
	ft_permutations(av[1], 0,size);
}
