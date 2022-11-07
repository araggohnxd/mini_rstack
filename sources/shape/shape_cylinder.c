/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:17:21 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/07 18:37:14 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

static t_bhaskara	get_delta_value(t_ray ray)
{
	t_bhaskara	_;

	_.a = pow(ray.direction.x, 2);
	_.a += pow(ray.direction.z, 2);
	_.b = 2 * ray.origin.x * ray.direction.x;
	_.b += 2 * ray.origin.z * ray.direction.z;
	_.c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1;
	_.delta = (_.b * _.b) - (4 * _.a * _.c);
	return (_);
}

static t_bool	is_cap_within_radius(t_ray ray, double time)
{
	double	x;
	double	z;

	x = ray.origin.x + (time * ray.direction.x);
	z = ray.origin.z + (time * ray.direction.z);
	return (((x * x) + (z * z)) <= 1);
}

static void	intersect_caps(t_shape *cyl, t_ray ray, t_intersect **head)
{
	double	time;

	if (!cyl->cylinder.capped || is_equal_double(0, ray.direction.y))
		return ;
	time = (cyl->cylinder.min - ray.origin.y) / ray.direction.y;
	if (is_cap_within_radius(ray, time))
		intersection_sorted_insert(head, create_intersection(time, cyl));
	time = (cyl->cylinder.max - ray.origin.y) / ray.direction.y;
	if (is_cap_within_radius(ray, time))
		intersection_sorted_insert(head, create_intersection(time, cyl));
}

void	intersect_cylinder(t_shape *cyl, t_ray ray, t_intersect **head)
{
	double		x[2];
	double		y[2];
	t_bhaskara	_;

	intersect_caps(cyl, ray, head);
	_ = get_delta_value(ray);
	if (is_equal_double(0, _.a))
		return ;
	if (_.delta < 0)
		return ;
	x[0] = (-_.b - sqrt(_.delta)) / (2 * _.a);
	x[1] = (-_.b + sqrt(_.delta)) / (2 * _.a);
	y[0] = ray.origin.y + (x[0] * ray.direction.y);
	y[1] = ray.origin.y + (x[1] * ray.direction.y);
	if (cyl->cylinder.min < y[0] && y[0] < cyl->cylinder.max)
		intersection_sorted_insert(head, create_intersection(x[0], cyl));
	if (!is_equal_double(x[0], x[1]))
		if (cyl->cylinder.min < y[1] && y[1] < cyl->cylinder.max)
			intersection_sorted_insert(head, create_intersection(x[1], cyl));
}

t_vector	get_cylinder_normal(t_shape *cyl, t_point point)
{
	double	distance;

	distance = (point.x * point.x) + (point.z * point.z);
	if (distance < 1 && point.y >= (cyl->cylinder.max - EPSILON))
		return (create_vector(0, 1, 0));
	if (distance < 1 && point.y <= (cyl->cylinder.min + EPSILON))
		return (create_vector(0, -1, 0));
	return (create_vector(point.x, 0, point.z));
}
