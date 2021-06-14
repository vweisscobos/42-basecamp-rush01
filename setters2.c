int	get_row_left_view_val(int *rules, int row);
int	get_row_right_view_val(int *rules, int row);
int	get_col_top_view_val(int *rules, int column);
int	get_col_bottom_view_val(int *rules, int column);

void	set_rows_first_numbers_limit(int row, int matriz[4][4], int *rules)
{
	int	i;

	i = 1;
	if (get_row_left_view_val(rules, row) == 4)
	{
		while (i <= 4)
		{
			matriz[row][i - 1] = i;
			i++;
		}
	}
	if (get_row_right_view_val(rules, row) == 4)
	{
		while (i <= 4)
		{
			matriz[row][4 - i] = i;
			i++;
		}
	}
}

void	set_cols_first_numbers_limit(int col, int matriz[4][4], int *rules)
{
	int	i;

	i = 1;
	if (get_col_top_view_val(rules, col) == 4)
	{
		while (i <= 4)
		{
			matriz[i - 1][col] = i;
			i++;
		}
	}
	if (get_col_bottom_view_val(rules, col) == 4)
	{
		while (i <= 4)
		{
			matriz[4 - i][col] = i;
			i++;
		}
	}
}
