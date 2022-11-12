/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:01:32 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 14:22:12 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	render(t_canvas *canvas, t_camera camera, t_world world)
{
	size_t		x;
	size_t		y;
	t_ray		ray;
	t_color		color;

	if (create_canvas(canvas, camera.h_size, camera.v_size) != 0)
		return (-1);
	y = 0;
	while (y < (camera.v_size - 1))
	{
		x = 0;
		while (x < (camera.h_size - 1))
		{
			ray = ray_for_pixel(camera, x, y);
			color = color_at(world, ray);
			write_to_canvas(canvas, x, y, color.merged);
			++x;
		}
		++y;
	}
	return (0);
}
