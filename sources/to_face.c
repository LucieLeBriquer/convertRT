#include "obj_to_rt.h"

static int	skip_vertex(const char *line)
{
	int	i;

	i = 0;
	while (ft_isdigit(line[i]) || line[i] == '/')
		i++;
	return (i);
}

static int	ft_atoi_pos(const char *line)
{
	int	res;

	res = 0;
	while (ft_isdigit(*line))
	{
		res = 10 * res + (*line - '0');
		line++;
	}
	return (res);
}

int			to_face(const char *line, t_face *face)
{
	int	i;

	i = ft_atoi_pos(line);
	face->v1 = i - 1;
	line += skip_vertex(line);
	if (*line != ' ')
		return (-1);
	line++;
	i = ft_atoi_pos(line);
	face->v2 = i - 1;
	line += skip_vertex(line);
	if (*line != ' ')
		return (-1);
	line++;
	i = ft_atoi_pos(line);
	face->v3 = i - 1;
	return (1);
}
