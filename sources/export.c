#include "obj_to_rt.h"

static void	write_header(int fd)
{
	write(fd, "R 400 400\n", 10);
	write(fd, "c 0,0,30 0,0,-1 53\n", 19);
	write(fd, "l 0,0,31 0.15 255,255,255\n", 26);
}

static void	write_double(int fd, double f)
{
	int		entiere;
	int		floating;
	char	*str1;
	char	*str2;

	entiere = (int)floor(f);
	floating = (int)floor((f - entiere) * pow(10, 6));
	str1 = ft_itoa(entiere);
	str2 = ft_itoa(floating);
	write(fd, str1, ft_strlen(str1));
	write(fd, ".", 1);
	write(fd, str2, ft_strlen(str2));
}

static void	write_vertex(int fd, t_vertex vertex)
{
	write_double(fd, vertex.x);
	write(fd, ",", 1);
	write_double(fd, vertex.y);
	write(fd, ",", 1);
	write_double(fd, vertex.z);
	write(fd, " ", 1);
}

static void	write_triangle(int fd, t_format obj, int i)
{
	write(fd, "tr ", 3);
	write_vertex(fd, (obj.vertex)[(obj.face)[i].v1]);
	write_vertex(fd, (obj.vertex)[(obj.face)[i].v2]);
	write_vertex(fd, (obj.vertex)[(obj.face)[i].v3]);
	write(fd, "255,255,255\n", 12);
}

int		create_obj(t_format obj)
{
	int	fd;	
	int	i;
	
	fd = open(obj.file_rt, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd <= 0)
		return (-1);
	write_header(fd);
	i = -1;
	while (++i < obj.nb_face)
		write_triangle(fd, obj, i);
	return (close(fd));
}
