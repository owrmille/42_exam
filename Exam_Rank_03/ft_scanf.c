#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

int	ft_scanf(const char *format, ...)
{
	va_list		args;
	int			count;
	int			temp_int;
	char		temp_char;
	char		*temp_str;
	const char	*p;

	va_start(args, format);

	count = 0;
	p = format;
	while (*p)
	{
		if (*p == '%')
		{
			p++;
			if (*p == 'd')
			{
				int *int_ptr = va_arg(args, int *);
				int sign = 1;

				// Skip whitespace
				while (isspace(temp_char = getchar())) {}

				// Check for a sign
				if (temp_char == '-' || temp_char == '+')
				{
					sign = (temp_char == '-') ? -1 : 1;
					temp_char = getchar();
				}

				// Parse the integer
				if (!isdigit(temp_char))
					return (count);

				temp_int = 0;
				while (isdigit(temp_char))
				{
					temp_int = temp_int * 10 + (temp_char - '0');
					temp_char = getchar();
				}

				*int_ptr = temp_int * sign;
				count++;
			}
			else if (*p == 's')
			{
				char *str_ptr = va_arg(args, char *);

				// Skip whitespace
				while (isspace(temp_char = getchar())) {}

				// Read string
				int i = 0;
				while (temp_char != EOF && !isspace(temp_char))
				{
					str_ptr[i++] = temp_char;
					temp_char = getchar();
				}
				str_ptr[i] = '\0';
				count++;
			}
			else if (*p == 'c')
			{
				char *char_ptr = va_arg(args, char *);

				// Skip whitespace
				while (isspace(temp_char = getchar())) {}

				*char_ptr = temp_char;
				count++;
			}
		}
		p++; // Move to the next character in the format string
	}
	va_end(args);
	return (count);
}

int main() {
	int number;
	char str[100];
	char character;

	ft_scanf("%s %d %c", str, &number, &character);
	printf("String: %s\n", str);
	printf("Integer: %d\n", number);
	printf("Character: %c\n", character);
	return (0);
}
