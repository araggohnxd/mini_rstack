NAME				:= mini_rstack

HEADER_PATH			:= ./includes
HEADER_FILES		:= mini_rstack.h internals.h

LIBS				:= ./libs
LIBFT_PATH			:= $(LIBS)/libft
LIBFT				:= $(LIBFT_PATH)/libft.a
MINILIBX_PATH		:= $(LIBS)/minilibx
MINILIBX			:= $(MINILIBX_PATH)/libmlx.a

SOURCE_DIRS			:= . parser mlx utils tuple color canvas matrix ray shape light world camera
SOURCE_PATH			:= $(addprefix ./sources/, $(SOURCE_DIRS))
SOURCE_FILES		:= main.c
SOURCE_FILES		+= tuple_constructors.c tuple_checkers.c tuple_operations.c
SOURCE_FILES		+= tuple_manipulators.c canvas_constructor.c canvas_destructor.c
SOURCE_FILES		+= write_to_canvas.c color_constructors.c color_operations.c
SOURCE_FILES		+= matrix_constructors.c matrix_checkers.c matrix_operations.c
SOURCE_FILES		+= matrix_transformations.c matrix_view_transform.c
SOURCE_FILES		+= intersection_list.c ray_constructor.c ray_operations.c
SOURCE_FILES		+= ray_for_pixel.c shape_constructors.c shape_setters.c
SOURCE_FILES		+= shape_sphere.c lighting.c is_shadowed.c light_constructors.c
SOURCE_FILES		+= world_constructor.c world_destructor.c world_operations.c
SOURCE_FILES		+= camera_constructor.c camera_setter.c render.c parser.c
SOURCE_FILES		+= parser_ambient.c parser_camera.c parser_error.c parser_shape.c
SOURCE_FILES		+= parser_light.c parser_checkers.c parser_sphere.c
SOURCE_FILES		+= scene_to_world.c radians.c destructors.c setup.c hooks.c

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
					./$(NAME)

vg:					all
					$(VALGRIND) $(VGFLAGS) ./$(NAME)

.PHONY:				all clean fclean re run vg
