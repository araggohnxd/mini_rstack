/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:19:36 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 16:05:53 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	create_canvas(t_canvas *c, double width, double height)
{
	c->image = mlx_new_image(
			get_mlx()->mlx,
			(int)round(width),
			(int)round(height));
	if (!c->image)
		return (error(ERR_MLX_IMAGE));
	c->address = mlx_get_data_addr(
			c->image,
			&c->bits_per_pixel,
			&c->line_length,
			&c->endianness);
	if (!c->address)
	{
		mlx_destroy_image(get_mlx()->mlx, c->image);
		return (error(ERR_MLX_IMAGE_DATA));
	}
	return (0);
}
