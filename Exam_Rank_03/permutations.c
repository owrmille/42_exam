#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	print_solution(int *arr, int n, char *sorted_str)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = sorted_str[arr[i]];
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_safe(int *arr, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		if (arr[i] == arr[idx])
			return (0);
		i++;
	}
	return (1);
}

void	print_permutations(int n, char *sorted_str)
{
	int	i;
	int	idx;
	int	*arr;

	i = 0;
	idx = 0;
	arr = (int *)malloc(sizeof(int) * n);
	if (!arr)
		return ;
	while (i < n)
	{
		arr[i] = -1;
		i++;
	}
	while (idx >= 0)
	{
		arr[idx]++;
		if (arr[idx] >= n)
		{
			arr[idx] = -1;
			idx--;
		}
		else if (is_safe(arr, idx))
		{
			if (idx == n - 1)
			{
				print_solution(arr, n, sorted_str);
			}
			else
			{
				idx++;
				arr[idx] = -1;
			}
		}
	}
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
}

char	*sort_str(char *s)
{
	char	temp;
	int		i;

	i = 0;
	while (i < ft_strlen(s) - 1)
	{
		if (s[i] > s[i + 1])
		{
			temp = s[i];
			s[i] = s[i + 1];
			s[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (s);
}

int	main(int argc, char **argv)
{
	int		n;
	char	*sorted_str;

	if (argc != 2)
		return (1);
	sorted_str = sort_str(argv[1]);
	n = ft_strlen(sorted_str);
	print_permutations(n, sorted_str);
	return (0);
}
