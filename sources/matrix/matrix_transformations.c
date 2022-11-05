/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:59:29 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 14:07:32 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

t_matrix	translate_matrix(double x, double y, double z)
{
	const double	translate[MAT_MAX][MAT_MAX] = {
	{1, 0, 0, x},
	{0, 1, 0, y},
	{0, 0, 1, z},
	{0, 0, 0, 1}
	};

	return (create_matrix(MAT_MAX, translate));
}

t_matrix	scale_matrix(double x, double y, double z)
{
	const double	scale[MAT_MAX][MAT_MAX] = {
	{x, 0, 0, 0},
	{0, y, 0, 0},
	{0, 0, z, 0},
	{0, 0, 0, 1}
	};

	return (create_matrix(MAT_MAX, scale));
}

t_matrix	rotate_matrix_x(double r)
{
	const double	c = cos(r);
	const double	s = sin(r);
	const double	rotx[MAT_MAX][MAT_MAX] = {
	{1, 0, 0, 0},
	{0, c, -s, 0},
	{0, s, c, 0},
	{0, 0, 0, 1}
	};

	return (create_matrix(MAT_MAX, rotx));
}

t_matrix	rotate_matrix_y(double r)
{
	const double	c = cos(r);
	const double	s = sin(r);
	const double	roty[MAT_MAX][MAT_MAX] = {
	{c, 0, s, 0},
	{0, 1, 0, 0},
	{-s, 0, c, 0},
	{0, 0, 0, 1}
	};

	return (create_matrix(MAT_MAX, roty));
}

t_matrix	rotate_matrix_z(double r)
{
	const double	c = cos(r);
	const double	s = sin(r);
	const double	rotz[MAT_MAX][MAT_MAX] = {
	{c, -s, 0, 0},
	{s, c, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}
	};

	return (create_matrix(MAT_MAX, rotz));
}
