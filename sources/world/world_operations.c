/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:50:53 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 14:22:12 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vector	normal_at(t_shape *s, t_point p)
{
	t_vector	w_normal;
	t_vector	s_normal;
	t_point		s_point;

	s_point = mul_matrix_tuple(s->inverse_transform, p);
	s_normal = s->normal_at(s, s_point);
	w_normal = mul_matrix_tuple(s->inverse_transpose_transform, s_normal);
	w_normal.w = VECTOR_W;
	w_normal = normalize(w_normal);
	return (w_normal);
}

t_comps	prepare_computation(t_intersect *i, t_ray ray)
{
	t_comps	comps;

	comps.t = i->t;
	comps.shape = i->s;
	comps.point = get_position(ray, comps.t);
	comps.camera = neg_tuple(ray.direction);
	comps.normal = normal_at(comps.shape, comps.point);
	if (dotp(comps.normal, comps.camera) < 0)
		comps.normal = neg_tuple(comps.normal);
	comps.overpoint = sum_tuple(comps.point, smul_tuple(comps.normal, EPSILON));
	return (comps);
}

void	intersect_world(t_world world, t_ray ray, t_intersect **head)
{
	t_shape	*current_shape;
	t_list	*shapes;
	t_ray	transform;

	shapes = world.shapes;
	while (shapes)
	{
		current_shape = (t_shape *)shapes->content;
		transform = transform_ray(ray, current_shape->inverse_transform);
		current_shape->intersect(current_shape, transform, head);
		shapes = shapes->next;
	}
}
