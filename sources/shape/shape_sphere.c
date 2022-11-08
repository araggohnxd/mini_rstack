/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:32:25 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/08 17:34:14 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

static t_bhaskara	get_delta_value(t_ray ray, t_vector sphere_to_ray)
{
	t_bhaskara	_;

	_.a = dotp(ray.direction, ray.direction);
	_.b = dotp(ray.direction, sphere_to_ray) * 2;
	_.c = dotp(sphere_to_ray, sphere_to_ray) - 1;
	_.delta = (_.b * _.b) - (4 * _.a * _.c);
	return (_);
}

void	intersect_sphere(t_shape *sphere, t_ray ray, t_intersect **head)
{
	double		x[2];
	t_bhaskara	_;
	t_vector	sphere_to_ray;

	sphere_to_ray = sub_tuple(ray.origin, create_point(0, 0, 0));
	_ = get_delta_value(ray, sphere_to_ray);
	if (_.delta < 0)
		return ;
	x[0] = (-_.b - sqrt(_.delta)) / (2 * _.a);
	x[1] = (-_.b + sqrt(_.delta)) / (2 * _.a);
	intersection_sorted_insert(head, create_intersection(x[0], sphere));
	if (!is_equal_double(x[0], x[1]))
		intersection_sorted_insert(head, create_intersection(x[1], sphere));
}

t_vector	get_sphere_normal(t_shape *sphere, t_point point)
{
	t_vector	normal;

	normal = sub_tuple(point, create_point(0, 0, 0));
	normal.w = VECTOR_W;
	(void)sphere;
	return (normal);
}
