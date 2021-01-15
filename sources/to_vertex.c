#include "obj_to_rt.h"

static int	skip(const char *line)
{
	int	i;

	i = 0;
	if (line[i] == '-')
		i++;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == '.')
		i++;
	while (ft_isdigit(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	return (i);
}

static int	size_of_int(int i)
{
	int	size;

	size = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / 10;
		size++;
	}
	return (size);
}

static int	conv_double(const char *line, double *f)
{
	int		entiere;
	int		floating;
	int		sign;
	int		size;

	floating = 0;
	entiere = ft_atoi(line);
	sign = 1;
	if (*line == '-' && line++)
		sign = -1;
	while (ft_isdigit(*line))
		line++;
	if (*line == '.' && line++)
		floating = ft_atoi(line);
	size = size_of_int(floating);
	while (*line == '0' && line++)
		size++;
	if (floating < 0)
		return (-1);
	*f = entiere + sign * (double)(floating) * pow(0.1, size);
	return (1);
}

int			to_vertex(const char *line, t_vertex *vertex)
{
	double	c;

	if (conv_double(line, &c) < 0)
		return (-1);
	line += skip(line);
	vertex->x = c;
	if (conv_double(line, &c) < 0)
		return (-1);
	line += skip(line);
	vertex->y = c;
	if (conv_double(line, &c) < 0)
		return (-1);
	vertex->z = c;
	return (1);
}
