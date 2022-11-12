/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:58:26 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 14:22:12 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_ray	_ray_for_pixel(t_camera camera, double x_world, double y_world)
{
	t_point		pixel;
	t_point		origin;
	t_vector	direction;

	pixel = mul_matrix_tuple(
			camera.inverse_transform,
			create_point(x_world, y_world, -1));
	origin = mul_matrix_tuple(camera.inverse_transform, create_point(0, 0, 0));
	direction = normalize(sub_tuple(pixel, origin));
	return (create_ray(origin, direction));
}

t_ray	ray_for_pixel(t_camera camera, double x, double y)
{
	double	x_offset;
	double	y_offset;
	double	x_world;
	double	y_world;

	x_offset = (x + .5) * camera.pixel_size;
	y_offset = (y + .5) * camera.pixel_size;
	x_world = camera.half_width - x_offset;
	y_world = camera.half_height - y_offset;
	return (_ray_for_pixel(camera, x_world, y_world));
}
