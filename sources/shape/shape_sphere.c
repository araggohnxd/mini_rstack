/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:32:25 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 18:48:16 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

static t_bhaskara	get_delta_value(t_ray r, t_vector sphere_to_ray)
{
	t_bhaskara	_;

	_.a = dot_product(r.direction, r.direction);
	_.b = dot_product(r.direction, sphere_to_ray) * 2;
	_.c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	_.delta = (_.b * _.b) - (4 * _.a * _.c);
	return (_);
}

void	intersect_sphere(t_shape *s, t_ray r, t_intersect **head)
{
	double		x[2];
	t_bhaskara	_;
	t_vector	sphere_to_ray;

	sphere_to_ray = sub_tuple(r.origin, create_point(0, 0, 0));
	_ = get_delta_value(r, sphere_to_ray);
	if (_.delta < 0)
		return ;
	x[0] = (-_.b - sqrt(_.delta)) / (2 * _.a);
	x[1] = (-_.b + sqrt(_.delta)) / (2 * _.a);
	intersection_sorted_insert(head, create_intersection(x[0], s));
	if (!is_equal_double(x[0], x[1]))
		intersection_sorted_insert(head, create_intersection(x[1], s));
}

t_vector	get_sphere_normal(t_shape *s, t_point p)
{
	t_vector	normal;

	normal = sub_tuple(p, create_point(0, 0, 0));
	normal.w = VECTOR_W;
	(void)s;
	return (normal);
}
