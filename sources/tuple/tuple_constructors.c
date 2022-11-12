/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_constructors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:40:20 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 14:22:12 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	create_tuple(double x, double y, double z, double w)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	return (tuple);
}

t_point	create_point(double x, double y, double z)
{
	return (create_tuple(x, y, z, POINT_W));
}

t_vector	create_vector(double x, double y, double z)
{
	return (create_tuple(x, y, z, VECTOR_W));
}
