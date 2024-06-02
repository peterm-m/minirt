#include "minirt.h"

static int	(*g_f_fo[10])(char *) = {
	&fo_a,
	&fo_c,
	&fo_l,
	&fo_sp,
	&fo_pl,
	&fo_cy,
//	&fo_cb,
//	&fo_hb,
//	&fo_pb,
	NULL
};

char	*ft_jump_spaces(char *str)
{
	while (*str && ft_isspace(*str))
		str++;
	return (str);
}

static int	ft_procese_flags(int ccase, int *a_flag, int *c_flag)
{
	if (!ccase)
	{
		if (a_flag)
			return (EXIT_FAILURE);
		else
			a_flag = TRUE;
	}
	else if (3 == ccase)
	{
		if (c_flag)
			return (EXIT_FAILURE);
		else
			c_flag = TRUE;
	}
	return (EXIT_SUCCESS);
}

int	ft_type_sellector(char *type)
{
	static int	a_flag = ZERO;
	static int	c_flag = ZERO;
	const char	*door;

	door = ft_strnstr(OBJECT_TYPES, type, 2);
	if (!door)
		return (EXIT_FAILURE);
	if (door - OBJECT_TYPES < 4)
		if (ftprocese_flags(door - OBJECT_TYPES, &a_flag, &c_flag))
			return (EXIT_FAILURE);
	if (type[TRUE])
		type += 2;
	type = ft_jump_spaces(type);
	return (g_f_fo[door - OBJECT_TYPES](type));
}
