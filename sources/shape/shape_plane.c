/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:14:05 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/06 17:14:46 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

void	intersect_plane(t_shape *plane, t_ray ray, t_intersect **head)
{
	double	time;

	if (is_equal_double(0, ray.direction.y))
		return ;
	time = -ray.origin.y / ray.direction.y;
	intersection_sorted_insert(head, create_intersection(time, plane));
}

t_vector	get_plane_normal(t_shape *plane, t_point point)
{
	(void)plane;
	(void)point;
	return (create_vector(0, 1, 0));
}
