NAME_RT			=	miniRT

INCLUDES_RT		=	includes/
HEADER_RT		=	includes/minirt.h

#LIBFT
DIR_LIB			=	libft/
LIBFT			=	$(DIR_LIB)libft.a

#include your directory name and files here
DIR_SRC			=	src/
FILES_SRC		=	main.c \
					print_structs.c \

SRCS_SRC		=	$(addprefix $(DIR_SRC), $(FILES_SRC))
OBJS_SRC		=	$(SRCS_SRC:%.c=%.o)

DIR_PARSE		=	parser/
FILES_PARSE		=	parser.c \
					utils_parser.c \
					init_parser.c \
					fill_obj.c \
					fill_scene.c \

SRCS_PARSE		=	$(addprefix $(DIR_PARSE), $(FILES_PARSE))
OBJS_PARSE		=	$(SRCS_PARSE:%.c=%.o)

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f

#MLX
MLX			= libmlx.a
MLX_PATH	= mlx_1/
MLX_FLAGS	= -lmlx -framework OpenGL -framework AppKit

.PHONY	:	all clean fclean re libft mlx norm

all		:	mlx libft $(NAME_RT)

mlx:
			@echo "Making $(MLX_PATH)$(MLX)"
			@make -C $(MLX_PATH)

libft	:
			@make -C $(DIR_LIB)

$(NAME_RT)	:	$(OBJS_PARSE) $(OBJS_SRC) #PLACE FOR ADDITIONAL OBJECTS IF ANY.
			$(CC) $(OBJS_PARSE) $(OBJS_SRC) $(LIBFT) $(MLX_FLAGS) -o $@

%.o	:	%.c $(LIBFT) $(HEADER_RT) $(MLX_PATH)$(MLX) Makefile
			$(CC) $(CFLAGS) -I $(INCLUDES_RT) -c $< -o $@

clean	:
			$(RM) $(OBJS_PARSE) $(OBJS_SRC) #PLACE FOR ADDITIONAL OBJECTS IF ANY.
			make -C $(DIR_LIB) clean
	
fclean	:	clean
			$(RM) $(NAME_RT)
			make -C $(DIR_LIB) fclean

re		:	fclean all

norm	:
			norminette includes
			norminette libft
			norminette parser
			norminette src
