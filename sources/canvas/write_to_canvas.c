/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_canvas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:24:38 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/11 15:21:37 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

int	ft_clamp(int x, int min, int max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

int	pixel_at(t_pattern pattern, int x, int y)
{
	char	*pixel;

	x = ft_clamp(x, 0, (pattern.width - 1));
	y = ft_clamp(y, 0, (pattern.height - 1));
	pixel = pattern.canvas.address;
	pixel += y * pattern.canvas.line_length;
	pixel += x * (pattern.canvas.bits_per_pixel / 8);
	return (*(unsigned int *)pixel);
}

void	write_to_canvas(t_canvas *canvas, int x, int y, int color)
{
	char	*pixel;
	int		index;

	pixel = canvas->address;
	pixel += (y * canvas->line_length) + (x * (canvas->bits_per_pixel / 8));
	index = canvas->bits_per_pixel - 8;
	while (index >= 0)
	{
		if (canvas->endianness == 0)
			*pixel++ = (color >> (canvas->bits_per_pixel - 8 - index)) & 0xFF;
		else
			*pixel++ = (color >> index) & 0xFF;
		index -= 8;
	}
}
