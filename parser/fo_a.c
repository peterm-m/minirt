#include "minirt.h"

int fo_a(char *line_post_type)
{
	if (ft_in_range_float(0.0, 1.0, line_post_type))
		return (EXIT_FAILURE);
	line_post_type = ft_jump_spaces(line_post_type);
	if (ft_in_range_int(0, 255, line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_int(0, 255, ++line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_int(0, 255, ++line_post_type))
		return (EXIT_FAILURE);
	line_post_type = ft_jump_spaces(line_post_type);
	if ('\n' != *line_post_type && line_post_type)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int fo_c(char *line_post_type)
{
	if (ft_in_range_float(__FLT_MIN__, __FLT_MAX__, line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_float(__FLT_MIN__, __FLT_MAX__, ++line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_float(__FLT_MIN__, __FLT_MAX__, ++line_post_type))
		return (EXIT_FAILURE);
	line_post_type = ft_jump_spaces(line_post_type);
	if (ft_in_range_float(-1.0, 1.0, line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_float(-1.0, 1.0, line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_float(-1.0, 1.0, line_post_type))
		return (EXIT_FAILURE);
	line_post_type = ft_jump_spaces(line_post_type);
	if (ft_in_range_int(0, 180, line_post_type))
		return (EXIT_FAILURE);
	line_post_type = ft_jump_spaces(line_post_type);
	if ('\n' != *line_post_type && line_post_type)
		return (EXIT_FAILURE);
}

int fo_l(char *line_post_type)
{
	if (ft_in_range_float(__FLT_MIN__, __FLT_MAX__, line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_float(__FLT_MIN__, __FLT_MAX__, ++line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_float(__FLT_MIN__, __FLT_MAX__, ++line_post_type))
		return (EXIT_FAILURE);
	line_post_type = ft_jump_spaces(line_post_type);
	if (ft_in_range_float(0.0, 1.0, line_post_type))
		return (EXIT_FAILURE);
	line_post_type = ft_jump_spaces(line_post_type);
	if (ft_in_range_int(0, 255, line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_int(0, 255, ++line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_int(0, 255, ++line_post_type))
		return (EXIT_FAILURE);
	line_post_type = ft_jump_spaces(line_post_type);
	if ('\n' != *line_post_type && line_post_type)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int fo_sp(char *line_post_type)
{
	if (ft_in_range_float(__FLT_MIN__, __FLT_MAX__, line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_float(__FLT_MIN__, __FLT_MAX__, ++line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_float(__FLT_MIN__, __FLT_MAX__, ++line_post_type))
		return (EXIT_FAILURE);
	line_post_type = ft_jump_spaces(line_post_type);
	if (ft_in_range_float(__FLT_MIN__, __FLT_MAX__, line_post_type))
		return (EXIT_FAILURE);
	line_post_type = ft_jump_spaces(line_post_type);
	if (ft_in_range_int(0, 255, line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_int(0, 255, ++line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_int(0, 255, ++line_post_type))
		return (EXIT_FAILURE);
	line_post_type = ft_jump_spaces(line_post_type);
	if ('\n' != *line_post_type && line_post_type)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int fo_pl(char *line_post_type)
{
	if (ft_in_range_float(__FLT_MIN__, __FLT_MAX__, line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_float(__FLT_MIN__, __FLT_MAX__, ++line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_float(__FLT_MIN__, __FLT_MAX__, ++line_post_type))
		return (EXIT_FAILURE);
	line_post_type = ft_jump_spaces(line_post_type);
	if (ft_in_range_float(-1.0, 1.0, line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_float(-1.0, 1.0, ++line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_float(-1.0, 1.0, ++line_post_type))
		return (EXIT_FAILURE);
	line_post_type = ft_jump_spaces(line_post_type);
	if (ft_in_range_int(0, 255, line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_int(0, 255, ++line_post_type))
		return (EXIT_FAILURE);
	if (',' != *line_post_type)
		return (EXIT_FAILURE);
	if (ft_in_range_int(0, 255, ++line_post_type))
		return (EXIT_FAILURE);
	line_post_type = ft_jump_spaces(line_post_type);
	if ('\n' != *line_post_type && line_post_type)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}