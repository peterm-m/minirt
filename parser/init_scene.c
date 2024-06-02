#include "minirt.h"

static int	(*g_f_fa[10])(char *) = {
	&fa_a,
	&fa_c,
	&fa_l,
	&fa_sp,
	&fa_pl,
	&fa_cy,
//	&fa_cb,
//	&fa_hb,
//	&fa_pb,
	NULL
};

ft_init_vars_type(char *type)
{
	const char	*door;

	door = ft_strnstr(OBJECT_TYPES, type, 2);
	if (!door)
		return (EXIT_FAILURE);
	if (type[TRUE])
		type += 2;
	type = ft_jump_spaces(type);
	return (g_f_fa[door - OBJECT_TYPES](type));
}
