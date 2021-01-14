#include "obj_to_rt.h"

static int	count_vertex(int fd, t_format *obj)
{
	char	*line;
	int		is_readable;

	is_readable = 0;
	obj->nb_vertex = 0;
	obj->nb_face = 0;
	while (get_next_line(fd, &line) > 0)
	{
		is_readable = 1;
		if (line[0] && line[0] == 'v' && line[1] && line[1] == ' ')
			obj->nb_vertex++;
		else if (line[0] && line[0] == 'f' && line[1] && line[1] == ' ')
			obj->nb_face++;
		free(line);
	}
	free(line);
	return (is_readable);
}

int			malloc_everything(t_format *obj)
{
	int	fd;

	fd = open(obj->file, O_RDONLY);
	if (fd < 0)
		return (-1);
	if (count_vertex(fd, obj) < 0)
		return (-1);
	obj->vertex = malloc(obj->nb_vertex * sizeof(t_vertex));
	if (!(obj->vertex))
		return (-2);
	obj->face = malloc(obj->nb_face * sizeof(t_face));
	if (!(obj->face))
	{
		free(obj->vertex);
		return (-2);
	}
	close(fd);
	return (0);
}

static int	fill_face(t_format *obj, char *line)
{
	static int	i;

	if (to_face(line, &((obj->face)[i])) < 0)
		return (-1);
	i++;
	return (0);
}

static int	fill_vertex(t_format *obj, const char *line)
{
	static int	i;

	if (to_vertex(line, &((obj->vertex)[i])) < 0)
		return (-1);
	i++;
	return (0);
}

int			fill_vertex_and_faces(t_format *obj)
{
	int		fd;
	char	*line;
	int		is_readable;

	fd = open(obj->file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'v' && line[1] == ' ' && fill_vertex(obj, line + 2) < 0)
		{
			free(line);
			return (-1); 
		}
		if (line[0] == 'f' && fill_face(obj, line + 2) < 0)
		{
			free(line);
			return (-1); 
		}
		free(line);
	}
	free(line);
	return (0);
}
