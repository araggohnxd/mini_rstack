/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:15:28 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/08 17:36:10 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

t_color	sum_color(t_color a, t_color b)
{
	return (create_color(
			(a.r + b.r),
			(a.g + b.g),
			(a.b + b.b))
	);
}

t_color	sub_color(t_color a, t_color b)
{
	return (create_color(
			(a.r - b.r),
			(a.g - b.g),
			(a.b - b.b))
	);
}

t_color	mul_color(t_color a, t_color b)
{
	return (create_color(
			(a.r * b.r),
			(a.g * b.g),
			(a.b * b.b))
	);
}

t_color	smul_color(t_color a, double m)
{
	return (create_color(
			(a.r * m),
			(a.g * m),
			(a.b * m))
	);
}
