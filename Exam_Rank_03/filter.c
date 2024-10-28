#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

char	*read_input(void)
{
	int		n;
	int		cnt;
	char	*buf;

	n = 1;
	cnt = 0;
	buf = (char *)malloc(sizeof(char) * 1);
	if (!(buf))
		return (NULL);
	while (n > 0)
	{
		n = read(0, &buf[cnt], 1);
		if (n < 0)
		{
			free(buf);
			return (NULL);
		}
		if (n == 0)
			break ;
		cnt += n;
		buf = realloc(buf, cnt + 1);
	}
	buf[cnt] = '\0';
	return (buf);
}

void	change_substr(char *str, char *s)
{
	int	i;
	int	j;
	int	old_i;

	i = 0;
	j = 0;
	while (str[i])
	{
		old_i = i;
		while (s[j])
		{
			if (str[i] != s[j])
				break ;
			i++;
			j++;
		}
		if (j == (int)strlen(s))
			while (str[--i] && --j >= 0)
				str[i] = '*';
		j = 0;
		i = old_i + 1;
	}
}

int	main(int argc, char **argv)
{
	char	*s;
	char	*buf;

	buf = NULL;
	s = argv[1];
	if (argc != 2)
		return (1);
	buf = read_input();
	if (!buf)
	{
		perror("Error");
		return (1);
	}
	change_substr(buf, s);
	write(1, buf, strlen(buf));
	free(buf);
	return (0);
}
