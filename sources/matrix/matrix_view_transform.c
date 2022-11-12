/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_view_transform.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:51:25 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 14:22:12 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_matrix	create_orientation(t_vector left, t_vector up, t_vector forward)
{
	const double	orientation[MAT_MAX][MAT_MAX] = {
	{left.x, left.y, left.z, 0},
	{up.x, up.y, up.z, 0},
	{-forward.x, -forward.y, -forward.z, 0},
	{0, 0, 0, 1}
	};

	return (create_matrix(MAT_MAX, orientation));
}

static t_matrix	create_transformation(
		t_vector left, t_vector up, t_vector forward, t_point from)
{
	t_matrix	orientation;
	t_matrix	view_transform;
	t_matrix	translated;

	orientation = create_orientation(left, up, forward);
	translated = translate_matrix(-from.x, -from.y, -from.z);
	view_transform = mul_matrix(orientation, translated);
	return (view_transform);
}

t_matrix	view_transform(t_point from, t_point to, t_vector up)
{
	t_vector	left;
	t_vector	normalized_up;
	t_vector	true_up;

	normalized_up = normalize(up);
	left = crossp(to, normalized_up);
	true_up = crossp(left, to);
	return (create_transformation(left, true_up, to, from));
}
