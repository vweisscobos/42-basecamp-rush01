int	get_row_left_view_val(int *rules, int row)
{	
	return (rules[8 + row]);
}

int	get_row_right_view_val(int *rules, int row)
{	
	return (rules[12 + row]);
}

int	get_col_top_view_val(int *rules, int column)
{
	return (rules[0 + column]);
}

int	get_col_bottom_view_val(int *rules, int column)
{
	return (rules[4 + column]);
}
