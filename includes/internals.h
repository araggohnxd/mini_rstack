/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:21:03 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 12:43:55 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include <libft.h>
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

#endif /* INTERNALS_H */
