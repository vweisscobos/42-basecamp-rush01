void	get_col(int i, int col[4], int matriz[4][4]);
void	get_row(int i, int row[4], int matriz[4][4]);
int		is_valid_col_view_count(int col, int comb[4], int *rules);
int		is_valid_row_view_count(int row, int comb[4], int *rules);

int	is_num_locked(int i, int j, int matriz[4][4])
{
	if (matriz[i][j] != 0)
		return (1);
	else
		return (0);
}

int	is_row_locked(int i, int matriz[4][4])
{
	if (
		matriz[i][0] != 0
		&& matriz[i][1] != 0
		&& matriz[i][2] != 0
		&& matriz[i][3] != 0
	)
		return (1);
	else
		return (0);
}

int	is_comb_sum_valid(int comb[4])
{
	if (comb[0] + comb[1] + comb[2] + comb[3] == 10)
		return (1);
	return (0);
}

int	are_nums_unique(int comb[4])
{
	if (
		comb[0] != comb[1]
		&& comb[0] != comb[2]
		&& comb[0] != comb[3]
		&& comb[1] != comb[2]
		&& comb[1] != comb[3]
		&& comb[2] != comb[3]
	)
		return (1);
	else
		return (0);
}

int	check_matriz(int matriz[4][4], int *rules)
{
	int	i;
	int	check;
	int	col[4];
	int	row[4];

	check = 1;
	i = 0;
	while (i < 4 && check == 1)
	{
		get_col(i, col, matriz);
		get_row(i, row, matriz);
		if (!is_comb_sum_valid(row))
			check = 0;
		if (!is_comb_sum_valid(col))
			check = 0;
		if (!is_valid_col_view_count(i, col, rules))
			check = 0;
		if (!is_valid_row_view_count(i, row, rules))
			check = 0;
		i++;
	}
	return (check);
}
