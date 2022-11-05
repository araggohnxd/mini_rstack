/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:04:53 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 16:06:01 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

void	set_shape_transformation(t_shape *s, t_matrix transformation)
{
	s->transformation = transformation;
	s->inverse_transformation = inverse_matrix(transformation);
}
