/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_constructors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:17:08 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 14:22:12 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	to_rgb(double color)
{
	int	_color;

	_color = (int)round(color * 255);
	if (_color > 255)
		return (255);
	if (_color < 0)
		return (0);
	return (_color);
}

static int	merge_colors(double r, double g, double b)
{
	return (to_rgb(r) << 16 | to_rgb(g) << 8 | to_rgb(b));
}

t_color	create_formatted_color(double r, double g, double b)
{
	return (create_color((r / 255), (g / 255), (b / 255)));
}

t_color	create_color(double r, double g, double b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.merged = merge_colors(r, g, b);
	return (color);
}
