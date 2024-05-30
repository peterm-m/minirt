#include "minirt.h"

char	*ft_jump_spaces(char *str)
{
	while (*str && ft_isspace(*str))
		str++;
	return (str);
}