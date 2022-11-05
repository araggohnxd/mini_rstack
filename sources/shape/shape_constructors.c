/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_constructors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:13:34 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 15:18:39 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

t_shape	create_shape(void)
{
	t_shape	shape;

	shape.transformation = create_identity_matrix();
	shape.inverse_transformation = create_identity_matrix();
	return (shape);
}

t_shape	create_sphere(void)
{
	t_shape	sphere;

	sphere = create_shape();
	sphere.type = ID_SPHERE;
	sphere.sphere.diameter = 1.;
	sphere.sphere.center = create_point(0, 0, 0);
	return (sphere);
}
