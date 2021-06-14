int	get_row_left_view_val(int *rules, int row);
int	get_row_right_view_val(int *rules, int row);
int	get_col_top_view_val(int *rules, int column);
int	get_col_bottom_view_val(int *rules, int column);

int	count_view(int comb[4])
{
	int	i;
	int	higher;
	int	count;

	count = 1;
	i = 1;
	higher = comb[0];
	while (i < 4)
	{
		if (comb[i] > higher)
		{
			higher = comb[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	rev_count_view(int comb[4])
{
	int	i;
	int	higher;
	int	count;

	count = 1;
	i = 2;
	higher = comb[3];
	while (i >= 0)
	{
		if (comb[i] > higher)
		{
			higher = comb[i];
			count++;
		}
		i--;
	}
	return (count);
}

int	is_valid_row_view_count(int row, int comb[4], int *rules)
{
	return (
		count_view(comb) == get_row_left_view_val(rules, row)
		&& rev_count_view(comb) == get_row_right_view_val(rules, row)
	);
}

int	is_valid_col_view_count(int col, int comb[4], int *rules)
{
	return (
		count_view(comb) == get_col_top_view_val(rules, col)
		&& rev_count_view(comb) == get_col_bottom_view_val(rules, col)
	);
}
