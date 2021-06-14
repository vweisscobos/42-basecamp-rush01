int		get_row_left_view_val(int *rules, int row);
int		get_row_right_view_val(int *rules, int row);
int		get_col_top_view_val(int *rules, int column);
int		get_col_bottom_view_val(int *rules, int column);
void	set_rows_first_numbers_limit(int row, int matriz[4][4], int *rules);
void	set_cols_first_numbers_limit(int col, int matriz[4][4], int *rules);

void	set_rows_first_numbers(int row, int matriz[4][4], int *rules)
{
	if (get_row_left_view_val(rules, row) == 1)
	{
		matriz[row][0] = 4;
		if (get_row_right_view_val(rules, row) == 2)
			matriz[row][3] = 3;
	}
	if (get_row_right_view_val(rules, row) == 1)
	{
		matriz[row][3] = 4;
		if (get_row_left_view_val(rules, row) == 2)
			matriz[row][0] = 3;
	}
	set_rows_first_numbers_limit(row, matriz, rules);
}

void	set_cols_first_numbers(int col, int matriz[4][4], int *rules)
{
	if (get_col_top_view_val(rules, col) == 1)
	{
		matriz[0][col] = 4;
		if (get_col_bottom_view_val(rules, col) == 2)
			matriz[3][col] = 3;
	}
	if (get_col_bottom_view_val(rules, col) == 1)
	{
		matriz[3][col] = 4;
		if (get_col_top_view_val(rules, col) == 2)
			matriz[0][col] = 3;
	}
	set_cols_first_numbers_limit(col, matriz, rules);
}

void	set_row(int row, int comb[4], int matriz[4][4])
{
	matriz[row][0] = comb[0];
	matriz[row][1] = comb[1];
	matriz[row][2] = comb[2];
	matriz[row][3] = comb[3];
}

void	set_col(int col, int comb[4], int matriz[4][4])
{
	matriz[0][col] = comb[0];
	matriz[1][col] = comb[1];
	matriz[2][col] = comb[2];
	matriz[3][col] = comb[3];
}
