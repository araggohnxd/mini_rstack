/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_destructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:24:04 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 13:24:28 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

void	destroy_canvas(t_canvas *canvas)
{
	mlx_destroy_image(canvas->mlx, canvas->image);
	mlx_destroy_display(canvas->mlx);
	free(canvas->mlx);
}
