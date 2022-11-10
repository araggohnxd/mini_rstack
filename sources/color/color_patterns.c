/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_patterns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:36:57 by ralves-b          #+#    #+#             */
/*   Updated: 2022/11/10 10:09:23 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

t_pattern	uv_checkers(double width, double height, t_color a, t_color b)
{
	t_pattern	checkers;

	checkers.colors[0] = a;
	checkers.colors[1] = b;
	checkers.width = width;
	checkers.height = height;
	return (checkers);
}

t_color	pattern_at(t_pattern pattern, t_point point, t_shape *shape)
{
	t_point	shape_point;
	size_t	u;
	size_t	v;
	t_uv	uv;

	shape_point = mul_matrix_tuple(shape->inverse_transform, point);
	uv = shape->uvmap(shape_point);
	u = floor(uv.u * pattern.width);
	v = floor(uv.v * pattern.height);
	return (pattern.colors[(u + v) % 2]);
}
