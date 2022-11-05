/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:21:03 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 13:29:49 by maolivei         ###   ########.fr       */
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

struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
};

typedef struct s_tuple	t_tuple;
typedef struct s_tuple	t_vector;
typedef struct s_tuple	t_point;

typedef struct s_canvas
{
	void	*mlx;
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endianness;
}	t_canvas;

#endif /* INTERNALS_H */
