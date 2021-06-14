#include <unistd.h>

int		is_valid_coordinates(char *coordinates, int *rules);
void	rush(int matriz[4][4], int rules[16]);

int	main(int argc, char *argv[])
{
	int	matriz[4][4];
	int	rules[16];
	int	i;

	i = 0;
	while (i < 4)
	{
		matriz[i][0] = 0;
		matriz[i][1] = 0;
		matriz[i][2] = 0;
		matriz[i][3] = 0;
		i++;
	}
	if (argc != 2 || !(is_valid_coordinates(argv[1], rules)))
		write(1, "Error\n", 6);
	rush(matriz, rules);
	return (0);
}
