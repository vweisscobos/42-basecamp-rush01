#include <unistd.h>

int	is_comb_sum_valid(int comb[4]);

void	get_col(int i, int col[4], int matriz[4][4])
{
	col[0] = matriz[0][i];
	col[1] = matriz[1][i];
	col[2] = matriz[2][i];
	col[3] = matriz[3][i];
}

void	get_row(int i, int row[4], int matriz[4][4])
{
	row[0] = matriz[i][0];
	row[1] = matriz[i][1];
	row[2] = matriz[i][2];
	row[3] = matriz[i][3];
}

void	reset_row(int i, int matriz[4][4])
{
	matriz[i][0] = 0;
	matriz[i][1] = 0;
	matriz[i][2] = 0;
	matriz[i][3] = 0;
}

void	print_matriz(int matriz[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = matriz[i][j] + '0';
			write(1, &c, 1);
			j++;
		}
		c = '\n';
		write(1, &c, 1);
		i++;
	}
}

void	print_str(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != 0)
	{
		c = str[i];
		write(1, &c, 1);
		i++;
	}
}
