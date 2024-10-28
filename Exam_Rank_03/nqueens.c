#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	print_solution(int *board, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		fprintf(stdout, "%d", board[i]);
		i++;
	}
	fprintf(stdout, "\n");
}

int	is_safe(int *board, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == board[col]
			|| board[i] - i == board[col] - col
			|| board[i] + i == board[col] + col)
			return (0);
		i++;
	}
	return (1);
}
void	nqueens(int n)
{
	int	i;
	int	col;
	int	*board;

	i = 0;
	col = 0;

	board = (int *)malloc(n * sizeof(int));
	if (!board)
		return ;
	while (i < n)
	{
		board[i] = -1;
		i++;
	}
	while (col >= 0)
	{
		board[col]++;
		if (board[col] >= n)
		{
			board[col] = -1;
			col--;
		}
		else if (is_safe(board, col))
		{
			if (col == n - 1)
			{
				print_solution(board, n);
			}
			else
			{
				col++;
				board[col] = -1;
			}
		}
	}
	if (board)
		free(board);
	board = NULL;
}

int	main(int argc, char **argv)
{
	int	n;

	if (argc != 2)
		return (1);
	n = atoi(argv[1]);
	nqueens(n);
	return (0);
}
