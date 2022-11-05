/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:15:28 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 16:17:01 by maolivei         ###   ########.fr       */
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

t_color	multiply_color(t_color a, t_color b)
{
	return (create_color(
			(a.r * b.r),
			(a.g * b.g),
			(a.b * b.b))
	);
}

t_color	scalar_multiply_color(t_color a, double multiplier)
{
	return (create_color(
			(a.r * multiplier),
			(a.g * multiplier),
			(a.b * multiplier))
	);
}
