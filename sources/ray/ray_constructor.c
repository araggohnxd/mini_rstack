/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_constructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:08:48 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 16:03:50 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

t_ray	create_ray(t_point origin, t_vector direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_ray	transform_ray(t_ray r, t_matrix m)
{
	return (create_ray(
			multiply_matrix_tuple(m, r.origin),
			multiply_matrix_tuple(m, r.direction))
	);
}
