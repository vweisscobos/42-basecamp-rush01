int		count_combs(int combs[24][4]);
int		is_row_locked(int i, int matriz[4][4]);
int		is_valid_row_view_count(int row, int comb[4], int *rules);
void	get_possibilities(int row, int pos, int matriz[4][4], int combs[24][4]);
void	reset_combs(int combs[24][4], int from);
void	set_row(int row, int comb[4], int matriz[4][4]);

void	filter_matches(int row, int combs[24][4], int *rules)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < 24)
	{	
		if (is_valid_row_view_count(row, combs[i], rules))
		{
			combs[counter][0] = combs[i][0];
			combs[counter][1] = combs[i][1];
			combs[counter][2] = combs[i][2];
			combs[counter][3] = combs[i][3];
			counter++;
		}
		i++;
	}
	reset_combs(combs, counter + 1);
}

void	get_valid_combs(int i, int matriz[4][4], int *rules, int combs[24][4])
{
	combs[0][0] = 1;
	combs[0][1] = 1;
	combs[0][2] = 1;
	combs[0][3] = 1;
	get_possibilities(i, 0, matriz, combs);
	filter_matches(i, combs, rules);
}

int	find_row_matches(int matriz[4][4], int *rules)
{
	int	i;
	int	combs[24][4];
	int	changed;

	changed = 0;
	reset_combs(combs, 0);
	i = 0;
	while (i < 4)
	{
		get_valid_combs(i, matriz, rules, combs);
		if (count_combs(combs) == 1 && !is_row_locked(i, matriz))
		{
			set_row(i, combs[0], matriz);
			changed = 1;
		}
		reset_combs(combs, 0);
		i++;
	}
	return (changed);
}
