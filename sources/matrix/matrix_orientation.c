/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_orientation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:34:41 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/08 17:37:07 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

/* It is MANDATORY to multiply Z by X, not X by Z. */

t_matrix	full_rotation_matrix(t_vector vector)
{
	double	x;
	double	z;
	double	ratio;

	ratio = sqrt((vector.x * vector.x) + (vector.y * vector.y));
	if (is_equal_double(0, ratio))
		z = M_PI_2;
	else
		z = acos(vector.y / ratio);
	x = acos(ratio);
	return (mul_matrix(rotate_matrix_z(z), rotate_matrix_x(x)));
}
