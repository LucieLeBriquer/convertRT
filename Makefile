CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
NAME		= convertRT

INCS_DIR	= ./includes
INCS		= $(addprefix includes/, libftfull.h obj_to_rt.h)

LIBS		= librairies/libftfull.a -lm

SRCS		= sources/export.c \
			sources/main.c \
			sources/parse.c \
			sources/to_face.c \
			sources/to_vertex.c

OBJS		= $(SRCS:.c=.o)

%.o			: %.c
			@$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

all			: $(NAME)

$(NAME)		: $(OBJS) $(INCS)
			@$(CC) $(CFLAGS) -I$(INCS_DIR) $(OBJS) $(LIBS) -o $(NAME)

clean:
			@$(RM) $(OBJS)

fclean		: clean
			@$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
