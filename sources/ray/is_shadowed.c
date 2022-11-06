/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadowed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:41:08 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 18:41:54 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

t_bool	_is_shadowed(t_world world, t_ray ray, double distance)
{
	t_intersect	*xs;
	t_intersect	*hit;
	t_bool		in_shadow;

	xs = NULL;
	intersect_world(world, ray, &xs);
	hit = get_hit(xs);
	in_shadow = (hit && hit->t < distance);
	intersection_list_clear(&xs);
	return (in_shadow);
}

t_bool	is_shadowed(t_world world, t_point point, t_lgt_point lp)
{
	t_tuple		aux;
	t_ray		ray;
	t_vector	direction;
	double		distance;

	aux = sub_tuple(lp.position, point);
	distance = magnitude(aux);
	direction = normalize(aux);
	ray = create_ray(point, direction);
	return (_is_shadowed(world, ray, distance));
}
