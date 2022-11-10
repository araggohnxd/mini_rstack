/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_constructors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:13:34 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/10 10:14:51 by maolivei         ###   ########.fr       */
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
	shape->transform = create_identity_matrix();
	shape->inverse_transform = create_identity_matrix();
	shape->inverse_transpose_transform = create_identity_matrix();
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
	sphere->normal_at = normal_at_sphere;
	sphere->intersect = intersect_sphere;
	sphere->uvmap = map_sphere;
	sphere->material.pattern.width = 16;
	sphere->material.pattern.height = 8;
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
	plane->normal_at = normal_at_plane;
	plane->uvmap = map_plane;
	plane->material.pattern.width = 4;
	plane->material.pattern.height = 4;
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
	cylinder->normal_at = normal_at_cylinder;
	cylinder->uvmap = map_cylinder;
	cylinder->material.pattern.width = 16;
	cylinder->material.pattern.height = 8;
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
	cone->normal_at = normal_at_cone;
	cone->uvmap = map_cone;
	cone->material.pattern.width = 16;
	cone->material.pattern.height = 8;
	return (cone);
}
