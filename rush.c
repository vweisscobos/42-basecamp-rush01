void	set_rows_first_numbers(int row, int matriz[4][4], int *rules);
void	get_valid_combs(int i, int matriz[4][4], int *rules, int combs[24][4]);
int		count_combs(int combs[24][4]);
void	set_row(int row, int comb[4], int matriz[4][4]);
void	reset_combs(int combs[24][4], int from);
void	set_cols_first_numbers(int col, int matriz[4][4], int *rules);
int		check_matriz(int matriz[4][4], int *rules);
void	reset_row(int i, int matriz[4][4]);
void	print_matriz(int matriz[4][4]);
void	print_str(char *str);

void	set_first_numbers(int matriz[4][4], int *rules)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		set_rows_first_numbers(i, matriz, rules);
		set_cols_first_numbers(i, matriz, rules);
		i++;
	}	
}

void	iterate_combinations(int row, int matriz[4][4], int *rules)
{	
	int	i;
	int	j;
	int	combs[24][4];

	reset_combs(combs, 0);
	get_valid_combs(row, matriz, rules, combs);
	i = 0;
	while (!check_matriz(matriz, rules) && i < count_combs(combs))
	{
		j = row + 1;
		set_row(row, combs[i], matriz);
		if (row < 3)
		{
			while (j < 4)
			{
				reset_row(j, matriz);
				j++;
			}
			iterate_combinations(row + 1, matriz, rules);
		}
		i++;
	}
}

void	rush (int matriz[4][4], int rules[16])
{
	set_first_numbers(matriz, rules);
	iterate_combinations(0, matriz, rules);
	if (check_matriz(matriz, rules))
		print_matriz(matriz);
	else
		print_str("Error\n");
}
