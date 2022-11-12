NAME				:= miniRT

HEADER_PATH			:= ./includes
HEADER_FILES		:= minirt.h internals.h errors.h

LIBS				:= ./libs
LIBFT_PATH			:= $(LIBS)/libft
LIBFT				:= $(LIBFT_PATH)/libft.a
MINILIBX_PATH		:= $(LIBS)/minilibx
MINILIBX			:= $(MINILIBX_PATH)/libmlx.a

SOURCE_DIRS			:= . parser mlx utils
SOURCE_DIRS			+= tuple color canvas matrix ray shape light world camera
SOURCE_PATH			:= $(addprefix ./sources/, $(SOURCE_DIRS))
SOURCE_FILES		:= main.c
SOURCE_FILES		+= tuple_constructors.c tuple_checkers.c tuple_operations.c
SOURCE_FILES		+= tuple_manipulators.c canvas_constructor.c canvas_destructor.c
SOURCE_FILES		+= write_to_canvas.c radians.c destructors.c setup.c hooks.c
SOURCE_FILES		+= color_constructors.c color_operations.c color_patterns.c
SOURCE_FILES		+= color_mapping.c matrix_constructors.c matrix_transformations.c
SOURCE_FILES		+= matrix_operations.c matrix_orientation.c matrix_checkers.c
SOURCE_FILES		+= matrix_view_transform.c intersection_list.c ray_constructor.c
SOURCE_FILES		+= ray_operations.c ray_for_pixel.c shape_constructors.c
SOURCE_FILES		+= shape_sphere.c shape_plane.c shape_cylinder.c shape_cone.c
SOURCE_FILES		+= shape_setters.c lighting.c is_shadowed.c light_constructors.c
SOURCE_FILES		+= world_constructor.c world_destructor.c world_operations.c
SOURCE_FILES		+= camera_constructor.c camera_setter.c render.c parser.c
SOURCE_FILES		+= parser_ambient.c parser_camera.c parser_error.c parser_shape.c
SOURCE_FILES		+= parser_sphere.c parser_plane.c parser_cylinder.c parser_cone.c
SOURCE_FILES		+= parser_light.c parser_checkers.c parser_pattern.c scene_to_world.c
SOURCE_FILES		+= line_tracker.c

OBJECT_PATH			:= ./objects
OBJECT_FILES		:= $(SOURCE_FILES:%.c=$(OBJECT_PATH)/%.o)

CC					:= cc
CFLAGS				:= -Wall -Wextra -Werror
IFLAGS				:= -I $(HEADER_PATH)
IFLAGS				+= -I $(LIBFT_PATH)/includes
IFLAGS				+= -I $(MINILIBX_PATH)/includes
LDFLAGS				:= -L $(LIBFT_PATH) -lft
LDFLAGS				+= -L $(MINILIBX_PATH) -lmlx -lXext -lX11 -lm
REMOVE				:= rm -rf
VALGRIND			:= valgrind
VGFLAGS				:= --leak-check=full --show-leak-kinds=all

ifdef DEBUG
	CFLAGS += -g3
else
	CFLAGS += -O3 -ffast-math
endif

vpath				%.c $(SOURCE_PATH)
vpath				%.h $(HEADER_PATH)

all:				$(NAME)

$(NAME):			$(OBJECT_FILES) $(LIBFT) $(MINILIBX)
					$(CC) $(CFLAGS) -o $@ $(OBJECT_FILES) $(LDFLAGS)

$(OBJECT_PATH)/%.o:	%.c $(HEADER_FILES) Makefile | $(OBJECT_PATH)
					$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJECT_PATH):
					mkdir -p $@

$(LIBFT):
					$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
					$(MAKE) -C $(MINILIBX_PATH)

clean:
					$(REMOVE) $(OBJECT_PATH)
					$(MAKE) -C $(LIBFT_PATH) clean
					$(MAKE) -C $(MINILIBX_PATH) clean

fclean:				clean
					$(REMOVE) $(NAME)
					$(MAKE) -C $(LIBFT_PATH) fclean

re:					fclean all

run:				all
					./$(NAME) $(argv)

vg:					all
					$(VALGRIND) $(VGFLAGS) ./$(NAME) $(argv)

.PHONY:				all clean fclean re run vg
