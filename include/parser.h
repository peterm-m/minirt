#ifndef PARSER_H
# define PARSER_H

#define OBJECT_TYPES "A ,C ,L ,sp,pl,cy,cb,hb,pb"

int		ft_parser(t_scene *scene, int argc, char **argv);
char	*ft_jump_spaces(char *str);
int		ft_type_sellector(char *type);
int		ft_in_range_int(int min, int max, char **n);
float	ft_in_range_float(float min, float max, char **n);

int	fo_a(char *line_post_type);
int	fo_c(char *line_post_type);
int	fo_l(char *line_post_type);
int	fo_sp(char *line_post_type);
int	fo_pl(char *line_post_type);
int	fo_cy(char *line_post_type);

int	fa_a(char *line_post_type);
int	fa_c(char *line_post_type);
int	fa_l(char *line_post_type);
int	fa_sp(char *line_post_type);
int	fa_pl(char *line_post_type);
int	fa_cy(char *line_post_type);

#endif
