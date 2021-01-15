#include "obj_to_rt.h"

static int	print_error(int err, int step)
{
	if (step == 0)
		printf("Error : wrong number of arguments\n");
	else if (step == 1)
	{
		if (err == -1)
			printf("Error : file unreadable\n");
		else
			printf("Error : allocation's issues\n");
	}
	else if (step == 2) 
		printf("Error : wront format\n");
	else 
		printf("Error : can't write on file\n");
	return (-1);
}

static void	free_all(t_format obj)
{
	free(obj.vertex);
	free(obj.face);
}

int			main(int argc, char **argv)
{
	t_format	obj;
	int			err;

	obj.file_rt = "export.rt";
	if (argc != 2)
		return (print_error(0, 0));
	obj.file = argv[1];
	err = malloc_everything(&obj);
	if (err < 0)
		return (print_error(err, 1));
	if (fill_vertex_and_faces(&obj) < 0)
		return (print_error(0, 2));
	if (create_obj(obj) < 0)
		return (print_error(0, 3));
	free_all(obj);
	return (0);
}
