/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_patterns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:36:57 by ralves-b          #+#    #+#             */
/*   Updated: 2022/11/08 18:04:39 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

t_pattern	create_pattern(t_color a, t_color b)
{
	t_pattern	pattern;

	pattern.color_a = a;
	pattern.color_b = b;
	pattern.transform = create_identity_matrix();
	pattern.inverse_transform = create_identity_matrix();
	return (pattern);
}

t_color	pattern_at(t_pattern pattern, t_point point)
{
	if ((int)(floor(point.x) + floor(point.y) + floor(point.z)) % 2)
		return (pattern.color_b);
	return (pattern.color_a);
}

t_color	get_pattern(t_pattern pattern, t_point point, t_shape *shape)
{
	t_point	shape_point;
	t_point	pattern_point;

	shape_point = mul_matrix_tuple(
			shape->inverse_transform, point);
	pattern_point = mul_matrix_tuple(
			pattern.inverse_transform, shape_point);
	return (pattern_at(pattern, pattern_point));
}

void	set_pattern_transformation(t_pattern *pattern, t_matrix transform)
{
	pattern->transform = transform;
	pattern->inverse_transform = inverse_matrix(transform);
}
