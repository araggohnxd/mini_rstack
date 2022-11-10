/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:21:03 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/10 10:15:06 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include <libft.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define EPSILON .00001
# define VECTOR_W 0.
# define POINT_W 1.
# define MAT_MAX 4
# define MAT_SQR 16
# ifndef M_PI
#  define M_PI 3.14159265358979323846	/* π */
# endif
# ifndef M_PI_2
#  define M_PI_2 1.57079632679489661923	/* π / 2 */
# endif

# define NAME "mini_rstack"
# define RT_WIDTH 1366
# define RT_HEIGHT 768

# define AMBIENT "A"
# define CAMERA "C"
# define LIGHT	"L"
# define SPHERE "sp"
# define PLANE	"pl"
# define CYLINDER "cy"
# define CONE "cn"
# define BLANKSPACES "\f\r\t\v"

typedef enum e_parse_id
{
	NONE,
	PARSE_AMBIENT,
	PARSE_CAMERA,
	PARSE_LIGHT,
	PARSE_SPHERE,
	PARSE_PLANE,
	PARSE_CYLINDER,
	PARSE_CONE
}	t_parse_id;

# define PARSE_ID_MIN PARSE_AMBIENT
# define PARSE_ID_MAX PARSE_CONE

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef t_tuple	t_vector;	/* w = 0 */
typedef t_tuple	t_point;	/* w = 1 */

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
	int		merged;
}	t_color;

typedef struct s_mlx
{
	void	*mlx;
}	t_mlx;

typedef struct s_canvas
{
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endianness;
}	t_canvas;

typedef struct s_matrix
{
	size_t	size;
	double	matrix[4][4];
}	t_matrix;

typedef struct s_ray
{
	t_point		origin;
	t_vector	direction;
}	t_ray;

typedef enum e_shape_id
{
	ID_SPHERE,
	ID_PLANE,
	ID_CYLINDER,
	ID_CONE
}	t_shape_id;

typedef struct s_uv
{
	double	u;
	double	v;
}	t_uv;

typedef struct s_pattern
{
	double		width;
	double		height;
	t_color		colors[2];
}	t_pattern;

typedef struct s_material
{
	t_color		color;
	t_color		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
	t_pattern	pattern;
	t_bool		has_pattern;
}	t_material;

typedef struct s_sphere
{
	double	diameter;
	t_point	center;
}	t_sphere;

typedef struct s_plane
{
	t_point	position;
}	t_plane;

typedef struct s_cylinder
{
	t_point	position;
	double	diameter;
	double	min;
	double	max;
	t_bool	capped;
}	t_cylinder;

typedef t_cylinder	t_cone;

typedef struct s_intersect	t_intersect;

typedef struct s_shape
{
	t_shape_id	type;
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
		t_cone		cone;
	};
	t_vector	orientation;
	t_matrix	transform;
	t_matrix	inverse_transform;
	t_matrix	inverse_transpose_transform;
	t_material	material;
	t_vector	(*normal_at)(struct s_shape *, t_point);
	t_uv		(*uvmap)(t_point);
	void		(*intersect)(struct s_shape *, t_ray, t_intersect **);
}	t_shape;

struct s_intersect
{
	t_shape				*s;
	double				t;
	struct s_intersect	*next;
};

typedef struct s_bhaskara
{
	double	a;
	double	b;
	double	c;
	double	delta;
}	t_bhaskara;

typedef struct s_light_point
{
	t_point	position;
	t_color	intensity;
}	t_lgt_point;

typedef struct s_position_attributes
{
	t_vector	camera;
	t_vector	normal;
	t_point		position;
}	t_pos_attr;

typedef struct s_light_attributes
{
	t_lgt_point	lp;
	t_shape		*shape;
	t_vector	camera;
	t_vector	normal;
	t_point		position;
	t_material	material;
	t_bool		in_shadow;
}	t_lgt_attr;

typedef struct s_world
{
	t_list	*lights;
	t_list	*shapes;
}	t_world;

typedef struct s_computations
{
	double		t;
	t_shape		*shape;
	t_point		point;
	t_point		overpoint;
	t_vector	normal;
	t_vector	camera;
}	t_comps;

typedef struct s_camera
{
	double		pixel_size;
	double		field_of_view;
	double		h_size;
	double		v_size;
	double		half_width;
	double		half_height;
	t_matrix	transform;
	t_matrix	inverse_transform;
}	t_camera;

typedef struct s_rt_ambient
{
	double	ratio;
	t_color	color;
}	t_rt_ambient;

typedef struct s_rt_camera
{
	t_point		view_point;
	t_vector	orientation;
	int			fov;
}	t_rt_camera;

typedef struct s_rt_scene
{
	t_rt_ambient	*ambient;
	t_rt_camera		*camera;
	t_list			*shapes;
	t_list			*lights;
	double			brightness;
}	t_rt_scene;

typedef struct s_minirt
{
	t_camera	camera;
	t_canvas	canvas;
	t_world		world;
	void		*window;
}	t_minirt;

typedef int	t_delegator(char **tokens, t_rt_scene *s);

#endif /* INTERNALS_H */
