/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mapping.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:05:20 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 14:22:12 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_uv	map_sphere(t_point point)
{
	double	phi;
	double	theta;
	double	radius;
	t_uv	uv;

	theta = atan2(point.x, point.z);
	radius = magnitude(create_vector(point.x, point.y, point.z));
	phi = acos(point.y / radius);
	uv.u = 1 - ((theta / (2 * M_PI)) + .5);
	uv.v = 1 - (phi / M_PI);
	return (uv);
}

t_uv	map_plane(t_point point)
{
	t_uv	uv;

	uv.u = fmod(point.x, 1);
	uv.v = fmod(point.z, 1);
	return (uv);
}

t_uv	map_cylinder(t_point point)
{
	double	theta;
	t_uv	uv;

	theta = atan2(point.x, point.z);
	uv.u = 1 - ((theta / (2 * M_PI)) + .5);
	uv.v = fmod(point.y, 1);
	return (uv);
}

t_uv	map_cone(t_point point)
{
	double	theta;
	double	radius;
	t_uv	uv;

	radius = (point.x * point.x) + (point.z * point.z);
	theta = atan2(point.x, point.z);
	uv.u = 1 - ((theta / (2 * M_PI)) + .5);
	uv.v = fmod(sqrt(radius), 1);
	return (uv);
}
