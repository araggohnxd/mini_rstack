/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_constructors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:13:34 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/06 17:17:03 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

t_shape	*create_shape(void)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	if (!shape)
		return (NULL);
	shape->material = create_material();
	shape->transformation = create_identity_matrix();
	shape->inverse_transformation = create_identity_matrix();
	shape->transposed_inverse = create_identity_matrix();
	return (shape);
}

t_shape	*create_sphere(void)
{
	t_shape	*sphere;

	sphere = create_shape();
	if (!sphere)
		return (NULL);
	sphere->type = ID_SPHERE;
	sphere->sphere.diameter = 1;
	sphere->sphere.center = create_point(0, 0, 0);
	sphere->material = create_material();
	sphere->get_normal = get_sphere_normal;
	sphere->intersect = intersect_sphere;
	return (sphere);
}

t_shape	*create_plane(void)
{
	t_shape	*plane;

	plane = create_shape();
	if (!plane)
		return (NULL);
	plane->type = ID_PLANE;
	plane->material.specular = .05;
	plane->plane.position = create_vector(0, 1, 0);
	plane->intersect = intersect_plane;
	plane->get_normal = get_plane_normal;
	return (plane);
}

t_shape	*create_cylinder(void)
{
	t_shape	*cylinder;

	cylinder = create_shape();
	if (!cylinder)
		return (NULL);
	cylinder->type = ID_CYLINDER;
	cylinder->cylinder.diameter = 1;
	cylinder->cylinder.min = -INFINITY;
	cylinder->cylinder.max = INFINITY;
	cylinder->cylinder.capped = TRUE;
	cylinder->intersect = intersect_cylinder;
	cylinder->get_normal = get_cylinder_normal;
	return (cylinder);
}

t_shape	*create_cone(void)
{
	t_shape	*cone;

	cone = create_shape();
	if (!cone)
		return (NULL);
	cone->type = ID_CONE;
	cone->cone.diameter = 1;
	cone->cone.min = -INFINITY;
	cone->cone.max = INFINITY;
	cone->cone.capped = TRUE;
	cone->intersect = intersect_cone;
	cone->get_normal = get_cone_normal;
	return (cone);
}
