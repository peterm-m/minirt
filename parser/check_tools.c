#include "minirt.h"

int	ft_in_range_int(int min, int max, char **n)
{
	int	num;
	int	i;

	if (*n == NULL || **n == '\0') 
		return (EXIT_FAILURE);
	i = 0;
	if (*n[0] == '-' || *n[0] == '+')
		i = 1;
	while (*n[i]) /// este bucle no vale
	{
		if (!isdigit(*n[i]))
			return (EXIT_FAILURE);
		i++;
	}
	num = atoi(*n);
	if (num < INT_MIN || num > INT_MAX)
		return (EXIT_FAILURE);
	*n = *n + i;
	if (num >= min && num <= max)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

float	ft_in_range_float(float min, float max, char **n)
{
	lomismoquearribaperoconfloats();//
}
