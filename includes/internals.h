/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:21:03 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 15:51:40 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include <libft.h>
# include <mlx.h>
# include <math.h>

# define EPSILON .00001
# define VECTOR_W 0.
# define POINT_W 1.
# define MAT_MAX 4
# define MAT_SQR 16

struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
};

typedef struct s_tuple	t_tuple;
typedef struct s_tuple	t_vector;	/* w = 0 */
typedef struct s_tuple	t_point;	/* w = 1 */

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

typedef struct s_sphere
{
	double	diameter;
	t_point	center;
}	t_sphere;

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
}	t_shape;

typedef struct s_intersect
{
	t_shape				s;
	double				t;
	struct s_intersect	*next;
}	t_intersect;

typedef struct s_bhaskara
{
	double	a;
	double	b;
	double	c;
	double	delta;
}	t_bhaskara;

#endif /* INTERNALS_H */
