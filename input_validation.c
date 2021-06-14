int	check_extremities(int *rules)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		if (i == 4)
		{
			i = 8;
			continue ;
		}
		if (rules[i] + rules[i + 4] > 4 + 1)
			return (0);
		i++;
	}
	return (1);
}

int	check_limit_values(int *rules)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (rules[i] < 1 || rules[i] > 4)
			return (0);
		i++;
	}
	return (1);
}

int	theres_forbidden_chars(char *coord)
{
	int	i;

	i = 0;
	while (coord[i] != '\0')
	{
		if (
			!(
				(coord[i] >= '1' && coord[i] <= '4') || coord[i] == ' '
			)
		)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_qtd_coordinates(char *coord, int *rules)
{
	int	i;
	int	qtd_coordinates;
	int	last_num;

	i = 0;
	last_num = 0;
	qtd_coordinates = 0;
	while (coord[i] != '\0')
	{
		if (coord[i] >= '1' && coord[i] <= '4' && last_num == 0)
		{
			rules[qtd_coordinates] = coord[i] - '0';
			qtd_coordinates++;
			last_num = coord[i] - '0';
		}
		else if (coord[i] == ' ')
			last_num = 0;
		else
			return (qtd_coordinates);
		i++;
	}
	return (qtd_coordinates);
}

int	is_valid_coordinates(char *coord, int rules[16])
{
	int	ck_qtd;

	if (theres_forbidden_chars(coord))
		return (0);
	ck_qtd = check_qtd_coordinates(coord, rules);
	if (ck_qtd != 16)
		return (0);
	if (
		!check_limit_values(rules)
		|| !check_extremities(rules)
	)
		return (0);
	return (1);
}
