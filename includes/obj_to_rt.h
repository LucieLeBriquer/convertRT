#ifndef OBJ_TO_RT_H
# define OBJ_TO_RT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h> 
# include <fcntl.h>
# include <math.h>
# include "libftfull.h"

# include <stdio.h>

typedef struct
{
	double	x;
	double	y;
	double	z;
}			t_vertex;

typedef struct
{
	int	v1;
	int	v2;
	int	v3;
}				t_face;

typedef struct
{
	int			nb_vertex;
	int			nb_face;
	t_vertex	*vertex;
	t_face		*face;
	char		*file;
	char		*file_rt;
}				t_format;

int		malloc_everything(t_format *obj);
int		fill_vertex_and_faces(t_format *obj);
int		to_vertex(const char *line, t_vertex *vertex);
int		to_face(const char *line, t_face *face);
int		create_obj(t_format obj);

#endif
