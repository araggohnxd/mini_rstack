/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:08:48 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 14:22:12 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_point	get_position(t_ray r, double t)
{
	return (sum_tuple(r.origin, smul_tuple(r.direction, t)));
}

t_intersect	*get_hit(t_intersect *xs)
{
	while (xs)
	{
		if (xs->t >= EPSILON)
			return (xs);
		xs = xs->next;
	}
	return (NULL);
}

t_color	shade_hit(t_world world, t_comps comps, t_list *lights)
{
	t_lgt_attr	light_attr;
	t_pos_attr	pos_attr;
	t_color		color;

	color = create_color(0, 0, 0);
	pos_attr = create_pos_attr(comps.camera, comps.normal, comps.overpoint);
	while (lights)
	{
		light_attr = create_light_attr(
				*(t_lgt_point *)lights->content,
				pos_attr,
				comps.shape->material);
		light_attr.in_shadow = is_shadowed(
				world, comps.overpoint, *(t_lgt_point *)lights->content);
		light_attr.shape = comps.shape;
		color = sum_color(color, lighting(light_attr));
		lights = lights->next;
	}
	return (color);
}

t_color	color_at(t_world world, t_ray ray)
{
	t_intersect	*xs;
	t_intersect	*hit;
	t_comps		comps;
	t_color		color;

	xs = NULL;
	intersect_world(world, ray, &xs);
	hit = get_hit(xs);
	if (!hit)
	{
		intersection_list_clear(&xs);
		return (create_color(0, 0, 0));
	}
	comps = prepare_computation(hit, ray);
	color = shade_hit(world, comps, world.lights);
	intersection_list_clear(&xs);
	return (color);
}
