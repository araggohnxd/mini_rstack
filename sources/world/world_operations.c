/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:50:53 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 22:39:39 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

t_vector	normal_at(t_shape *s, t_point p)
{
	t_vector	world_normal;
	t_vector	object_normal;
	t_point		object_point;

	object_point = multiply_matrix_tuple(s->inverse_transformation, p);
	object_normal = s->get_normal(s, object_point);
	world_normal = multiply_matrix_tuple(s->transposed_inverse, object_normal);
	world_normal.w = VECTOR_W;
	world_normal = normalize(world_normal);
	return (world_normal);
}

t_comps	prepare_computation(t_intersect *i, t_ray ray)
{
	t_comps	comps;

	comps.t = i->t;
	comps.shape = i->s;
	comps.point = get_position(ray, comps.t);
	comps.camera = neg_tuple(ray.direction);
	comps.normal = normal_at(comps.shape, comps.point);
	if (dot_product(comps.normal, comps.camera) < 0)
		comps.normal = neg_tuple(comps.normal);
	comps.overpoint = sum_tuple(
			comps.point,
			scalar_multiply_tuple(comps.normal, EPSILON));
	return (comps);
}

void	intersect_world(t_world world, t_ray ray, t_intersect **head)
{
	t_shape	*current_shape;
	t_list	*shapes;
	t_ray	transformed;

	shapes = world.shapes;
	while (shapes)
	{
		current_shape = (t_shape *)shapes->content;
		transformed = transform_ray(ray, current_shape->inverse_transformation);
		current_shape->intersect(current_shape, transformed, head);
		shapes = shapes->next;
	}
}
