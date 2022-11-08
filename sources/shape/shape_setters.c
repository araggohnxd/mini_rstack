/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:04:53 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/08 18:07:49 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

void	set_shape_transformation(t_shape *s, t_matrix transform)
{
	s->transform = transform;
	s->inverse_transform = inverse_matrix(transform);
	s->inverse_transpose_transform = transpose_matrix(s->inverse_transform);
}
