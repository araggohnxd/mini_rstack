/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:19:36 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 13:41:21 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

static void	destroy_mlx(void *mlx)
{
	mlx_destroy_display(mlx);
	free(mlx);
}

int	create_canvas(t_canvas *c, double height, double width)
{
	c->mlx = mlx_init();
	if (!c->mlx)
		return (-1);
	c->image = mlx_new_image(c->mlx, (int)round(width), (int)round(height));
	if (!c->image)
		return (destroy_mlx(c->mlx), -1);
	c->address = mlx_get_data_addr(
			c->image,
			&c->bits_per_pixel,
			&c->line_length,
			&c->endianness);
	if (!c->address)
		return (mlx_destroy_image(c->mlx, c->image), destroy_mlx(c->mlx), -1);
	return (0);
}
