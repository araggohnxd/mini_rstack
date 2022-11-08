/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:21:02 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/08 19:35:43 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

static t_bhaskara	get_delta_value(t_ray ray)
{
	t_bhaskara	_;

	_.a = pow(ray.direction.x, 2);
	_.a -= pow(ray.direction.y, 2);
	_.a += pow(ray.direction.z, 2);
	_.b = (2 * ray.origin.x * ray.direction.x);
	_.b -= (2 * ray.origin.y * ray.direction.y);
	_.b += (2 * ray.origin.z * ray.direction.z);
	_.c = pow(ray.origin.x, 2);
	_.c -= pow(ray.origin.y, 2);
	_.c += pow(ray.origin.z, 2);
	_.delta = (_.b * _.b) - (4 * _.a * _.c);
	return (_);
}

static t_bool	is_cap_within_radius(t_ray ray, double time, double radius)
{
	double	x;
	double	z;

	x = ray.origin.x + (time * ray.direction.x);
	z = ray.origin.z + (time * ray.direction.z);
	return (((x * x) + (z * z)) <= (radius * radius));
}

static void	intersect_caps(t_shape *cone, t_ray ray, t_intersect **head)
{
	double	time;

	if (!cone->cone.capped || is_equal_double(0, ray.direction.y))
		return ;
	time = (cone->cone.min - ray.origin.y) / ray.direction.y;
	if (is_cap_within_radius(ray, time, cone->cone.min))
		intersection_sorted_insert(head, create_intersection(time, cone));
	time = (cone->cone.max - ray.origin.y) / ray.direction.y;
	if (is_cap_within_radius(ray, time, cone->cone.max))
		intersection_sorted_insert(head, create_intersection(time, cone));
}

void	intersect_cone(t_shape *cone, t_ray ray, t_intersect **head)
{
	double		x[2];
	double		y[2];
	t_bhaskara	_;

	intersect_caps(cone, ray, head);
	_ = get_delta_value(ray);
	if (is_equal_double(0, _.a) && is_equal_double(0, _.b))
		return ;
	if (is_equal_double(0, _.a))
		return (intersection_sorted_insert(
				head, create_intersection((-_.c / (2 * _.b)), cone)));
	if (_.delta < 0)
		return ;
	x[0] = (-_.b - sqrt(_.delta)) / (2 * _.a);
	x[1] = (-_.b + sqrt(_.delta)) / (2 * _.a);
	y[0] = ray.origin.y + (x[0] * ray.direction.y);
	y[1] = ray.origin.y + (x[1] * ray.direction.y);
	if (cone->cone.min < y[0] && y[0] < cone->cone.max)
		intersection_sorted_insert(head, create_intersection(x[0], cone));
	if (!is_equal_double(x[0], x[1]))
		if (cone->cone.min < y[1] && y[1] < cone->cone.max)
			intersection_sorted_insert(head, create_intersection(x[1], cone));
}

t_vector	get_cone_normal(t_shape *cone, t_point point)
{
	double	distance;
	double	radius;
	double	y;

	distance = (point.x * point.x) + (point.z * point.z);
	radius = cone->cone.max * cone->cone.max;
	if (distance < radius && point.y >= (cone->cone.max - EPSILON))
		return (create_vector(0, 1, 0));
	radius = cone->cone.min * cone->cone.min;
	if (distance < radius && point.y <= (cone->cone.min + EPSILON))
		return (create_vector(0, -1, 0));
	y = sqrt(distance);
	if (point.y > 0)
		y = -y;
	return (create_vector(point.x, y, point.z));
}
