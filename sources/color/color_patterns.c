/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_patterns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:36:57 by ralves-b          #+#    #+#             */
/*   Updated: 2022/11/11 14:44:20 by maolivei         ###   ########.fr       */
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

t_color	normalize_pixel(int color)
{
	int	r;
	int	g;
	int	b;

	r = 0xFF & color >> 16;
	g = 0xFF & color >> 8;
	b = 0xFF & color;
	return (create_formatted_color(r, g, b));
}

t_color	bump_at(t_point point, t_shape *shape)
{
	t_point	shape_point;
	size_t	x;
	size_t	y;
	t_uv	uv;

	shape_point = mul_matrix_tuple(shape->inverse_transform, point);
	uv = shape->uvmap(shape_point);
	x = floor(uv.u * (shape->material.pattern.width - 1));
	y = floor(uv.v * (shape->material.pattern.height - 1));
	return (normalize_pixel(pixel_at(shape->material.pattern, x, y)));
}

t_color	pattern_at(t_point point, t_shape *shape)
{
	t_point	shape_point;
	size_t	u;
	size_t	v;
	t_uv	uv;

	shape_point = mul_matrix_tuple(shape->inverse_transform, point);
	uv = shape->uvmap(shape_point);
	u = floor(uv.u * shape->material.pattern.width);
	v = floor(uv.v * shape->material.pattern.height);
	return (shape->material.pattern.colors[(u + v) % 2]);
}
