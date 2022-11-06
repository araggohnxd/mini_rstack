/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:55:37 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 18:56:00 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

t_camera	create_camera(double h_size, double v_size, double field_of_view)
{
	double		half_view;
	double		aspect_ratio;
	t_camera	camera;

	half_view = tan(field_of_view / 2);
	aspect_ratio = h_size / v_size;
	camera.half_width = half_view;
	camera.half_height = half_view / aspect_ratio;
	if (aspect_ratio < 1)
	{
		camera.half_width = half_view * aspect_ratio;
		camera.half_height = half_view;
	}
	camera.field_of_view = field_of_view;
	camera.h_size = h_size;
	camera.v_size = v_size;
	camera.pixel_size = (camera.half_width * 2) / h_size;
	camera.transformation = create_identity_matrix();
	camera.inverse_transformation = create_identity_matrix();
	return (camera);
}
