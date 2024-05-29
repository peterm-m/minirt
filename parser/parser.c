#include "minirt.h"

static int ft_init_vars(t_scene *scene, int fd)
{
	(void)scene;
	(void)fd;
}

static int ft_parse_file(int fd)
{
	(void)fd;
}

int ft_parser(t_scene *scene, int argc, char **argv)
{
	int fd;

	if (argc > 2)
		return (EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		return (EXIT_FAILURE);
	if (ft_parse_file(fd))
		return (EXIT_FAILURE);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (ft_init_vars(scene, fd))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}