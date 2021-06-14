void	reset_combs(int combs[24][4], int from)
{
	int	i;

	i = from;
	while (i < 24)
	{
		combs[i][0] = 0;
		combs[i][1] = 0;
		combs[i][2] = 0;
		combs[i][3] = 0;
		i++;
	}
}

void	push(int combs[24][4], int comb[4])
{
	int	i;

	i = 0;
	while (i < 24)
	{
		if (combs[i][0] == 0)
		{
			combs[i][0] = comb[0];
			combs[i][1] = comb[1];
			combs[i][2] = comb[2];
			combs[i][3] = comb[3];
			break ;
		}
		i++;
	}
}

int	count_combs(int combs[24][4])
{
	int	i;

	i = 0;
	while (combs[i][0] != 0)
		i++;
	return (i);
}
