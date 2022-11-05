/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:08:48 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 16:01:00 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

t_point	get_position(t_ray r, double t)
{
	return (sum_tuple(r.origin, scalar_multiply_tuple(r.direction, t)));
}

t_intersect	*get_hit(t_intersect *xs)
{
	while (xs)
	{
		if (xs->t > 0.)
			return (xs);
		xs = xs->next;
	}
	return (NULL);
}
