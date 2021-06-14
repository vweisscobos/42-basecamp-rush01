int		is_num_locked(int i, int j, int matriz[4][4]);
int		are_nums_unique(int comb[4]);
void	push(int combs[24][4], int comb[4]);

int	match_row_locked(int row, int comb[4], int mtx[4][4])
{
	int	i;
	int	j;
	int	match;

	match = 1;
	i = 0;
	while (i < 4 && match == 1)
	{
		j = 0;
		if (is_num_locked(row, i, mtx) && comb[i] != mtx[row][i])
			match = 0;
		while (j < 4)
		{
			if (j != row && is_num_locked(j, i, mtx) && comb[i] == mtx[j][i])
			{
				match = 0;
			}
			j++;
		}
		i++;
	}
	return (match);
}

int	is_valid_row_comb(int i, int comb[4], int matriz[4][4])
{
	if (
		comb[0] + comb[1] + comb[2] + comb[3] == 10
		&& are_nums_unique(comb)
		&& match_row_locked(i, comb, matriz)
	)
		return (1);
	else
		return (0);
}

void	get_possibilities(
	int row,
	int pos,
	int matriz[4][4],
	int combs[24][4]
)
{
	while (combs[0][pos] <= 4)
	{
		if (pos < 3)
		{
			get_possibilities(row, pos + 1, matriz, combs);
			combs[0][pos + 1] = 0;
		}
		else if (is_valid_row_comb(row, combs[0], matriz))
			push(combs, combs[0]);
		combs[0][pos] = combs[0][pos] + 1;
	}
}
