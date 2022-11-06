/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:21:03 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 22:18:43 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include <libft.h>
# include <mlx.h>
# include <math.h>
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

# define RT_WIDTH 1366
# define RT_HEIGHT 768

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

typedef struct s_canvas
{
	void	*mlx;
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
	ID_SPHERE
}	t_shape_id;

typedef struct s_material
{
	t_color	color;
	t_color	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_material;

typedef struct s_sphere
{
	double	diameter;
	t_point	center;
}	t_sphere;

typedef struct s_intersect	t_intersect;

typedef struct s_shape
{
	t_shape_id	type;
	union
	{
		t_sphere	sphere;
	};
	t_vector	orientation;
	t_matrix	transformation;
	t_matrix	inverse_transformation;
	t_matrix	transposed_inverse;
	t_material	material;
	t_vector	(*get_normal)(struct s_shape *, t_point);
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
	t_matrix	transformation;
	t_matrix	inverse_transformation;
}	t_camera;

#endif /* INTERNALS_H */
