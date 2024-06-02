#include "minirt.h"

static int ft_init_vars_line(t_scene *scene, char* line)
{
	line = ft_jump_spaces(line);
	if ('\n' == line[ZERO] || '\0' == line[ZERO])
		return (EXIT_SUCCESS);
	if (ft_init_vars_type(line))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int ft_init_vars(t_scene *scene, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (EXIT_FAILURE);
	while ( line )
	{
		if (ft_init_vars_line(scene, line))
			return (EXIT_FAILURE);
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}

static int	ft_parse_line(char *line)
{
	static int	am_lgh_flag = ZERO;
	static int	cam_flag = ZERO;

	line = ft_jump_spaces(line);
	if ('\n' == line[ZERO] || '\0' == line[ZERO])
		return (EXIT_SUCCESS);
	if (ft_type_sellector(line))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int ft_parse_file(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (EXIT_FAILURE);
	while ( line )
	{
		if (ft_parse_line(line))
			return (EXIT_FAILURE);
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}

int ft_parser(t_scene *scene, int argc, char **argv)
{
	int fd;

	if (argc > 2)
		return (EXIT_FAILURE);
	fd = open(argv[TRUE], O_RDONLY);
	if (fd < 3)
		return (EXIT_FAILURE);
	if (ft_parse_file(fd))
		return (close(fd), EXIT_FAILURE);
	close(fd);
	fd = open(argv[TRUE], O_RDONLY);
	if (ft_init_vars(scene, fd))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}