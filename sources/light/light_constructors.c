/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_constructors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:19:15 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/07 02:30:54 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

t_material	create_material(void)
{
	t_material	material;

	material.color = create_color(1, 1, 1);
	material.ambient = create_color(.1, .1, .1);
	material.diffuse = .9;
	material.specular = .9;
	material.shininess = 200;
	material.has_pattern = FALSE;
	return (material);
}

t_pos_attr	create_pos_attr(t_vector camera, t_vector normal, t_point pos)
{
	t_pos_attr	attributes;

	attributes.camera = camera;
	attributes.normal = normal;
	attributes.position = pos;
	return (attributes);
}

t_lgt_point	*create_light_point(t_point position, t_color intensity)
{
	t_lgt_point	*light_point;

	light_point = malloc(sizeof(t_lgt_point));
	if (!light_point)
		return (NULL);
	light_point->position = position;
	light_point->intensity = intensity;
	return (light_point);
}

t_lgt_attr	create_light_attr(t_lgt_point lp, t_pos_attr pos, t_material m)
{
	t_lgt_attr	attributes;

	attributes.lp = lp;
	attributes.camera = pos.camera;
	attributes.normal = pos.normal;
	attributes.position = pos.position;
	attributes.material = m;
	attributes.in_shadow = FALSE;
	return (attributes);
}
